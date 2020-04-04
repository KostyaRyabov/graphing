#include "nodemanager.h"

#include <QQuickItem>

NodeManager::NodeManager(QObject *parent) : QObject(parent)
{
    auto rootContext = engine.rootContext();

    rootContext->setContextProperty("manager", this);

    //default properties
    rootContext->setContextProperty("nodeRadius", 8);
    rootContext->setContextProperty("wsHeight", 512);
    rootContext->setContextProperty("wsWidth", 512);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty()) return;

    root = engine.rootObjects()[0];
    workspace = root->findChild<QObject*>("workspace");

    nodeComponent = new QQmlComponent(&engine, QUrl(QStringLiteral("qrc:/Node.qml")));
    arrayComponent = new QQmlComponent(&engine, QUrl(QStringLiteral("qrc:/Arror.qml")));
}

NodeManager::~NodeManager(){

}


void NodeManager::newFile(){
    //clear all data
    model.matrix.clear();
    filePath.clear();

    emit dataChanged();
}

void NodeManager::openFile(){
    filePath = QFileDialog::getOpenFileName(0, "file path", "", "*.json");

    if (!filePath.isNull()){
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly)){
            qWarning("Couldn't open file.");
            return;
        }

        QByteArray data = file.readAll();
        QJsonDocument document(QJsonDocument::fromJson(data));
        read(document.object());
    }
}

void NodeManager::saveFile(){
    filePath = QFileDialog::getSaveFileName(0, "file path", "", "*.json");

    if (!filePath.isNull()){
        saveAsFile();
    }
}

void NodeManager::saveAsFile(){
    // saving by prepared file path

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)){
        qWarning("Couldn't create file.");
        return;
    }

    QJsonObject data;
    write(data);
    QJsonDocument document(data);
    file.write(document.toJson());
}

bool NodeManager::filePathExists(){
    return !filePath.isNull();
}

void NodeManager::addNode(int x, int y){
    auto obj = nodeComponent->create();
    obj->setProperty("parent", QVariant::fromValue(workspace));
    obj->setProperty("xc", x);
    obj->setProperty("yc", y);
    obj->setProperty("index", nodeList.size());

    nodeList.append(obj);

    for (auto &row : model.matrix){ row.append(0); }

    QVector<int> newRow;
    newRow.reserve(nodeList.size());
    newRow.fill(0,nodeList.size());

    model.matrix.append(newRow);
}

void NodeManager::updateMatrix(int NodeA, int NodeB, bool related){
    model.matrix[NodeA][NodeB] = related;
}

void NodeManager::removeNode(int i){
    nodeList.remove(i);

    for (auto j = i; j < nodeList.size(); j++){
        nodeList[j]->setProperty("identifier", i++);
    }
    /*
    matrix.remove(i);
    for (auto &row : matrix){
        row.remove(i);
    }
    */


}

void NodeManager::read(const QJsonObject &json){
    model.matrix.clear();
    QJsonArray mxArray = json["Nodes"].toArray();

    for (int mxIndex = 0; mxIndex < mxArray.size(); ++mxIndex) {
        QJsonArray mxRow = mxArray[mxIndex].toArray();
        QVector<int> newRow;
        for (auto mxitem : mxRow){
            newRow.append(mxitem.toInt());
        }
        model.matrix.append(newRow);
    }
}

void NodeManager::write(QJsonObject &json) const{
    QJsonArray mxArray;
    for (auto &row : model.matrix) {
        QJsonArray mxRow;
        for (auto &item : row){
            mxRow.append(item);
        }
        mxArray.append(mxRow);
    }
    json["Nodes"] = mxArray;
}
