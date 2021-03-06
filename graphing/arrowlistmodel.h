#ifndef ARROWLISTMODEL_H
#define ARROWLISTMODEL_H

#include <QAbstractListModel>
#include <structures.h>
#include <QDebug>
#include <QtMath>
#include <QHash>
#include <nodelistmodel.h>
#include <QQueue>
#include <options.h>

enum aRoles{
    xxx = Qt::UserRole + 1,
    yyy,
    len,
    alpha,
    bDir,
    aDetonate,
    isMoving,
    aIndex
};

class arrowListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    arrowListModel(QObject *parent = nullptr);
    ~arrowListModel();

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void createLoop(int nodeIndex);
    Q_INVOKABLE void bindA(int nodeIndex);
    Q_INVOKABLE void bindB(int nodeIndex, bool exist = true);
    Q_INVOKABLE void remove(int arrowID,bool animated);
    Q_INVOKABLE void removeCurrent();
    Q_INVOKABLE void showArrowList();
    Q_INVOKABLE void kill();
    Q_INVOKABLE void moveTo(int arrowID, int lX, int lY, float angle);
    int getArrowID(int A, int B);

    Q_INVOKABLE void changeFocus(int arrowID);
    friend class NodeManager;
private:
    QVector<Arrow*> arrowList;

    QQueue<Arrow*> del_list;
    bool adding = false;

    int selectedID = -1;

    bool checkSize = false;
signals:
    void cleared();
    void checkNodeCollision();
    void updateNodesPosition();

    void selectNode(int nodeID,bool append);
    void updateNode(int i, int value, int role);
    QVector<Arrow*> getArrowListWithNode(int nodeA);
    Node* getNode(int index, bool checkExisted);
    int checkExisting(int A, int B);
    void updateMatrix(int NodeA, int NodeB, Arrow* p_arrow);
    bool checkLoopExisting(int nodeID);
    Arrow* getArrow(int NodeA, int NodeB);
};

#endif // ARROWLISTMODEL_H
