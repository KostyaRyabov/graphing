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

void nodeListModel::selectNodesOnRect(int left, int top, int right, int bottom, int offsetX, int offsetY, float scale){
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

    qDebug() << "---------------------"<< scale <<"-----------------------";

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

    qDebug() << left << right << top << bottom;

    int X,Y, newX, newY;

    /*
     P.S.: scale фактор не учитывался сразу

     0) если левая граница селектора меньше левой границы рабочей области приравнять нулю
     1) если правая граница селектора больше правой границы блока, то делать сдвиг, иначе присвоить правой ганице блока правую границу селектора (и потов выйти из цыкла)
     2) если ширина блока равна рассчитываемому то включить весь блок, иначе проводить выборку по растоянию
    */

    for (X = left; X < right; X = newX){
        newX = (X/block_RangeX+1)*block_RangeX;
        if (newX > right) newX = right;

        for (Y = top; Y < bottom; Y = newY){
            newY = (Y/block_RangeY+1)*block_RangeY;
            if (newY > bottom) newY = bottom;

            if ((newX - X >= block_RangeX) && (newY - Y >= block_RangeY)){
                selected.append(map[(Y/block_RangeY)*block_Size+(X/block_RangeX)]);
            }else{
                for (auto node : map[(Y/block_RangeY)*block_Size+(X/block_RangeX)]){
                    if ((X <= node->xc && node->xc <= newX) && (Y <= node->yc && node->yc <= newY)) {
                        selected.append(node);
                    }
                }
            }
        }
    }

    qDebug() << "selected:";
    for (auto &node : selected){
        qDebug() << node->index;
    }
}

void nodeListModel::checkNodeCollision(int index){          //O(N)
    //update node position on map

    updateNodePosition(index);

    auto collision = getCollision(index);
    if (collision != nullptr) emit mergeNodes(nodeList[index], collision);
}

void nodeListModel::updateNodePosition(int &index){
    auto item = nodeList[index];

    short   row = item->yc/block_RangeX,
            column = item->xc/block_RangeX,
            block = block_Size*row + column;

    if (item->lastBlock != block){
        auto &list = map[item->lastBlock];

        qDebug() << "list";
        for (auto &el : list){
            qDebug() << el->index;
        }

        int ix = list.indexOf(item);
        if (ix >= 0) list.remove(ix);
        item->lastBlock = block;
        qDebug() << "move to block №"<<item->lastBlock;
        map[block].append(item);
    }
}

Node* nodeListModel::getCollision(int &index, bool consider_offset){
    auto item = nodeList[index];

    if (consider_offset){
        auto list = &map[block_Size*((item->yc+item->ry)/block_RangeX)+((item->xc+item->rx)/block_RangeX)];

        for (auto node : *list){
            if (node == item) continue;
            if (qSqrt(qPow(node->xc-item->xc-item->rx,2)+qPow(node->yc-item->yc-item->ry,2)) < Selector_Radius) return node;
        }
    } else {
        auto list = &map[block_Size*(item->yc/block_RangeX)+(item->xc/block_RangeX)];

        for (auto node : *list){
            if (node == item) continue;
            if (qSqrt(qPow(node->xc-item->xc,2)+qPow(node->yc-item->yc,2)) < Selector_Radius) return node;
        }
    }

    return nullptr;
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

    short   row = item->yc/block_RangeY,
            column = item->xc/block_RangeX;
    item->lastBlock = block_Size*row + column;
    qDebug() << "block №"<<item->lastBlock;
    map[item->lastBlock].append(item);
    nodeList.append(item);

    qDebug() << "list";
    for (auto &el : map[item->lastBlock]){
        qDebug() << el->index;
    }

    endInsertRows();
}

void nodeListModel::removeNode(int i, bool relations){
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

Node* nodeListModel::getNode(int index, bool checkExisted){
    if (!checkExisted) return nodeList[index];

    auto collision = getCollision(index,true);
    if (collision != nullptr) return collision;

    auto item = nodeList[index];
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

    emit dataChanged(index,index,{role});

    return true;
}

void nodeListModel::update(int i, int value, int role, bool multi){
    setData(index(i), value, role);

    if (multi) {
        for (auto &node: selected) {
            if (node->index != i) {
                //qDebug() << "           update node" << node->index << " role:" << role;

                switch (role) {
                case nRoles::xc:
                    update(node->index, node->xc + nodeList[i]->xc-value,role, false);
                    break;
                case nRoles::yc:
                    update(node->index, node->yc + nodeList[i]->yc-value,role, false);
                    break;
                }
            }
        }
    }

    emit updateBindings(i);
}

void nodeListModel::showNodeList(){
    qDebug() << "---Nodes---";

    for (auto node : nodeList){
        qDebug() << node << "|" << node->index << ":    (" << node->xc << node->yc << ")" << "(" << node->rx << node->ry << ")";
    }

    qDebug() << "-----------";
}

