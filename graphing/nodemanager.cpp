#include "nodemanager.h"

NodeManager::NodeManager()
{
    connect(this, SIGNAL(matrixChanged()),
         this, SLOT (map()));
}

NodeManager::~NodeManager(){

}

QList<int> NodeManager::matrix(){

}

int NodeManager::size(){

}

void NodeManager::setMatrix(QList<int> newMatrix){

}

void NodeManager::setSize(int newSize){

}


void NodeManager::matrixChanged(){

}

void NodeManager::sizeChanged(){

}

void NodeManager::createFile(){
    // очищает содержимое рабочей области
    // убирает файл при наличии
    //
}

void NodeManager::openFile(){

}

void NodeManager::saveFile(){

}

void NodeManager::saveAsFile(){

}
