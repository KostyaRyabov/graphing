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

#include <QThread>
#include <QQmlComponent>

#include <QVector>

#include <QAbstractListModel>
#include <arrowlistmodel.h>
#include <nodelistmodel.h>

class NodeManager : public QObject
{
    Q_OBJECT
public:
    NodeManager(QObject *parent = nullptr);
    ~NodeManager();

    Q_INVOKABLE void clear();
    Q_INVOKABLE bool openFile();
    Q_INVOKABLE bool saveFile();
    Q_INVOKABLE bool saveAsFile();

    Q_INVOKABLE void showMatrix();
    Q_INVOKABLE void removeArrow(int arrowID);

    nodeListModel node_model;
    arrowListModel arrow_model;
private:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    QVector<QVector<Arrow*>> matrix;   // матрица смежности

    QFile file;
    void mergeArrows(int &FromID, int &ToID, int &i);
private slots:
    void readFile();
    void mergeNodes(Node* From, Node* To);
    void updateBindings(int &nodeA);
    void removeBindings(int &nodeA);
    void addItem();
    Q_INVOKABLE void removeNode(int index);
    int checkExisting(int A, int B);
    void updateMatrix(int NodeA, int NodeB, Arrow* p_arrow);
    Arrow* getArrow(int NodeA, int NodeB);
};

#endif // NODEMANAGER_H
