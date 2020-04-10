#include "arrowlistmodel.h"

arrowListModel::arrowListModel(QObject *parent) : QAbstractListModel(parent)
{
    del_list.reserve(10);
    arrowList.reserve(10);
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
        if (item->isLooped) return QVariant(item->A->xc+0.95*Node_Radius);
        if (item->A == item->B) return QVariant(item->B->xc+item->B->rx/2);         // new arrow
        else return QVariant((item->B->xc+item->A->xc)/2);
    case yyy:
        if (item->isLooped) return QVariant(item->A->yc+1.5*Node_Radius);
        if (item->A == item->B) return QVariant(item->B->yc+item->B->ry/2);         // new arrow
        else return QVariant((item->B->yc+item->A->yc)/2);
    case alpha: {
        if (item->isLooped) return 0;

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
        if (item->isLooped) return QVariant(-1);
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

    auto aList = getArrowListWithNode(node->index);
    if (adding) aList.append(arrowList.last());

    for(auto ix : aList) {
        auto i = index(arrowList.indexOf(ix));                         // получаем индекс ребра и
        emit dataChanged(i,i,{xxx,yyy,len,alpha});                      // обновляем его содержимое
    }
}

void arrowListModel::createLoop(int nodeIndex){
    qDebug() << "create loop";

    auto *p_node = emit getNode(nodeIndex,false);

    auto index = arrowList.size();
    beginInsertRows(QModelIndex(),index,index);         // создаем новое ребро

    Arrow* item = new Arrow();                                         // процесс инициализации ребра
    item->A = p_node;
    item->B = p_node;
    item->isLooped = true;
    item->bidirectional = false;
    arrowList.append(item);                            // занесение ребра в матрицу инцидентности

    emit updateMatrix(nodeIndex,nodeIndex,item);

    endInsertRows();
}

void arrowListModel::bindA(int nodeIndex){              // привязка первого узла к ребру
    auto *p_node = emit getNode(nodeIndex,false);             // получаем узел по его идентификатору

    auto index = arrowList.size();
    beginInsertRows(QModelIndex(),index,index);         // создаем новое ребро

    Arrow* item = new Arrow();                                         // процесс инициализации ребра
    item->A = p_node;
    item->B = p_node;
    item->isLooped = false;
    item->bidirectional = false;
    arrowList.append(item);                            // занесение ребра в матрицу инцидентности

    adding = true;

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

            int id = arrowList.indexOf(getArrow(p_node->index, currentArrow->A->index));     // получаем существующее ребро
            auto i = index(id);
            arrowList[id]->bidirectional = true;
            emit dataChanged(i,i,{aRoles::bDir});
            break;
        } case aDir::NotFound: {
            qDebug() << "(не найдено)";
            emit updateMatrix(currentArrow->A->index, p_node->index,currentArrow);      // обновляется матрица
            currentArrow->B = p_node;                                 // добавляется карта
            auto i = index(arrowList.size()-1);
            emit dataChanged(i,i,{xxx,yyy,len,alpha});
            break;
        } case aDir::InSimplex:{
            qDebug() << "(повторяющее)";
            remove(currentArrow);
        }
    }

    adding = false;
}

void arrowListModel::remove(Arrow* arrow){
    qDebug() << "removing"<< arrow->A->index << arrow->B->index;

    auto i = index(arrowList.indexOf(arrow));
    emit dataChanged(i,i,{aRoles::detonate});
    del_list.push_front(arrow);
}

void arrowListModel::removeCurrent(){
    auto currentArrow = arrowList.last();
    qDebug() << "removing"<< currentArrow->A->index << currentArrow->B->index;

    auto i = index(arrowList.size()-1);
    emit dataChanged(i,i,{aRoles::detonate});
    del_list.push_front(currentArrow);
}

void arrowListModel::removeBindings(Node* node){
    auto aList = getArrowListWithNode(node->index);

    qDebug() << "del List:" << aList.size();

    QModelIndex i;
    for (auto &arrow : aList) {
        qDebug() << arrow->A->index << arrow->B->index;
        i = index(arrowList.indexOf(arrow));
        emit dataChanged(i,i,{aRoles::detonate});
        del_list.push_front(arrow);
    }
}

void arrowListModel::kill(){
    if (!del_list.isEmpty()){
        auto arrow = del_list.takeLast();
        qDebug() << "kill"<< arrow->A->index << arrow->B->index;
        auto index = arrowList.indexOf(arrow);
        beginRemoveRows(QModelIndex(),index,index);
        arrowList.remove(index);
        endRemoveRows();
    }
}
