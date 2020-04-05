#include "nodemanager.h"

#include <QQuickItem>

NodeManager::NodeManager(QObject *parent) : QObject(parent)
{
    connect(&node_model, SIGNAL(addItem()), this, SLOT(addItem()));
    connect(&arrow_model, SIGNAL(getNode(int)), &node_model, SLOT(getNode(int)));
    connect(&node_model, SIGNAL(updated(Node*)), &arrow_model, SLOT(updated(Node*)));
}

NodeManager::~NodeManager(){

}

void NodeManager::newFile(){
    //clear all data
    matrix.clear();
    filePath.clear();

    //emit dataChanged();
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

void NodeManager::read(const QJsonObject &json){
    matrix.clear();
    QJsonArray mxArray = json["Nodes"].toArray();

    for (int mxIndex = 0; mxIndex < mxArray.size(); ++mxIndex) {
        QJsonArray mxRow = mxArray[mxIndex].toArray();
        QVector<int> newRow;
        for (auto mxitem : mxRow){
            newRow.append(mxitem.toInt());
        }
        matrix.append(newRow);
    }
}

void NodeManager::write(QJsonObject &json) const{
    QJsonArray mxArray;
    for (auto &row : matrix) {
        QJsonArray mxRow;
        for (auto &item : row){
            mxRow.append(item);
        }
        mxArray.append(mxRow);
    }
    json["Nodes"] = mxArray;
}

void NodeManager::updateMatrix(int NodeA, int NodeB, bool related){
    matrix[NodeA][NodeB] = related;
}

void NodeManager::addItem(){
    for (auto &row : matrix) row.append(0);
    matrix.append(QVector<int>().fill(0,matrix.size()));
}

void NodeManager::removeItem(int index){
    matrix.remove(index);
    for (auto &row : matrix) row.remove(index);
}
