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
    connect(&arrow_model, SIGNAL(updateNode(int,int,int)), &node_model, SLOT(update(int,int,int)));
    connect(&arrow_model, SIGNAL(selectNode(int,bool)), &node_model, SLOT(selectNode(int,bool)));
    connect(&arrow_model, SIGNAL(cleared()), this, SLOT(readFile()));
    connect(&arrow_model, SIGNAL(checkLoopExisting(int)), this, SLOT(checkLoopExisting(int)));
}

NodeManager::~NodeManager(){
    clear(false);
}

void NodeManager::copy(){
    buffer.tmp_coord_list.clear();
    buffer.tmp_arrow_list.clear();

    buffer.cx = 0;
    buffer.cy = 0;

    QHash<int,int> keys;
    keys.reserve(node_model.selected.size()-1);
    int counter = 0;

    for (auto A : node_model.selected){
        buffer.cx += A->xc;
        buffer.cy += A->yc;

        keys[A->index] = counter++;
        buffer.tmp_coord_list.append({A->xc, A->yc});
    }

    buffer.cx /= node_model.selected.size();
    buffer.cy /= node_model.selected.size();

    for (auto A : node_model.selected){
        for (auto B : node_model.selected){
            int dir = checkExisting(A->index,B->index);

            if (dir == aDir::InSimplex){
                iArrow a;
                a.A = keys[A->index];
                a.B = keys[B->index];

                a.bidirectional = false;
                buffer.tmp_arrow_list.append(a);
            }else if (dir == aDir::Duplex){
                if (A->index <= B->index){
                    iArrow a;
                    a.A = keys[A->index];
                    a.B = keys[B->index];

                    a.bidirectional = true;
                    buffer.tmp_arrow_list.append(a);
                }
            }
        }
    }
}

void NodeManager::paste(int mouseX, int mouseY){
    int offset = matrix.size();

    for (auto node : buffer.tmp_coord_list){
        node_model.addNode(node.first - buffer.cx + mouseX, node.second - buffer.cy + mouseY);
    }

    for (auto arrow : buffer.tmp_arrow_list){
        if (arrow.A == arrow.B){
            arrow_model.createLoop(arrow.A + offset);
        }else{
            arrow_model.bindA(arrow.A + offset);
            arrow_model.bindB(arrow.B + offset, false);

            if (arrow.bidirectional){
                auto &arrow = arrow_model.arrowList.last();
                arrow->bidirectional = true;
                auto ix = arrow_model.index(arrow->index);
                emit arrow_model.dataChanged(ix,ix,{aRoles::bDir});
            }
        }


    }
}

void NodeManager::clear(bool anim){
    node_model.selected.clear();
    for (auto &node : node_model.nodeList){
        node_model.removeNode(node->index, anim);
    }
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
            arrow_model.remove(matrix[FromID][i]->index,false);
            break;
        }case aDir::InSimplex:{
            arrow_model.remove(matrix[ToID][i]->index,false);

            auto *arrow = matrix[FromID][i];
            arrow->A = node_model.nodeList[ToID];
            arrow->B = node_model.nodeList[i];
            matrix[ToID][i] = arrow;
            matrix[i][ToID] = arrow;
            break;
        }case aDir::OutSimplex:{
            arrow_model.remove(matrix[i][ToID]->index,false);

            auto *arrow = matrix[i][FromID];
            arrow->A = node_model.nodeList[ToID];
            arrow->B = node_model.nodeList[i];
            matrix[ToID][i] = arrow;
            matrix[i][ToID] = arrow;
            break;
        }default:{
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
            arrow_model.remove(matrix[FromID][i]->index,false);
            break;
        }case aDir::InSimplex:{
            Arrow* arrow = matrix[FromID][i];
            arrow_model.remove(arrow->index,false);
            break;
        }case aDir::OutSimplex:{
            arrow_model.remove(matrix[FromID][i]->index,false);

            Arrow* arrow = matrix[i][ToID];
            arrow->bidirectional = true;
            matrix[ToID][i] = arrow;

            auto ix = arrow_model.index(arrow->index);
            emit arrow_model.dataChanged(ix,ix,{aRoles::bDir});
            break;
        }default:{
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
            arrow_model.remove(matrix[i][FromID]->index,false);
            break;
        }case aDir::InSimplex:{
            arrow_model.remove(matrix[i][FromID]->index,false);

            Arrow* arrow = matrix[ToID][i];
            arrow->bidirectional = true;
            matrix[i][ToID] = arrow;

            auto ix = arrow_model.index(arrow->index);
            emit arrow_model.dataChanged(ix,ix,{aRoles::bDir});
            break;
        }case aDir::OutSimplex:{
            Arrow* arrow = matrix[i][FromID];
            arrow_model.remove(arrow->index,false);
            break;
        }default:{
            Arrow* arrow = matrix[i][FromID];
            arrow->B = node_model.nodeList[ToID];
            matrix[i][ToID] = arrow;
            break;
        }
        }
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
        if (oldArrow) arrow_model.remove(arrow->index,false);
        else{
            arrow->A = To;
            arrow->B = To;
            matrix[To->index][To->index] = arrow;
        }
    }

    node_model.removeNode(From->index,false,false);

    showMatrix();
}

