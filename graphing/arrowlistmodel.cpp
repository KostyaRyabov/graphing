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

    auto &item = arrowList[index.row()];

    switch (role) {
    case xxx:
        return QVariant((item.B->xc+item.B->rx+item.A->xc)/2);
    case yyy:
        return QVariant((item.B->yc+item.B->ry+item.A->yc)/2);
    case alpha:
    {
        int v_x = item.B->xc+item.B->rx-item.A->xc;
        int v_y = item.B->yc+item.B->ry-item.A->yc;

        float a = qRadiansToDegrees(qAcos(v_y/(qSqrt(qPow(v_x,2)+qPow(v_y,2)))));

        if (v_x > 0) return QVariant(360 - a);
        else return QVariant(a);
    }
    case len:
        return QVariant(qSqrt(qPow(item.B->xc+item.B->rx-item.A->xc,2)+qPow(item.B->yc+item.B->ry-item.A->yc,2)));
    case bDir:
        return QVariant(item.bidirectional);
    default:
        return QVariant();
    }
}

void arrowListModel::updated(Node *node){
    if (arrowList.isEmpty()) return;

    auto it = map.find(node);
    if (it == map.end()) return;
    auto &list = *it;

    for(auto &ix : list) {
        auto i = index(ix);
        emit dataChanged(i,i);
    }
}

void arrowListModel::bind(int nodeIndex){
    auto *p_node = getNode(nodeIndex);
    if (map.find(p_node) != map.end()) return;

    auto index = arrowList.size();
    beginInsertRows(QModelIndex(),index,index);

    Arrow item;
    item.A = p_node;
    item.B = p_node;
    item.bidirectional = false;
    arrowList.append(item);

    map[item.A].insert(index);
    //map[item.B].insert(index);

    endInsertRows();
}
