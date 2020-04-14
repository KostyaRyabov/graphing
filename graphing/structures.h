#ifndef STRUCTURES_H
#define STRUCTURES_H

struct Node{
    int xc,yc,rx,ry,index,lastBlock;
    bool    isSelected = false,
            destroy = true;;
};

struct Arrow{
    Node* A;
    Node* B;

    int index;
    bool    isLooped = false,
            bidirectional = false,
            destroy = true;
};



enum aDir{
    NotFound = -1,
    InSimplex,
    OutSimplex,
    Duplex
};

#endif // STRUCTURES_H
