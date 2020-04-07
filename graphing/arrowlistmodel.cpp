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
    case alpha: {
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

            remove(currentArrow);

            int id = getArrowID(p_node->index, currentArrow->A->index);     // получаем существующее ребро
            auto i = index(id);
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
            remove(currentArrow);
        }
    }
}

int arrowListModel::getArrowID(int A, int B){
    return arrowList.indexOf(emit getArrow(A,B));
}

void arrowListModel::cutArrow(Arrow *arrow){
    auto list = map.find(arrow->A);
    list->remove(arrow);
    if (list->isEmpty()) map.remove(arrow->A);

    list = map.find(arrow->B);
    list->remove(arrow);
    if (list->isEmpty()) map.remove(arrow->B);
}

void arrowListModel::remove(Arrow* arrow){
    qDebug() << "removing"<< arrow->A->index << arrow->B->index;
    cutArrow(arrow);

    auto i = index(arrowList.indexOf(arrow));
    emit dataChanged(i,i,{aRoles::detonate});
    del_list.push_front(arrow);
}

void arrowListModel::removeCurrent(){
    auto currentArrow = arrowList.last();
    qDebug() << "removing"<< currentArrow->A->index << currentArrow->B->index;

    auto list = map.find(currentArrow->A);
    list->remove(currentArrow);
    if (list->isEmpty()) map.remove(currentArrow->A);

    auto i = index(arrowList.size()-1);
    emit dataChanged(i,i,{aRoles::detonate});
    del_list.push_front(currentArrow);
}

void arrowListModel::removeBindings(Node* node){
    auto list = map.find(node);
    if (list != map.end()){
        QModelIndex i;
        for (auto arrow : *list) {
            i = index(arrowList.indexOf(arrow));
            emit dataChanged(i,i,{aRoles::detonate});
            del_list.push_front(arrow);
        }
    }
}

void arrowListModel::kill(){
    if (!del_list.isEmpty()){
        auto arrow = del_list.takeLast();
        cutArrow(arrow);
        qDebug() << "kill"<< arrow->A->index << arrow->B->index;
        auto index = arrowList.indexOf(arrow);
        beginRemoveRows(QModelIndex(),index,index);
        arrowList.remove(index);
        endRemoveRows();
    }
}

void arrowListModel::showMap(){
    QTextStream Qcout(stdout);

    Qcout << "\n---MAP---\n";

    auto nodes = map.keys();

    for (auto &node : nodes){
        Qcout << node->index << " :";
        for (auto &arrow : map[node]){
            Qcout << "  " << arrowList.indexOf(arrow);
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
