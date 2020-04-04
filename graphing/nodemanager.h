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

#include <namodel.h>

#include <QQmlComponent>
class NodeManager : public QObject
{
    Q_OBJECT
public:
    NodeManager(QObject *parent = nullptr);
    ~NodeManager();

    Q_PROPERTY(NOTIFY dataChanged)
    Q_INVOKABLE void newFile();
    Q_INVOKABLE void openFile();
    Q_INVOKABLE void saveFile();
    Q_INVOKABLE void saveAsFile();
    Q_INVOKABLE bool filePathExists();

    naModel model;
signals:
    void dataChanged();
public slots:
    void addNode(int x, int y);
    void removeNode(int i);
private:
    QQmlComponent *nodeComponent;
    QQmlComponent *arrayComponent;

    QQmlApplicationEngine engine;
    QObject *root;
    QObject *workspace;

    QVector<QObject*> nodeList;
    QVector<QObject*> arrowList;

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    void updateMatrix(int NodeA, int NodeB, bool related);

    QString filePath;
};

#endif // NODEMANAGER_H
