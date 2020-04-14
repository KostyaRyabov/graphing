#ifndef NODELISTMODEL_H
#define NODELISTMODEL_H

#include <QAbstractListModel>
#include <structures.h>
#include <QDebug>

#include <QtMath>
#include <options.h>

enum nRoles{
    xc = Qt::UserRole + 1,
    yc,
    rx,
    ry,
    nIndex,
    isSelected
};

class nodeListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    nodeListModel(QObject *parent = nullptr);
    ~nodeListModel();

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Q_INVOKABLE void addNode(int x, int y);
    Q_INVOKABLE void removeNode(int i, bool relations);
    Q_INVOKABLE void checkNodeCollision(int index);

    Q_INVOKABLE void selectNode(int nodeID, bool append);

    Q_INVOKABLE void showNodeList();
    Q_INVOKABLE void selectNodesOnRect(int left, int top, int right, int bottom, int offsetX, int offsetY, float scale);

    Node* getCollision(int &index, bool consider_offset = false);
    void updateNodePosition(int &index);

    friend class NodeManager;
private:
    QVector<Node*> nodeList;        //view
    QVector<Node*> map[block_Size*block_Size];     //for searching
    QVector<Node*> selected;
signals:
    void mergeNodes(Node* From, Node* To);
    void removeBindings(int &nodeA);
    void updateBindings(int &nodeA);
    void addItem();
    void removeItem(int index);
    Q_INVOKABLE void removeArrowsWidth(QVector<Node*> list);
public slots:
    Q_INVOKABLE void update(int i, int value, int role, bool multi = true);
    Node* getNode(int index, bool checkExisted);
};

#endif // NODELISTMODEL_H
