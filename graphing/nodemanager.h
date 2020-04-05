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

#include <QAbstractListModel>
#include <arrowlistmodel.h>
#include <nodelistmodel.h>

class NodeManager : public QObject
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

    nodeListModel node_model;
    arrowListModel arrow_model;
private:
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    void updateMatrix(int NodeA, int NodeB, bool related);

    QString filePath;
    QVector<QVector<int>> matrix;   // nodes relations

private slots:
    void addItem();
    void removeItem(int index);
};

#endif // NODEMANAGER_H
