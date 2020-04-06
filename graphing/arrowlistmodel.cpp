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
        if (item.A == item.B) return QVariant(item.B->xc+item.B->rx/2);         // new arrow
        else return QVariant((item.B->xc+item.A->xc)/2);
    case yyy:
        if (item.A == item.B) return QVariant(item.B->yc+item.B->ry/2);         // new arrow
        else return QVariant((item.B->yc+item.A->yc)/2);
    case alpha:
    {
        int v_x,v_y;

        if (item.A == item.B){
            v_x = item.B->rx;
            v_y = item.B->ry;
        }else{
            v_x = item.B->xc-item.A->xc;
            v_y = item.B->yc-item.A->yc;
        }

        float a = qRadiansToDegrees(qAcos(v_y/(qSqrt(qPow(v_x,2)+qPow(v_y,2)))));

        if (v_x > 0) return QVariant(360 - a);
        else return QVariant(a);
    }
    case len:
        if (item.A == item.B) return QVariant(qSqrt(qPow(item.B->rx,2)+qPow(item.B->ry,2)));
        else return QVariant(qSqrt(qPow(item.B->xc-item.A->xc,2)+qPow(item.B->yc-item.A->yc,2)));
    case bDir:
        return QVariant(item.bidirectional);
    default:
        return QVariant();
    }
}

void arrowListModel::updated(Node *node){           // обновление ребер, связанных с передаваемой точкой в качестве аргумента
    if (arrowList.isEmpty()) return;                // проверка наличия ребер

    auto list = map.constFind(node);                               // получаем список ребер из матрицы
    if (list == map.constEnd()) {
        qDebug() << "loser node:"<< node;
        return;
    }
    QTextStream Qcout(stdout);

    Qcout << "updated arrows:";
    for(auto &ix : *list) {
        auto i = index(ix);                         // получаем индекс ребра и
        Qcout << " " << ix;
        emit dataChanged(i,i);                      // обновляем его содержимое
    }
    Qcout << "\n";
}

void arrowListModel::bindA(int nodeIndex){              // привязка первого узла к ребру
    auto *p_node = emit getNode(nodeIndex);             // получаем узел по его идентификатору

    auto index = arrowList.size();
    beginInsertRows(QModelIndex(),index,index);         // создаем новое ребро

    Arrow item;                                         // процесс инициализации ребра
    item.A = p_node;
    item.B = p_node;
    item.bidirectional = false;
    arrowList.append(item);                             // занесение в список
    map[item.A].insert(index);                          // занесение ребра в матрицу инцидентности

    endInsertRows();
}

void arrowListModel::bindB(int nodeIndex){              // привязка второго узла к ребру
    auto *p_node = emit getNode(nodeIndex);             // получаем узел по его идентификатору
    arrowList.last().B = p_node;                        // присваиваем последнему ребру (новому) второй узел

    int arrowID = arrowList.size()-1;                   // добавляем ребро в матрицу инцидентности для второго узла
    map[p_node].insert(arrowID);

    //updated(p_node);

    /*
    map[arrowList[arrowID].A].remove(arrowID);
    if (map[arrowList[arrowID].A].isEmpty()) map.remove(arrowList[arrowID].A);
    */
}

void arrowListModel::remove(int A, int B){
    auto *pA = getNode(A);
    auto list_it = map.find(pA);
    if (list_it == map.end()) return;
    auto *pB = getNode(B);

    int index = -1;

    for (auto &arrowID : *list_it){
        if (arrowList[arrowID].A == pA && arrowList[arrowID].B == pB){
            index = arrowID;
            break;
        }
    }

    if (index != -1){
        beginRemoveRows(QModelIndex(),index,index);
        arrowList.remove(index);
        (*list_it).remove(index);
        if (list_it->isEmpty()) map.remove(pA);
        endRemoveRows();
    }
}

void arrowListModel::showMap(){
    QTextStream Qcout(stdout);

    Qcout << "\n---MAP---\n";

    auto nodes = map.keys();

    for (auto &node : nodes){
        Qcout << node << " :";
        for (auto &arrow : map[node]){
            Qcout << "  " << arrow;
        }
        Qcout << "\n";
    }

    Qcout << "\n---------\n";
}

void arrowListModel::showArrowList(){
    qDebug() << "---Arrows---";

    for (auto &arrow : arrowList){
        qDebug() << arrow.A->index << arrow.B->index << arrow.bidirectional;
    }

    qDebug() << "------------";
}
