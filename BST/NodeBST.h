// Author: Noor Eyad
// Created on 5/3/2023.
// ID: 20210499

#ifndef BST_AVL_HEAP_TREES_NODEBST_H
#define BST_AVL_HEAP_TREES_NODEBST_H

#include "../Student.h"

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


#endif //BST_AVL_HEAP_TREES_NODEBST_H
