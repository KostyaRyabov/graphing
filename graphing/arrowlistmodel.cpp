#include "arrowlistmodel.h"

arrowListModel::arrowListModel(QObject *parent) : QAbstractListModel(parent)
{

}

arrowListModel::~arrowListModel()
{

}

QHash<int, QByteArray> arrowListModel::roleNames() const{
    QHash<int, QByteArray> roles;
    roles[xxx] = "PosX";
    roles[yyy] = "PosY";
    roles[len] = "Length";
    roles[alpha] = "Angle";
    roles[bDir] = "bDirection";
    roles[detonate] = "Delete";
    return roles;
}

int arrowListModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return arrowList.size();
}

QVariant arrowListModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid()){
        return QVariant();
    }

    auto item = arrowList[index.row()];

    switch (role) {
    case xxx:
        if (item->A == item->B) return QVariant(item->B->xc+item->B->rx/2);         // new arrow
        else return QVariant((item->B->xc+item->A->xc)/2);
    case yyy:
        if (item->A == item->B) return QVariant(item->B->yc+item->B->ry/2);         // new arrow
        else return QVariant((item->B->yc+item->A->yc)/2);
    case alpha:
    {
        int v_x,v_y;

        if (item->A == item->B){
            v_x = item->B->rx;
            v_y = item->B->ry;
        }else{
            v_x = item->B->xc-item->A->xc;
            v_y = item->B->yc-item->A->yc;
        }

        float a = qRadiansToDegrees(qAcos(v_y/(qSqrt(qPow(v_x,2)+qPow(v_y,2)))));

        if (v_x > 0) return QVariant(360 - a);
        else return QVariant(a);
    }
    case len:
        if (item->A == item->B) return QVariant(qSqrt(qPow(item->B->rx,2)+qPow(item->B->ry,2)));
        else return QVariant(qSqrt(qPow(item->B->xc-item->A->xc,2)+qPow(item->B->yc-item->A->yc,2)));
    case bDir:
        return QVariant(item->bidirectional);
    case detonate:
        item->destroy = !item->destroy;
        qDebug() << "                       item->destroy:" << item->destroy;
        return QVariant(item->destroy);
    default:
        return QVariant();
    }
}

void arrowListModel::updated(Node *node){           // обновление ребер, связанных с передаваемой точкой в качестве аргумента
    if (arrowList.isEmpty()) return;                // проверка наличия ребер

    auto list = map.find(node);                     // получаем список ребер из матрицы
    if (list == map.end()) return;                  // проверяем наличие

    for(auto ix : *list) {
        auto i = index(arrowList.indexOf(ix));                         // получаем индекс ребра и
        emit dataChanged(i,i,{xxx,yyy,len,alpha});                      // обновляем его содержимое
    }
}

void arrowListModel::bindA(int nodeIndex){              // привязка первого узла к ребру
    auto *p_node = emit getNode(nodeIndex,false);             // получаем узел по его идентификатору

    auto index = arrowList.size();
    beginInsertRows(QModelIndex(),index,index);         // создаем новое ребро

    Arrow* item = new Arrow();                                         // процесс инициализации ребра
    item->A = p_node;
    item->B = p_node;
    item->bidirectional = false;
    arrowList.append(item);                             // занесение в список
    map[item->A].insert(item);                          // занесение ребра в матрицу инцидентности

    endInsertRows();
}

void arrowListModel::bindB(int nodeIndex){              // привязка второго узла к ребру
    auto *p_node = emit getNode(nodeIndex,true);        // получаем узел по его идентификатору
    auto currentArrow = arrowList.last();

    switch (emit checkExisting(currentArrow->A->index,p_node->index)) {
        case aDir::OutSimplex: {    // >> duplex
            qDebug() << "(в другом направлении)";
            emit updateMatrix(currentArrow->A->index,p_node->index,getArrow(p_node->index,currentArrow->A->index));     // устанавливается в матрице другое направление

            auto i = index(arrowList.indexOf(currentArrow));
            emit dataChanged(i,i,{aRoles::detonate});

            int id = getArrowID(p_node->index, currentArrow->A->index);     // получаем существующее ребро
            i = index(id);
            arrowList[id]->bidirectional = true;
            emit dataChanged(i,i,{aRoles::bDir});
            break;
        } case aDir::NotFound: {
            qDebug() << "(не найдено)";
            emit updateMatrix(currentArrow->A->index, p_node->index,currentArrow);      // обновляется матрица
            currentArrow->B = p_node;
            map[currentArrow->B].insert(currentArrow);                                  // добавляется карта
            auto i = index(arrowList.size()-1);
            emit dataChanged(i,i,{xxx,yyy,len,alpha});
            break;
        } case aDir::InSimplex:{
            qDebug() << "(повторяющее)";
            remove(p_node, currentArrow->A);
        }
    }
}

void arrowListModel::removeArrowsWidth(QVector<Node*> list){
    /*
    for (auto &p_node : list){
        auto list_it = map.find(p_node);
        auto *pB = getNode(B, false);

        int index = -1;

        for (auto &arrowID : *list_it){
            if (arrowList[arrowID].A == pA && arrowList[arrowID].B == pB){
                index = arrowID;
                break;
            }
        }

        if (index != -1){
            qDebug() << "               remove arrow:"<<index;

            beginRemoveRows(QModelIndex(),index,index);
            arrowList.remove(index);
            (*list_it).remove(index);
            if (list_it->isEmpty()) map.remove(pA);
            endRemoveRows();
        }

    }
    */
}

int arrowListModel::getArrowID(int A, int B){
    return arrowList.indexOf(emit getArrow(A,B));
}

void arrowListModel::remove(int A, int B){
    qDebug() << "                   remove1";
    auto *pA = getNode(A, false);
    auto list_it = map.find(pA);
    if (list_it == map.end()) return;
    auto *pB = getNode(B, false);

    for (auto arrow : *list_it){
        if (arrow->B == pB){
            qDebug()<<"             arrow was found";
            auto index = arrowList.indexOf(arrow);
            beginRemoveRows(QModelIndex(),index,index);
            arrowList.remove(index);
            (*list_it).remove(arrow);
            if (list_it->isEmpty()) map.remove(pA);
            endRemoveRows();
            return;
        }
        else qDebug()<<"             arrow was not found";
    }
}

void arrowListModel::remove(Node* pA, Node* pB){
    qDebug() << "                   remove2";
    auto list_it = map.find(pA);
    if (list_it == map.end()) return;

    for (auto arrow : *list_it){
        if (arrow->B == pB){
            qDebug()<<"             arrow was found";

            auto index = arrowList.indexOf(arrow);
            beginRemoveRows(QModelIndex(),index,index);
            arrowList.remove(index);
            (*list_it).remove(arrow);
            if (list_it->isEmpty()) map.remove(pA);
            endRemoveRows();
            return;
        }else qDebug()<<"             arrow was not found";
    }
}

void arrowListModel::showMap(){
    QTextStream Qcout(stdout);

    Qcout << "\n---MAP---\n";

    auto nodes = map.keys();

    for (auto &node : nodes){
        Qcout << node->index << " :";
        for (auto &arrow : map[node]){
            Qcout << "  " << arrow;
        }
        Qcout << "\n";
    }

    Qcout << "\n---------\n";
}

void arrowListModel::showArrowList(){
    qDebug() << "---Arrows---";

    for (auto &arrow : arrowList){
        qDebug() << arrow->A->index << arrow->B->index << arrow->bidirectional;
    }

    qDebug() << "------------";
}
