// Author: Noor Eyad
// Created on 5/3/2023.
// ID: 20210499

#include "../Student.h"

#ifndef BST_AVL_HEAP_TREES_NODE_H
#define BST_AVL_HEAP_TREES_NODE_H

struct node{
    node* left;
    node* right;
    node* parent;
    Student info;
    node(){
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    node(Student student){
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        info = student;
    }
};

#endif //BST_AVL_HEAP_TREES_NODE_H
