#ifndef ARROWLISTMODEL_H
#define ARROWLISTMODEL_H

#include <QAbstractListModel>
#include <structures.h>
#include <QDebug>
#include <QtMath>

#include <QHash>

class arrowListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    arrowListModel(QObject *parent = nullptr);
    ~arrowListModel();

    enum aRoles{
        xxx = Qt::UserRole + 1,
        yyy = Qt::UserRole + 2,
        len = Qt::UserRole + 3,
        alpha = Qt::UserRole + 4,
        bDir = Qt::UserRole + 5
    };

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void bind(int nodeIndex);
    //removeNode
private:
    QVector<Arrow> arrowList;
    QHash<Node*,QSet<int>> map;      //search: node -> arrows (update)           map<key-node,list<ArrowID>>

    void updateMatrix(int NodeA, int NodeB, bool related);
private slots:
    void updated(Node *node);
signals:
    Node* getNode(int index);
};

#endif // ARROWLISTMODEL_H
