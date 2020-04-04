#include "namodel.h"

naModel::naModel()
{

}

naModel::~naModel()
{

}

QHash<int, QByteArray> naModel::roleNames() const{
    QHash<int, QByteArray> roles;
    roles[maRoles::PosX] = "xc";
    roles[maRoles::PosY] = "yc";
    roles[maRoles::Index] = "index";
    return roles;
}

int naModel::rowCount(const QModelIndex &parent = QModelIndex()) const{
    return
}

QVariant naModel::data(const QModelIndex &index, int role = Qt::DisplayRole) const{

}
