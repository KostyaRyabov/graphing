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

    Q_INVOKABLE void bindA(int nodeIndex);
    Q_INVOKABLE void bindB(int nodeIndex);
    Q_INVOKABLE void remove(int A, int B);

    Q_INVOKABLE void showMap();
    Q_INVOKABLE void showArrowList();
private:
    QVector<Arrow> arrowList;
    QHash<Node*,QSet<int>> map;      // матрица инцидентности

    void updateMatrix(int NodeA, int NodeB, bool related);
private slots:
    void updated(Node *node);
signals:
    Node* getNode(int index);
};

#endif // ARROWLISTMODEL_H
