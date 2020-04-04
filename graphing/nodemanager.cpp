#include "nodemanager.h"

#include <QQuickItem>

NodeManager::NodeManager(QObject *parent) : QAbstractListModel(parent)
{

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

void NodeManager::addNode(int x, int y){
    int i = nodeList.size();
    beginInsertRows(QModelIndex(),i,i);
    nodeList.append({x,y,i});
    endInsertRows();

    for (auto &row : matrix) row.append(0);
    matrix.append(QVector<int>().fill(0,i+1));
}

void NodeManager::removeNode(int i){
    matrix.remove(i);
    for (auto &row : matrix) row.remove(i);

    beginRemoveRows(QModelIndex(), i,i);
    nodeList.remove(i);
    endRemoveRows();

    for (auto j = i; j < nodeList.size(); j++) {
        setData(index(j), i++, maRoles::Index);
    }
}







// model


QHash<int, QByteArray> NodeManager::roleNames() const{
    QHash<int, QByteArray> roles;
    roles[PosX] = "node_x";
    roles[PosY] = "node_y";
    roles[Index] = "node_id";
    return roles;
}

int NodeManager::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return nodeList.size();
}

QVariant NodeManager::data(const QModelIndex &index, int role) const{
    if (!index.isValid()){
        return QVariant();
    }

    switch (role) {
    case PosX:
        return QVariant(nodeList[index.row()].x);
    case PosY:
        return QVariant(nodeList[index.row()].y);
    case Index:
        return QVariant(index.row());
    default:
        return QVariant();
    }
}

bool NodeManager::setData(const QModelIndex &index, const QVariant &value, int role){
    if (!index.isValid()){
        return false;
    }

    switch (role) {
    case maRoles::PosX:
        nodeList[index.row()].x = value.toInt();
        break;
    case maRoles::PosY:
        nodeList[index.row()].y = value.toInt();
        break;
    case maRoles::Index:
        nodeList[index.row()].index = value.toInt();
        break;
    default:
        break;
    }

    emit dataChanged(index, index);
    return true;
}
