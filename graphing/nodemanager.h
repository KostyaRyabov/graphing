#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlListProperty>
#include <QQmlContext>

#include <QQuickView>

#include <QObject>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

#include <QQmlComponent>

#include <QAbstractItemModel>
#include <QAbstractListModel>

struct Node{
    int x,y,index;
};

struct Arrow{
    Node* A;
    Node* B;

    bool bidirectional = false;
};


class NodeManager : public QAbstractListModel
{
    Q_OBJECT
public:
    NodeManager(QObject *parent = nullptr);
    ~NodeManager();

    Q_INVOKABLE void newFile();
    Q_INVOKABLE void openFile();
    Q_INVOKABLE void saveFile();
    Q_INVOKABLE void saveAsFile();
    Q_INVOKABLE bool filePathExists();

    enum maRoles{
        PosX = Qt::UserRole + 1,
        PosY = Qt::UserRole + 2,
        Index = Qt::UserRole + 3,
    };

    QHash<int, QByteArray> roleNames() const;

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
public slots:
    void addNode(int x, int y);
    void removeNode(int i);
private:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    void updateMatrix(int NodeA, int NodeB, bool related);

    QString filePath;
    QVector<Node> nodeList;         // visual control
    QVector<Arrow> arrowList;
    QVector<QVector<int>> matrix;   // nodes relations
};

#endif // NODEMANAGER_H
