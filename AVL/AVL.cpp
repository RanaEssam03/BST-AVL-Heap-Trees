//
// Created by Rana Essam on 5/2/2023.
//

#include "AVL.h"

Node *AVL::getRoot() const {
    return root;
}

void AVL::setRoot(Node *r) {
    this->root = r;
}

int AVL::height(struct Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

Node* AVL::insert(Node* node, const Student& info ) {

    if(node == nullptr){
        Node*  newNode = new Node();
        newNode->info = info;
        return  newNode;
    }
    if(node->info < info){
        node->rightChild = insert(node->rightChild, info);
    }
    else{
        node->leftChild = insert(node->leftChild, info);
    }

    node->height = 1 + max(height(node->leftChild), height(node->rightChild));

    int bF = getBFactor(node);

    if(bF <-1 && node->info <info){
//        rotateLeft()
            //TODO
    }
    if(bF > 1 && node->info > info){
//        rotateRight()
        //TODO
    }
    if(bF < -1 && node->info > info){
//        rotateLeft()
//            rotateRight()
        //TODO
    }
    if(bF >1 && node->info < info){
//            rotateRight()
//            rotateLeft()
            //TODO

    }
    return node;


}

void AVL::remove(const Student& student) {

}

void AVL::search(const Student& student) {

}

void AVL::print() {

}

int AVL::getBFactor(Node *node) {
   int r= 0, l = 0;
   if(node == nullptr){
       return 0;
   }
   if(node->leftChild != nullptr){
       l = node->leftChild->height;
   }
   if(node->rightChild != nullptr){
       r = node->rightChild->height;
   }
    return r-l;
}
