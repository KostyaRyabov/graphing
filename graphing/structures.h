#ifndef STRUCTURES_H
#define STRUCTURES_H

struct Node{
    int xc,yc,rx,ry,index;
};

struct Arrow{
    Node* A;
    Node* B;

    bool bidirectional = false;
    bool destroy = true;
};

enum aDir{
    NotFound = -1,
    InSimplex,
    OutSimplex,
    Duplex
};

#endif // STRUCTURES_H
