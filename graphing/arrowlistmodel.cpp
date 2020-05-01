#include "arrowlistmodel.h"

arrowListModel::arrowListModel(QObject *parent) : QAbstractListModel(parent)
{
    del_list.reserve(reservedItemsCount);
    arrowList.reserve(reservedItemsCount);
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
    roles[aDetonate] = "Delete";
    roles[aIndex] = "arrow_id";
    roles[isMoving] = "selected";
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
        if (item->A == item->B) return QVariant(item->B->xc+item->B->rx/2);
        else return QVariant((item->B->xc+item->A->xc)/2);
    case yyy:
        if (item->isLooped) return QVariant(item->A->yc+1.5*Node_Radius);
        if (item->A == item->B) return QVariant(item->B->yc+item->B->ry/2);
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
    case aDetonate:
        item->destroy = !item->destroy;
        return QVariant(item->destroy);
    case aIndex:
        item->index = index.row();
        return QVariant(item->index);
    case isMoving:
        return (selectedID == item->index);
    default:
        return QVariant();
    }
}

void arrowListModel::createLoop(int nodeIndex){
    if (emit checkLoopExisting(nodeIndex)) return;

    auto *p_node = emit getNode(nodeIndex,false);

    auto index = arrowList.size();
    beginInsertRows(QModelIndex(),index,index);

    Arrow* item = new Arrow();
    item->A = p_node;
    item->B = p_node;
    item->isLooped = true;
    item->bidirectional = false;
    arrowList.append(item);

    emit updateMatrix(nodeIndex,nodeIndex,item);

    endInsertRows();
}

void arrowListModel::bindA(int nodeIndex){
    auto *p_node = emit getNode(nodeIndex,false);

    auto index = arrowList.size();
    beginInsertRows(QModelIndex(),index,index);

    Arrow* item = new Arrow();
    item->A = p_node;
    item->B = p_node;
    item->isLooped = false;
    item->bidirectional = false;
    item->index = index;
    arrowList.append(item);

    adding = true;

    endInsertRows();
}

void arrowListModel::bindB(int nodeIndex, bool exist){
    auto *p_node = emit getNode(nodeIndex, exist);
    auto currentArrow = arrowList.last();

    if (p_node != nullptr){
        switch (emit checkExisting(currentArrow->A->index,p_node->index)) {
            case aDir::OutSimplex: {
                auto arrow = getArrow(p_node->index,currentArrow->A->index);
                emit updateMatrix(currentArrow->A->index,p_node->index,arrow);

                remove(currentArrow->index,false);
                auto i = index(arrow->index);
                arrowList[arrow->index]->bidirectional = true;
                emit dataChanged(i,i,{aRoles::bDir});
                break;
            } case aDir::InSimplex:{
                remove(currentArrow->index,false);
                break;
            } case aDir::Duplex:{
                remove(currentArrow->index,false);
                break;
            } default:{
                emit updateMatrix(currentArrow->A->index, p_node->index,currentArrow);
                currentArrow->B = p_node;
                auto i = index(arrowList.size()-1);
                emit dataChanged(i,i,{xxx,yyy,len,alpha});
                break;
            }
        }
    }else removeCurrent();

    adding = false;
}

int arrowListModel::getArrowID(int A, int B){
    return arrowList.indexOf(emit getArrow(A,B));
}

void arrowListModel::changeFocus(int arrowID){
    QModelIndex ix;

    ix = index(selectedID);
    selectedID = arrowID;
    emit dataChanged(ix,ix,{isMoving});

    ix = index(selectedID);
    emit dataChanged(ix,ix,{isMoving});
}

void arrowListModel::moveTo(int arrowID, int lX, int lY, float angle){
    Arrow* arrow = arrowList[arrowID];

    angle = qDegreesToRadians(angle);

    double S = qSin(angle);
    double C = qCos(angle);
    int x = lX*C-lY*S;
    int y = lX*S+lY*C;

    emit selectNode(arrow->A->index,false);
    emit selectNode(arrow->B->index,true);

    emit updateNode(arrow->A->index,arrow->A->xc+x,nRoles::xc);
    emit updateNode(arrow->A->index,arrow->A->yc+y,nRoles::yc);
}

void arrowListModel::remove(int arrowID,bool animated){
    if (animated){
        auto i = index(arrowID);
        emit dataChanged(i,i,{aDetonate});
        del_list.push_front(arrowList[arrowID]);
    }else{
        beginRemoveRows(QModelIndex(),arrowID,arrowID);
        auto arrow = arrowList.takeAt(arrowID);
        delete arrow;
        endRemoveRows();

        emit dataChanged(index(arrowID),index(arrowList.size()-1),{aIndex});

        adding = false;

        if (checkSize) {
            emit cleared();
            checkSize = false;
        }
    }
}

void arrowListModel::removeCurrent(){
    remove(arrowList.last()->index,true);
}

void arrowListModel::kill(){
    if (!del_list.isEmpty()){
        remove(del_list.takeLast()->index,false);
    }
}

void arrowListModel::showArrowList(){
    qDebug() << "---Arrows["+QVariant(arrowList.size()).toString()+"]---";

    for (auto &arrow : arrowList){
        qDebug() << arrow->index;
    }

    qDebug() << "------------";
}
