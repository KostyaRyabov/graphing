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
    roles[aIndex] = "arrow_id";
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
        return QVariant(item->destroy);
    case aIndex:
        item->index = index.row();
        return QVariant(item->index);
    default:
        return QVariant();
    }
}

void arrowListModel::createLoop(int nodeIndex){
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
    item->index = index;
    arrowList.append(item);                            // занесение ребра в матрицу инцидентности

    adding = true;

    endInsertRows();
}

void arrowListModel::bindB(int nodeIndex){              // привязка второго узла к ребру
    auto *p_node = emit getNode(nodeIndex,true);        // получаем узел по его идентификатору
    auto currentArrow = arrowList.last();

    switch (emit checkExisting(currentArrow->A->index,p_node->index)) {
        case aDir::OutSimplex: {
            auto arrow = getArrow(p_node->index,currentArrow->A->index);
            emit updateMatrix(currentArrow->A->index,p_node->index,arrow);     // устанавливается в матрице другое направление

            remove(currentArrow->index,false);
            auto i = index(arrow->index);
            arrowList[arrow->index]->bidirectional = true;
            qDebug() << "update dir:" << arrow->index;
            emit dataChanged(i,i,{aRoles::bDir});
            break;
        } case aDir::InSimplex:{
            remove(currentArrow->index,false);
            break;
        } case aDir::Duplex:{
            remove(currentArrow->index,false);
            break;
        } default:{
            emit updateMatrix(currentArrow->A->index, p_node->index,currentArrow);      // обновляется матрица
            currentArrow->B = p_node;                                 // добавляется карта
            auto i = index(arrowList.size()-1);
            emit dataChanged(i,i,{xxx,yyy,len,alpha});
            break;
        }
    }

    adding = false;
}

int arrowListModel::getArrowID(int A, int B){
    return arrowList.indexOf(emit getArrow(A,B));
}

void arrowListModel::moveTo(int arrowID, int lX, int lY, float angle){
    Arrow* arrow = arrowList[arrowID];

    angle = qDegreesToRadians(angle);

    double S = qSin(angle);
    double C = qCos(angle);
    int x = lX*C-lY*S;
    int y = lX*S+lY*C;

    emit updateNode(arrow->A->index,arrow->A->xc+x,nRoles::xc);
    emit updateNode(arrow->A->index,arrow->A->yc+y,nRoles::yc);

    emit updateNode(arrow->B->index,arrow->B->xc+x,nRoles::xc);
    emit updateNode(arrow->B->index,arrow->B->yc+y,nRoles::yc);
}

void arrowListModel::remove(int arrowID,bool animated){
    if (animated){
        auto i = index(arrowID);
        emit dataChanged(i,i,{detonate});
        del_list.push_front(arrowList[arrowID]);
    }else{
        beginRemoveRows(QModelIndex(),arrowID,arrowID);
        auto arrow = arrowList.takeAt(arrowID);
        delete arrow;
        endRemoveRows();

        emit dataChanged(index(arrowID),index(arrowList.size()-1),{aIndex});

        adding = false;
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
