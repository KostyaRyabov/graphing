#ifndef NODELISTMODEL_H
#define NODELISTMODEL_H

#include <QAbstractListModel>
#include <structures.h>
#include <QDebug>

class nodeListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    nodeListModel(QObject *parent = nullptr);
    ~nodeListModel();

    enum nRoles{
        xc = Qt::UserRole + 1,
        yc = Qt::UserRole + 2,
        rx = Qt::UserRole + 3,
        ry = Qt::UserRole + 4,
        Index = Qt::UserRole + 5
    };

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Q_INVOKABLE void addNode(int x, int y);
    Q_INVOKABLE void update(int i, int value, int role);
    Q_INVOKABLE void removeNode(int i);

    Q_INVOKABLE void showNodeList();
private:
    QVector<Node*> nodeList;
signals:
    void updated(Node* node);
    void addItem();
    void removeItem(int index);
private slots:
    Node* getNode(int index);
};

#endif // NODELISTMODEL_H
