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



Node* AVL::insert(Node* & node,  Student info ) {

    if(node == nullptr){
        Node*  newNode = new Node();
        newNode->info = info;
        node = newNode;
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

    if(bF <-1 && node->rightChild->info <info){
        node = rotateLeft(node);

    }
    if(bF > 1 && node->leftChild->info > info){

        node = rotateRight(node);

    }
    if(bF < -1 && node->rightChild->info > info){


        node->rightChild =   rotateRight(node->rightChild);
        node=  rotateLeft(node);

    }
    if(bF >1 && node->leftChild->info < info){

        node =rotateRight(node->leftChild);
        node= rotateLeft(node);

    }
    return node;


}

Node* AVL::rotateLeft(Node *&node) {
    Node * right = node->rightChild;
    Node * leftOfR= right->leftChild;

    right->leftChild = node;
    node->rightChild = leftOfR;

    node->height = max(height(node->leftChild),
                       height(node->rightChild)) + 1;

    right->height = max(height(right->leftChild),
                       height(right->rightChild)) + 1;
    return right;

}



Node* AVL::rotateRight(Node * & node) {
    Node * left = node->leftChild;
    Node * rightOfL= left->rightChild;
    left->rightChild = node;
    node->leftChild = rightOfL;

    node->height = max(height(node->leftChild),
                    height(node->rightChild)) + 1;

    left->height = max(height(left->leftChild),
                    height(left->rightChild)) + 1;

    return left;
}

Node* getMinNode(Node* node){


}


void AVL::remove(const Student& student, Node* node) {

}

Node* AVL::search(int id, Node* node) {
    if(node != nullptr){
        if(node->info.id == id){
            return node;
        }
         search(id, node->rightChild);
         search(id, node->leftChild);
    }

    return nullptr;

}

void AVL::print(Node* node) {
    if(node != nullptr){
        std::cout << node->info.gpa << " ";
        print(node->leftChild);
        print(node->rightChild);
    }
}

int AVL::getBFactor(Node *node) {

    return height(node->leftChild)- height(node->rightChild);
}
