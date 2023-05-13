/// @author: Rana Essam
/// @created on  5/2/2023.
/// ID: 20210133

#ifndef BST_AVL_HEAP_TREES_AVL_H
#define BST_AVL_HEAP_TREES_AVL_H


#include "Node.h"

class AVL {
private:
     Node * root;

    int getBFactor(Node* node);

     int height(Node *N);

     Node* rotateLeft(Node *& node);

     Node* rotateRight(Node * &node);

    void print(Node *node);

    Node* search(int id, Node *root);

    Node *getMinNode(Node *node);

    Node *insert(Node *node, Student info);

    Node *remove(int id, Node *root);
public:
    AVL(){
        root = nullptr;
    }

    void printStudents(); //interface function

    void insertByInfo(Student info);//interface function

    void searchById(int id);//interface function

    void removeById(int id);//interface function

    void startAVL();
};


#endif //BST_AVL_HEAP_TREES_AVL_H
