//
// Created by Rana Essam on 5/2/2023.
//

#ifndef BST_AVL_HEAP_TREES_AVL_H
#define BST_AVL_HEAP_TREES_AVL_H


#include "Node.h"

class AVL {
private:
     Node * root;
public:
    AVL(){
        root = nullptr;
    }

     Node* insert(Node* node, const Student& info );

    void remove(const Student& student);

    void search(const Student& student);

    void print();

    Node *getRoot() const;

    void setRoot(Node *root);

    int getBFactor(Node* node);

    int height(Node *N);
};


#endif //BST_AVL_HEAP_TREES_AVL_H
