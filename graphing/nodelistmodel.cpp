#include "nodelistmodel.h"

nodeListModel::nodeListModel(QObject *parent) : QAbstractListModel(parent)
{
    nodeList.reserve(reservedItemsCount);
    selected.reserve(reservedItemsCount);
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
    roles[isSelected] = "selected";
    roles[nDetonate] = "Delete";

    return roles;
}

int nodeListModel::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return nodeList.size();
}

void nodeListModel::selectNodesOnRect(int left, int top, int right, int bottom, int offsetX, int offsetY, float scale){
    for (auto &item : selected) setData(index(item->index),false,nRoles::isSelected);
    selected.clear();

    if (left > right) {
        int tmp = left;
        left = right;
        right = tmp;
    }

    if (top > bottom) {
        int tmp = top;
        top = bottom;
        bottom = tmp;
    }

    left = (left < offsetX)?0:left-offsetX;
    top = (top < offsetY)?0:top-offsetY;

    right-=offsetX;
    bottom-=offsetY;

    left/=scale;
    right/=scale;
    top/=scale;
    bottom/=scale;

    if (right > ws_Width) right = ws_Width;
    if (bottom > ws_Height) bottom = ws_Height;

    int X,Y, newX, newY;

    for (X = left; X < right; X = newX){
        newX = (X/block_RangeX+1)*block_RangeX;
        if (newX > right) newX = right;

        for (Y = top; Y < bottom; Y = newY){
            newY = (Y/block_RangeY+1)*block_RangeY;
            if (newY > bottom) newY = bottom;

            if ((newX - X >= block_RangeX) && (newY - Y >= block_RangeY)){
                selected.append(map[(Y/block_RangeY)*block_count+(X/block_RangeX)]);
            }else{
                for (auto node : map[(Y/block_RangeY)*block_count+(X/block_RangeX)]){
                    if ((X <= node->xc && node->xc <= newX) && (Y <= node->yc && node->yc <= newY)) {
                        selected.append(node);
                    }
                }
            }
        }
    }

    for (auto &item : selected) setData(index(item->index),true,nRoles::isSelected);
}

void nodeListModel::checkNodeCollision(){
    updateNodesPosition();

    for (auto &node : selected){
        auto collision = getCollision(node->index);
        if (collision != nullptr) emit mergeNodes(node, collision);
    }
}

void nodeListModel::updateNodesPosition(){
    short block;
    Node* item;

    QVector<Node*>::iterator it = selected.begin();

    while (it != selected.end()){
        item = *it;

        if (item->xc < Node_Radius || item->xc > ws_Width - Node_Radius || item->yc < Node_Radius || item->yc > ws_Height - Node_Radius){
            auto &list = map[item->lastBlock];

            int ix = list.indexOf(item);
            if (ix >= 0) list.remove(ix);

            it = selected.erase(it);
            removeNode(item->index,true);
            continue;
        }

        block = block_count*(item->yc/block_RangeX) + (item->xc/block_RangeX);

        if (item->lastBlock != block){
            auto &list = map[item->lastBlock];

            int ix = list.indexOf(item);
            if (ix >= 0) list.remove(ix);
            item->lastBlock = block;
            map[block].append(item);
        }

        ++it;
    }
}

Node* nodeListModel::getCollision(int &index, bool consider_offset){
    auto item = nodeList[index];

    if (consider_offset){
        auto list = &map[block_count*((item->yc+item->ry)/block_RangeX)+((item->xc+item->rx)/block_RangeX)];

        for (auto node : *list){
            if (node == item) continue;
            if (qSqrt(qPow(node->xc-item->xc-item->rx,2)+qPow(node->yc-item->yc-item->ry,2)) < Selector_Radius) return node;
        }
    } else {
        auto list = &map[block_count*(item->yc/block_RangeX)+(item->xc/block_RangeX)];

        for (auto node : *list){
            if (node == item) continue;
            if (qSqrt(qPow(node->xc-item->xc,2)+qPow(node->yc-item->yc,2)) < Selector_Radius) return node;
        }
    }

    return nullptr;
}

void nodeListModel::selectNode(int nodeID, bool append){
    if (!append) {
        for (auto &item : selected) setData(index(item->index),false,nRoles::isSelected);
        selected.clear();
    }

    selected.append(nodeList[nodeID]);
    setData(index(nodeID),true,nRoles::isSelected);
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
    case isSelected:
        return item->isSelected;
    case nDetonate:
        return QVariant(item->destroy);
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
    item->destroy = false;
    item->index = i;

    short   row = item->yc/block_RangeY,
            column = item->xc/block_RangeX;

    item->lastBlock = block_count*row + column;
    map[item->lastBlock].append(item);
    nodeList.append(item);

    endInsertRows();
}

void nodeListModel::remove(){
    for (auto &item: selected){
        removeNode(item->index, true);
    }
    selected.clear();
}

void nodeListModel::removeNode(int i, bool relations, bool animate){
    if (animate){
        setData(index(i), QVariant(true), nDetonate);
    }else{
        beginRemoveRows(QModelIndex(), i,i);
        if (relations) emit removeBindings(i);

        auto item = nodeList.takeAt(i);

        auto &list = map[item->lastBlock];
        int ix = list.indexOf(item);
        if (ix >= 0) list.remove(ix);

        delete item;

        endRemoveRows();

        emit removeItem(i);
        emit dataChanged(index(i),index(nodeList.size()-1),{nIndex});
    }
}

Node* nodeListModel::getNode(int index, bool checkExisted){
    if (!checkExisted) return nodeList[index];

    auto collision = getCollision(index,true);
    if (collision != nullptr) return collision;

    auto item = nodeList[index];

    int x = item->xc+item->rx,
        y = item->yc+item->ry;

    if (x < Node_Radius || x > ws_Width - Node_Radius || y < Node_Radius || y > ws_Height - Node_Radius) return nullptr;

    addNode(x,y);
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
    case isSelected:
        item->isSelected = value.toBool();
        break;
    case nDetonate:
        item->destroy = value.toBool();
        break;
    default:
        return false;
    }

    emit dataChanged(index,index,{role});

    return true;
}

void nodeListModel::update(int i, int value, int role, bool multi){
    if (multi) {
        for (auto &node: selected) {
            if (node->index != i) {
                switch (role) {
                case nRoles::xc:
                    update(node->index, node->xc + value-nodeList[i]->xc,role, false);
                    break;
                case nRoles::yc:
                    update(node->index, node->yc + value-nodeList[i]->yc,role, false);
                    break;
                }
            }
        }
    }

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

