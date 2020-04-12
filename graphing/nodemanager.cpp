#include "nodemanager.h"

#include <QQuickItem>

NodeManager::NodeManager(QObject *parent) : QObject(parent)
{
    connect(&node_model, SIGNAL(addItem()), this, SLOT(addItem()));
    connect(&arrow_model, SIGNAL(getNode(int,bool)), &node_model, SLOT(getNode(int,bool)));
    connect(&arrow_model, SIGNAL(checkExisting(int, int)), this, SLOT(checkExisting(int, int)));
    connect(&arrow_model, SIGNAL(updateMatrix(int, int, Arrow*)), this, SLOT(updateMatrix(int, int, Arrow*)));
    connect(&node_model, SIGNAL(removeItem(int)), this, SLOT(removeNode(int)));
    connect(&arrow_model, SIGNAL(getArrow(int,int)), this, SLOT(getArrow(int,int)));
    connect(&node_model, SIGNAL(mergeNodes(Node*,Node*)), this, SLOT(mergeNodes(Node*,Node*)));
    connect(&node_model, SIGNAL(updateBindings(int&)), this, SLOT(updateBindings(int&)));
    connect(&node_model, SIGNAL(removeBindings(int&)), this, SLOT(removeBindings(int&)));
    connect(&arrow_model, SIGNAL(showMatrix()), this, SLOT(showMatrix()));
}

NodeManager::~NodeManager(){

}

void NodeManager::newFile(){
    //clear all data
    matrix.clear();
    filePath.clear();

    //emit dataChanged();
}

void NodeManager::removeArrow(int arrowID){
    Arrow *arrow = arrow_model.arrowList[arrowID];

    if (matrix[arrow->A->index][arrow->B->index] != nullptr){
        matrix[arrow->A->index][arrow->B->index] = nullptr;
    }
    if (matrix[arrow->B->index][arrow->A->index] != nullptr){
        matrix[arrow->B->index][arrow->A->index] = nullptr;
    }
}

void NodeManager::mergeArrows(int &FromID, int &ToID, int &i){
    if (ToID == i) return;

    int arrowDiractionFrom = checkExisting(FromID,i);
    int arrowDiractionTo = checkExisting(ToID,i);

    switch (arrowDiractionFrom) {
    case aDir::Duplex:
        switch (arrowDiractionTo) {
        case aDir::Duplex:{
            qDebug() << "[Duplex Duplex]";
            arrow_model.remove(matrix[FromID][i]->index,false);
            break;
        }case aDir::InSimplex:{
            qDebug() << "[Duplex InSimplex]";
            arrow_model.remove(matrix[ToID][i]->index,false);

            auto *arrow = matrix[FromID][i];
            arrow->A = node_model.nodeList[ToID];
            arrow->B = node_model.nodeList[i];
            matrix[ToID][i] = arrow;
            matrix[i][ToID] = arrow;
            break;
        }case aDir::OutSimplex:{
            qDebug() << "[Duplex OutSimplex]";
            arrow_model.remove(matrix[i][ToID]->index,false);

            auto *arrow = matrix[i][FromID];
            arrow->A = node_model.nodeList[ToID];
            arrow->B = node_model.nodeList[i];
            matrix[ToID][i] = arrow;
            matrix[i][ToID] = arrow;
            break;
        }default:{
            qDebug() << "[Duplex NF]";
            auto *arrow = matrix[i][FromID];
            arrow->A = node_model.nodeList[ToID];
            arrow->B = node_model.nodeList[i];
            matrix[ToID][i] = arrow;
            matrix[i][ToID] = arrow;
            break;
        }
        }
        break;
    case aDir::InSimplex:
        switch (arrowDiractionTo) {
        case aDir::Duplex:{
            qDebug() << "[InSimplex Duplex]";
            arrow_model.remove(matrix[FromID][i]->index,false);
            break;
        }case aDir::InSimplex:{
            qDebug() << "[InSimplex InSimplex]";
            Arrow* arrow = matrix[FromID][i];
            arrow_model.remove(arrow->index,false);
            break;
        }case aDir::OutSimplex:{
            qDebug() << "[InSimplex OutSimplex]";
            arrow_model.remove(matrix[FromID][i]->index,false);

            Arrow* arrow = matrix[i][ToID];
            arrow->bidirectional = true;
            matrix[ToID][i] = arrow;

            auto ix = arrow_model.index(arrow->index);
            emit arrow_model.dataChanged(ix,ix,{aRoles::bDir});
            break;
        }default:{
            qDebug() << "[InSimplex NF]";
            Arrow* arrow = matrix[FromID][i];
            arrow->A = node_model.nodeList[ToID];
            matrix[ToID][i] = arrow;
            break;
        }
        }
        break;
    case aDir::OutSimplex:
        switch (arrowDiractionTo) {
        case aDir::Duplex:{
            qDebug() << "[OutSimplex Duplex]";
            arrow_model.remove(matrix[i][FromID]->index,false);
            break;
        }case aDir::InSimplex:{
            qDebug() << "[OutSimplex InSimplex]";
            arrow_model.remove(matrix[i][FromID]->index,false);

            Arrow* arrow = matrix[ToID][i];
            arrow->bidirectional = true;
            matrix[i][ToID] = arrow;

            auto ix = arrow_model.index(arrow->index);
            emit arrow_model.dataChanged(ix,ix,{aRoles::bDir});
            break;
        }case aDir::OutSimplex:{
            qDebug() << "[OutSimplex OutSimplex]";
            Arrow* arrow = matrix[i][FromID];
            arrow_model.remove(arrow->index,false);
            break;
        }default:{
            qDebug() << "[OS NF]";
            Arrow* arrow = matrix[i][FromID];
            arrow->B = node_model.nodeList[ToID];
            matrix[i][ToID] = arrow;
            break;
        }
        }
        break;
    default:
        qDebug() << "[NF NF]";
        break;
    }
}

