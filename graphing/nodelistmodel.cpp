#include "nodelistmodel.h"

nodeListModel::nodeListModel(QObject *parent) : QAbstractListModel(parent)
{
    nodeList.reserve(10);
}

nodeListModel::~nodeListModel()
{

}

QHash<int, QByteArray> nodeListModel::roleNames() const{
    QHash<int, QByteArray> roles;
    roles[xc] = "PosX";
    roles[yc] = "PosY";
    roles[rx] = "RelativePosX";
    roles[ry] = "RelativePosY";
    roles[nIndex] = "node_id";

    return roles;
}

int nodeListModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return nodeList.size();
}

void nodeListModel::checkNodeCollision(int index){
    auto item = nodeList[index];

    for (auto node : nodeList){
        if (node == item) continue;
        if (qSqrt(qPow(node->xc-item->xc,2)+qPow(node->yc-item->yc,2)) < Selector_Radius) {
            emit mergeNodes(item, node);
            break;
        }
    }
}

QVariant nodeListModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid()){
        return QVariant();
    }

    auto &item = nodeList[index.row()];

    switch (role) {
    case xc:
        return QVariant(item->xc);
    case yc:
        return QVariant(item->yc);
    case rx:
        return QVariant(item->rx);
    case ry:
        return QVariant(item->ry);
    case nIndex:
        item->index = index.row();
        return QVariant(item->index);
    default:
        return QVariant();
    }
}

void nodeListModel::addNode(int x, int y){
    int i = nodeList.size();
    beginInsertRows(QModelIndex(),i,i);
    emit addItem();

    auto *item = new Node();
    item->xc = x;
    item->yc = y;
    item->rx = 0;
    item->ry = 0;
    item->index = i;
    nodeList.append(item);

    endInsertRows();
}

void nodeListModel::removeNode(int i, bool relations){
    beginRemoveRows(QModelIndex(), i,i);
    if (relations) emit removeBindings(i);
    delete nodeList.takeAt(i);
    endRemoveRows();

    emit removeItem(i);
    emit dataChanged(index(i),index(nodeList.size()-1),{nIndex});
}

Node* nodeListModel::getNode(int index, bool checkExisted){
    if (!checkExisted) return nodeList[index];

    auto item = nodeList[index];

    for (auto node : nodeList){
        if (node != item && qSqrt(qPow(node->xc-item->xc-item->rx,2)+qPow(node->yc-item->yc-item->ry,2)) < Selector_Radius) {
            return node;
        }
    }

    addNode(item->xc+item->rx,item->yc+item->ry);
    return nodeList.last();
}

bool nodeListModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if (!index.isValid()) return false;

    auto item = nodeList[index.row()];

    switch (role) {
    case xc:
        item->xc = value.toInt();
        break;
    case yc:
        item->yc = value.toInt();
        break;
    case rx:
        item->rx = value.toInt();
        break;
    case ry:
        item->ry = value.toInt();
        break;
    default:
        return false;
    }

    emit dataChanged(index,index);

    return true;
}

void nodeListModel::update(int i, int value, int role){
    setData(index(i), value, role);

    emit updateBindings(i);
}

void nodeListModel::showNodeList(){
    qDebug() << "---Nodes---";

    for (auto node : nodeList){
        qDebug() << node << "|" << node->index << ":    (" << node->xc << node->yc << ")" << "(" << node->rx << node->ry << ")";
    }

    qDebug() << "-----------";
}

