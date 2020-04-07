#ifndef ARROWLISTMODEL_H
#define ARROWLISTMODEL_H

#include <QAbstractListModel>
#include <structures.h>
#include <QDebug>
#include <QtMath>

#include <QHash>

#include <QLinkedList>

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

    Q_INVOKABLE void remove(Arrow* arrow);
    Q_INVOKABLE void removeCurrent();

    Q_INVOKABLE void showMap();
    Q_INVOKABLE void showArrowList();

    Q_INVOKABLE void kill();

    int getArrowID(int A, int B);
private:
    QVector<Arrow*> arrowList;
    QHash<Node*,QSet<Arrow*>> map;      // матрица инцидентности

    QLinkedList<Arrow*> del_list;
    void cutArrow(Arrow* arrow);
private slots:
    void removeBindings(Node* node);
    void updated(Node *node);
signals:
    Node* getNode(int index, bool checkExisted);
    int checkExisting(int A, int B);
    void updateMatrix(int NodeA, int NodeB, Arrow* p_arrow);
    Arrow* getArrow(int NodeA, int NodeB);
};

#endif // ARROWLISTMODEL_H
