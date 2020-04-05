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

void arrowListModel::bindA(int nodeIndex){
    auto *p_node = getNode(nodeIndex);
    //if (map.contains(p_node)) return;

    auto index = arrowList.size();
    beginInsertRows(QModelIndex(),index,index);

    Arrow item;
    item.A = p_node;
    item.B = p_node;
    item.bidirectional = false;
    arrowList.append(item);

    map[item.A].insert(index);

    endInsertRows();
}

void arrowListModel::bindB(int nodeIndex){
    auto *p_node = getNode(nodeIndex);
    arrowList.last().B = p_node;

    map[p_node].insert(arrowList.size()-1);
}

void arrowListModel::remove(int A, int B){
    auto *pA = getNode(A);
    auto list_it = map.find(pA);
    if (list_it != map.end()) return;
    auto *pB = getNode(B);

    int index = -1;

    for (auto &arrowID : *list_it){
        if (arrowList[arrowID].A == pA && arrowList[arrowID].B == pB){
            index = arrowID;
            break;
        }
    }

    beginRemoveRows(QModelIndex(),index,index);
    arrowList.remove(index);
    (*list_it).remove(index);
    endRemoveRows();
}