void NodeManager::mergeNodes(Node* From, Node* To){
    showMatrix();

    int i;


    if (matrix[From->index][To->index] != nullptr){
        arrow_model.remove(matrix[From->index][To->index]->index,false);
    } else if (matrix[To->index][From->index] != nullptr){
        arrow_model.remove(matrix[To->index][From->index]->index,false);
    }





    for (i = 0; i < From->index; i++) mergeArrows(From->index,To->index,i);
    for (i++ ; i < matrix.size(); i++) mergeArrows(From->index,To->index,i);

    Arrow* arrow = matrix[From->index][From->index];
    if (arrow){
        Arrow* oldArrow = matrix[To->index][To->index];
        if (oldArrow) delete arrow;
        else{
            arrow->A = To;
            arrow->B = To;
            matrix[To->index][To->index] = arrow;
        }
    }



    node_model.removeNode(From->index,false);

    showMatrix();
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
        for (auto arrow : row){
            if (arrow != nullptr){
                Qcout << " " << QVariant(arrow->index).toString();
            } else Qcout << " -";
        }
        Qcout << "\n";
    }

    Qcout << "----------------\n";
}

Arrow* NodeManager::getArrow(int NodeA, int NodeB){
    return matrix[NodeA][NodeB];
}

void NodeManager::updateBindings(int &nodeA){
    QModelIndex i;

    if (arrow_model.adding){
        i = arrow_model.index(arrow_model.arrowList.size()-1);
        emit arrow_model.dataChanged(i,i,{xxx,yyy,len,alpha});
    }else{
        for (int nodeB = 0; nodeB < matrix.size(); nodeB++){
            if (matrix[nodeA][nodeB] != nullptr){
                i = arrow_model.index(matrix[nodeA][nodeB]->index);
                emit arrow_model.dataChanged(i,i,{xxx,yyy,len,alpha});
            } else if (matrix[nodeB][nodeA] != nullptr){
                i = arrow_model.index(matrix[nodeB][nodeA]->index);
                emit arrow_model.dataChanged(i,i,{xxx,yyy,len,alpha});
            }
        }
    }
}

void NodeManager::removeBindings(int &nodeA){
    for (int nodeB = 0; nodeB < matrix.size(); nodeB++){
        if (matrix[nodeA][nodeB] != nullptr){
            arrow_model.remove(matrix[nodeA][nodeB]->index,true);
        } else if (matrix[nodeB][nodeA] != nullptr){
            arrow_model.remove(matrix[nodeB][nodeA]->index,true);
        }
    }
}
