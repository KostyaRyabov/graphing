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
    connect(&node_model, SIGNAL(removeBindings(Node*)), &arrow_model, SLOT(removeBindings(Node*)));
    connect(&arrow_model, SIGNAL(getArrowListWithNode(int)), this, SLOT(getArrowListWithNode(int)));
    connect(&node_model, SIGNAL(mergeNodes(Node*,Node*)), this, SLOT(mergeNodes(Node*,Node*)));
}

NodeManager::~NodeManager(){

}

void NodeManager::newFile(){
    //clear all data
    matrix.clear();
    filePath.clear();

    //emit dataChanged();
}

void NodeManager::mergeArrows(int &fA, int &fB, int &A, int &B){
    int arrowDiraction1 = checkExisting(fA,fB);
    int arrowDiraction2 = checkExisting(A,B);

    if (arrowDiraction1 == aDir::Duplex){
        if (arrowDiraction2 == aDir::Duplex){
            // удаляем 1е ребро
            arrow_model.remove(matrix[fA][fB]);
        }else if (arrowDiraction2 == aDir::NotFound){
            // указываем в матрице в 2х местах 1е ребро
            matrix[A][B] = matrix[fA][fB];
            matrix[B][A] = matrix[fA][fB];
        }else{
            // указываем в другой позиции (B,A) матрицы 2е ребро
            // удаляем 1е ребро и сообщаем 2му, что он двунаправленный

            arrow_model.remove(matrix[fA][fB]);
            Arrow *arrow = matrix[A][B];
            arrow->bidirectional = true;
            matrix[B][A] = arrow;

            auto index = arrow_model.index(arrow_model.arrowList.indexOf(arrow));
            emit arrow_model.dataChanged(index,index,{arrowListModel::aRoles::bDir});
        }
    } else if (arrowDiraction1 == aDir::InSimplex){
        if (arrowDiraction2 == aDir::OutSimplex || arrowDiraction2 == aDir::Duplex){
            // указываем в другой позиции (A,B) матрицы 2е ребро
            // удаляем 1е ребро и сообщаем 2му, что он двунаправленный

            arrow_model.remove(matrix[fA][fB]);
            Arrow *arrow = matrix[B][A];
            arrow->bidirectional = true;
            matrix[A][B] = arrow;

            auto index = arrow_model.index(arrow_model.arrowList.indexOf(arrow));
            emit arrow_model.dataChanged(index,index,{arrowListModel::aRoles::bDir});
        }else{
            // удаляем 1е ребро

            arrow_model.remove(matrix[fA][fB]);
        }
    } else if (arrowDiraction1 == aDir::OutSimplex){
        if (arrowDiraction2 == aDir::InSimplex || arrowDiraction2 == aDir::Duplex){
            // указываем в другой позиции (B,A) матрицы 2е ребро
            // удаляем 1е ребро и сообщаем 2му, что он двунаправленный

            arrow_model.remove(matrix[fB][fA]);
            Arrow *arrow = matrix[A][B];
            arrow->bidirectional = true;
            matrix[B][A] = arrow;

            auto index = arrow_model.index(arrow_model.arrowList.indexOf(arrow));
            emit arrow_model.dataChanged(index,index,{arrowListModel::aRoles::bDir});
        }else{
            // удаляем 1е ребро

            arrow_model.remove(matrix[fB][fA]);
        }
    }
}

void NodeManager::mergeNodes(Node* From, Node* To){
    qDebug() << "from"<<From->index<<"to"<<To->index;
    showMatrix();

    int i;
    Arrow *arrow, *oldArrow;

    for (i = 0; i < From->index; i++) mergeArrows(From->index,i,To->index,i);
    for (i++ ; i < matrix.size(); i++) mergeArrows(From->index,i,To->index,i);

    arrow = matrix[From->index][From->index];
    if (arrow){
        oldArrow = matrix[To->index][To->index];
        if (oldArrow) delete arrow;
        else{
            arrow->A = To;
            arrow->B = To;
            matrix[To->index][To->index] = arrow;
        }
    }

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

QVector<Arrow*> NodeManager::getArrowListWithNode(int nodeA){
    QVector<Arrow*> arrowList;

    for (int nodeB = 0; nodeB < matrix.size(); nodeB++){
        if (matrix[nodeA][nodeB] != nullptr){
            arrowList.append(matrix[nodeA][nodeB]);
        } else if (matrix[nodeB][nodeA] != nullptr){
            arrowList.append(matrix[nodeB][nodeA]);
        }
    }

    return arrowList;
}
