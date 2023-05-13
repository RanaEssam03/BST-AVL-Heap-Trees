// Author: Noor Eyad
// Created on 5/3/2023.
// ID: 20210499

#include "node.h"
#include <vector>
#include "../loadfile.cpp"

#ifndef BST_AVL_HEAP_TREES_BST_H
#define BST_AVL_HEAP_TREES_BST_H

class BST{
private:
    node* root;
public:
    void addStudent(Student student);
    node* removeStudent(int ID, node* pointer);
    node* search(int ID, node* pointer);
    void print(node* node);
    node* getRoot();
    node* minValueNode(node* pointer);

    void startBST();
};


#endif //BST_AVL_HEAP_TREES_BST_H