bool NodeManager::openFile(){
    file.setFileName(QFileDialog::getOpenFileName(0, "file path", "", "*.json"));

    if (!file.open(QIODevice::ReadOnly)) return false;

    if (arrow_model.arrowList.size() > 0) {
        arrow_model.checkSize = true;
        clear();
    }
    else readFile();
    return true;
}

void NodeManager::readFile(){
    QByteArray data = file.readAll();
    QJsonDocument document(QJsonDocument::fromJson(data));
    if (!read(document.object()) && !matrix.isEmpty()) clear();
    file.close();
}

bool NodeManager::saveAsFile(){
    file.setFileName(QFileDialog::getSaveFileName(0, "file path", "", "*.json"));
    return saveFile();
}

bool NodeManager::saveFile(){
    if (!file.open(QIODevice::WriteOnly)) return false;

    QJsonObject data;
    write(data);
    QJsonDocument document(data);
    file.write(document.toJson());
    file.close();

    return true;
}

bool NodeManager::read(const QJsonObject &json){
    auto item = json["size"];
    if (item.isUndefined()) {
        debug("unsupported data");
    }

    int size = json["size"].toInt();

    for (int A = 0; A < size; A++) {
        auto alpha = qDegreesToRadians(360.0/size*A);
        node_model.addNode(ws_Width/2+(ws_Width-2*Node_Radius)/2*qCos(alpha),ws_Height/2+(ws_Height-2*Node_Radius)/2*qSin(alpha));
    }

    for (int A = 0; A < size; A++) {
        auto item = json[QString::number(A)];

        if (item.isUndefined()) {
            debug("unsupported data");
        }

        QJsonArray bindedNodes = item.toArray();

        for (auto B : bindedNodes) {
            if (B.isUndefined()) {
                debug("unsupported data");
            }

            if (A == B.toInt()) arrow_model.createLoop(A);
            else if (auto arrow = matrix[B.toInt()][A]){
                arrow->bidirectional = true;
                auto ix = arrow_model.index(arrow->index);
                emit arrow_model.dataChanged(ix,ix,{aRoles::bDir});
            }else{
                arrow_model.bindA(A);
                arrow_model.bindB(B.toInt(), false);
            }
        }
    }

    return true;
}

void NodeManager::write(QJsonObject &json) const{
    json.insert("size",matrix.size());

    for (int A = 0; A < matrix.size(); A++) {
        QJsonObject nodeList;
        QJsonArray bindingsJArray;
        for (int B = 0; B < matrix.size(); B++) {
            if (matrix[A][B]) bindingsJArray.append(B);
        }
        json.insert(QString::number(A),bindingsJArray);
    }
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

bool NodeManager::checkLoopExisting(int nodeID){
    return matrix[nodeID][nodeID] != nullptr;
}
