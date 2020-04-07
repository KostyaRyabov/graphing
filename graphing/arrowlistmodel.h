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
        yyy,
        len,
        alpha,
        bDir,
        detonate
    };

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void bindA(int nodeIndex);
    Q_INVOKABLE void bindB(int nodeIndex);

    void remove(Node* A, Node* B);
    Q_INVOKABLE void remove(int A, int B);

    Q_INVOKABLE void showMap();
    Q_INVOKABLE void showArrowList();

    int getArrowID(int A, int B);
private:
    QVector<Arrow*> arrowList;
    QHash<Node*,QSet<Arrow*>> map;      // матрица инцидентности
private slots:
    void updated(Node *node);
    Q_INVOKABLE void removeArrowsWidth(QVector<Node*> list);
signals:
    Node* getNode(int index, bool checkExisted);
    int checkExisting(int A, int B);
    void updateMatrix(int NodeA, int NodeB, Arrow* p_arrow);
    Arrow* getArrow(int NodeA, int NodeB);
};

#endif // ARROWLISTMODEL_H
