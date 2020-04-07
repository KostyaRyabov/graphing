#include "nodemanager.h"

#include <QQuickItem>

NodeManager::NodeManager(QObject *parent) : QObject(parent)
{
    connect(&node_model, SIGNAL(addItem()), this, SLOT(addItem()));
    connect(&arrow_model, SIGNAL(getNode(int,bool)), &node_model, SLOT(getNode(int,bool)));
    connect(&node_model, SIGNAL(updated(Node*)), &arrow_model, SLOT(updated(Node*)));
    connect(&arrow_model, SIGNAL(checkExisting(int, int)), this, SLOT(checkExisting(int, int)));
    connect(&arrow_model, SIGNAL(updateMatrix(int, int, Arrow*)), this, SLOT(updateMatrix(int, int, Arrow*)));
    connect(&node_model, SIGNAL(removeItem(int)), this, SLOT(removeNode(int)));
    connect(&arrow_model, SIGNAL(getArrow(int,int)), this, SLOT(getArrow(int,int)));
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
    /*
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
    */
}

void NodeManager::saveFile(){
    /*
    filePath = QFileDialog::getSaveFileName(0, "file path", "", "*.json");

    if (!filePath.isNull()){
        saveAsFile();
    }
    */
}

void NodeManager::saveAsFile(){
    /*
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
    */
}

bool NodeManager::filePathExists(){
    return !filePath.isNull();
}

void NodeManager::read(const QJsonObject &json){
    /*
    matrix.clear();
    QJsonArray mxArray = json["Nodes"].toArray();

    for (int mxIndex = 0; mxIndex < mxArray.size(); ++mxIndex) {
        QJsonArray mxRow = mxArray[mxIndex].toArray();
        QVector<bool> newRow;
        for (auto mxitem : mxRow){
            newRow.append(mxitem.toBool());
        }
        matrix.append(newRow);
    }
    */
}

void NodeManager::write(QJsonObject &json) const{
    /*
    QJsonArray mxArray;
    for (auto &row : matrix) {
        QJsonArray mxRow;
        for (auto &item : row){
            mxRow.append(item);
        }
        mxArray.append(mxRow);
    }
    json["Nodes"] = mxArray;
    */
}

void NodeManager::updateMatrix(int NodeA, int NodeB, Arrow* p_arrow){
    matrix[NodeA][NodeB] = p_arrow;

    showMatrix();
}

void NodeManager::addItem(){
    qDebug() << "item was added:" << matrix.size();
    for (auto &row : matrix) row.append(0);

    matrix.append(QVector<Arrow*>().fill(nullptr,matrix.size()+1));
    showMatrix();
}

void NodeManager::removeNode(int index){
    matrix.remove(index);
    for (auto &row : matrix) row.remove(index);
    showMatrix();
}

int NodeManager::checkExisting(int A, int B){
    showMatrix();

    if (matrix[A][B]){
        if (matrix[B][A]) return aDir::Duplex;
        return aDir::InSimplex;
    } else if (matrix[B][A]) return aDir::OutSimplex;
    return aDir::NotFound;
}

void NodeManager::showMatrix(){
    QTextStream Qcout(stdout);
    Qcout << "\n---NodeMatrix---\n";

    for (auto &row : matrix){
        for (auto column : row){
            Qcout << " " << QVariant(column != nullptr).toInt();
        }
        Qcout << "\n";
    }

    Qcout << "----------------\n";
}

Arrow* NodeManager::getArrow(int NodeA, int NodeB){
    return matrix[NodeA][NodeB];
}
