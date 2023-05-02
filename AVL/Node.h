//
// Created by Rana Essam on 5/2/2023.
//

#ifndef BST_AVL_HEAP_TREES_NODE_H
#define BST_AVL_HEAP_TREES_NODE_H

#include "../Student.h"


struct Node {
    Node * leftChild;
    Node * rightChild;
    Node * parent;
    int height;
    Student info;
    Node(){
        leftChild = nullptr;
        rightChild = nullptr;
        parent = nullptr;
        height = 0;
    }
};


#endif //BST_AVL_HEAP_TREES_NODE_H
