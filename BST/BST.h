// Author: Noor Eyad
// Created on 5/3/2023.
// ID: 20210499

#include "node.h"

#ifndef BST_AVL_HEAP_TREES_BST_H
#define BST_AVL_HEAP_TREES_BST_H

class BST{
private:
    node* root;
public:
    void addStudent(Student& student);
    void removeStudent(int ID);
    void search(int ID);
    void print(node* node);
    node* getRoot();
};


#endif //BST_AVL_HEAP_TREES_BST_H
