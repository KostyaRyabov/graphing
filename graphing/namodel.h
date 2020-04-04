#ifndef NAMODEL_H
#define NAMODEL_H

#include <QAbstractItemModel>

struct Node{
    uint x,y;
};

class naModel : public QAbstractItemModel
{
public:
    naModel();
    ~naModel();

    enum maRoles{
        PosX = Qt::UserRole + 1,
        PosY = Qt::UserRole + 2,
        Index = Qt::UserRole + 3,
    };

    QHash<int, QByteArray> roleNames() const;

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
private:
    QVector<Node> NodeList;         // visual control
    QVector<QVector<int>> matrix;   // nodes relations
};

#endif // NAMODEL_H
