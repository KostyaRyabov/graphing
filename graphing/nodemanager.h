#ifndef NODEMANAGER_H
#define NODEMANAGER_H

#include <QApplication>
#include <QObject>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <QVector>
#include <QAbstractListModel>
#include <arrowlistmodel.h>
#include <nodelistmodel.h>

struct iArrow{
    int A, B;
    bool bidirectional = false;
};

struct Buffer{
    int cx, cy;
    QList<QPair<int,int>> tmp_coord_list;
    QList<iArrow> tmp_arrow_list;
};

class NodeManager : public QObject
{
    Q_OBJECT
public:
    NodeManager(QObject *parent = nullptr);
    ~NodeManager();

    Q_INVOKABLE void clear(bool anim = true);
    Q_INVOKABLE bool openFile();
    Q_INVOKABLE bool saveFile();
    Q_INVOKABLE bool saveAsFile();
    Q_INVOKABLE void copy();
    Q_INVOKABLE void paste(int mouseX, int mouseY);

    Q_INVOKABLE void showMatrix();
    Q_INVOKABLE void removeArrow(int arrowID);

    nodeListModel node_model;
    arrowListModel arrow_model;
private:
    bool read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    Buffer buffer;
    QVector<QVector<Arrow*>> matrix;
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
    bool checkLoopExisting(int nodeID);
signals:
    void debug(QString text);
};

#endif // NODEMANAGER_H
