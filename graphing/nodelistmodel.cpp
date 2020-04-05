#include "nodelistmodel.h"

nodeListModel::nodeListModel(QObject *parent) : QAbstractListModel(parent)
{

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
    roles[Index] = "node_id";

    return roles;
}

int nodeListModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return nodeList.size();
}

QVariant nodeListModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid()){
        return QVariant();
    }

    auto &item = nodeList[index.row()];

    switch (role) {
    case xc:
        return QVariant(item.xc);
    case yc:
        return QVariant(item.yc);
    case rx:
        return QVariant(item.rx);
    case ry:
        return QVariant(item.ry);
    case Index:
        return QVariant(index.row());
    default:
        return QVariant();
    }
}

void nodeListModel::addNode(int x, int y){
    int i = nodeList.size();
    beginInsertRows(QModelIndex(),i,i);

    Node item;
    item.xc = x;
    item.yc = y;
    item.rx = 0;
    item.ry = 0;
    item.index = i;
    nodeList.append(item);

    endInsertRows();

    emit addItem();
}

void nodeListModel::removeNode(int i){
    emit removeItem(i);

    beginRemoveRows(QModelIndex(), i,i);
    nodeList.remove(i);
    endRemoveRows();

    //change indexes for rest nodes
    for (auto j = i; j < nodeList.size(); j++) {
        update(j, i++, nRoles::Index);
    }
}

Node* nodeListModel::getNode(int index){
    return &nodeList[index];
}

bool nodeListModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if (!index.isValid()) return false;

    auto &item = nodeList[index.row()];

    switch (role) {
    case xc:
        item.xc = value.toInt();
        break;
    case yc:
        item.yc = value.toInt();
        break;
    case rx:
        item.rx = value.toInt();
        break;
    case ry:
        item.ry = value.toInt();
        break;
    case Index:
        item.index = value.toInt();
        break;
    default:
        return false;
    }

    emit dataChanged(index,index);

    return true;
}

void nodeListModel::update(int i, int value, int role){
    setData(index(i), value, role);

    emit updated(&nodeList[i]);
}

void nodeListModel::showNodeList(){
    qDebug() << "---Nodes---";

    for (auto &node : nodeList){
        qDebug() << node.index << ":    (" << node.xc << node.yc << ")" << "(" << node.rx << node.ry << ")";
    }

    qDebug() << "-----------";
}

