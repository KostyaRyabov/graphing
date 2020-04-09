#ifndef NODELISTMODEL_H
#define NODELISTMODEL_H

#include <QAbstractListModel>
#include <structures.h>
#include <QDebug>

#include <QtMath>
#include <options.h>

class nodeListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    nodeListModel(QObject *parent = nullptr);
    ~nodeListModel();

    enum nRoles{
        xc = Qt::UserRole + 1,
        yc,
        rx,
        ry,
        Index
    };

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Q_INVOKABLE void addNode(int x, int y);
    Q_INVOKABLE void update(int i, int value, int role);
    Q_INVOKABLE void removeNode(int i, bool relations);
    Q_INVOKABLE void checkNodeCollision(int index);

    Q_INVOKABLE void showNodeList();
private:
    QVector<Node*> nodeList;
signals:
    void mergeNodes(Node* From, Node* To);
    void removeBindings(Node* node);
    void updated(Node* node);
    void addItem();
    void removeItem(int index);
    Q_INVOKABLE void removeArrowsWidth(QVector<Node*> list);
private slots:
    Node* getNode(int index, bool checkExisted);
};

#endif // NODELISTMODEL_H
