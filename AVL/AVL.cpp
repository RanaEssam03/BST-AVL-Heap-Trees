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



Node* AVL::insert(Node* & node, Node* parent ,  Student info ) {

    if(node == nullptr){
        Node*  newNode = new Node();
        newNode->info = info;
        node = newNode;
        node->parent = parent;
        if(parent == nullptr){
            this->root = node;
        }
        return  newNode;
    }
    if(node->info < info){
        node->rightChild = insert(node->rightChild, node, info);
    }
    else{
        node->leftChild = insert(node->leftChild, node, info);
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
    right->parent = node->parent;
    node->rightChild = leftOfR;
    if(node->parent == nullptr){
        this->root = right;
    }
    node->parent = right;
    if(leftOfR != nullptr){
        leftOfR->parent = node;
    }

    node->height = max(height(node->leftChild),
                       height(node->rightChild)) + 1;

    right->height = max(height(right->leftChild),
                       height(right->rightChild)) + 1;
    return right;

}



Node* AVL::rotateRight(Node * & node) {
    Node * left = node->leftChild;
    Node * rightOfL;

    rightOfL= left->rightChild;

    left->rightChild = node;
    node->leftChild = rightOfL;

    left->parent = node->parent;

    if(node->parent == nullptr){
        cout << "heree root";
        this->root = left;
    }
    node->parent = left;
    if(rightOfL!= nullptr){
        rightOfL->parent = node;
    }

    node->height = max(height(node->leftChild),
                    height(node->rightChild)) + 1;

    left->height = max(height(left->leftChild),
                    height(left->rightChild)) + 1;

    return left;
}

//Node* getMinNode(Node* node){
//
//
//}


void AVL::remove(const Student& student, Node* node) {

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


Node* AVL::getMinNode(Node* node){
    if (node->leftChild == nullptr){
        return node;
    }
    return getMinNode(node->leftChild);
}


void AVL::remove(int id) {
    Node * student = search(id, getRoot());
    if(student == NULL){
        cout << "student not found\n";
        return;
    }
    Node* parent = student->parent;
    Node* tmp;
    cout << "Student found";
    if((!student->leftChild && !student->rightChild)){
            if(student > parent){
                parent->rightChild = nullptr;
            }
            else{
                parent->leftChild = nullptr;
            }
            free(student);
            tmp= parent;
    }
    else if((student->leftChild && student->rightChild)){

        Node* min = getMinNode(student->rightChild); // to get inorderSuccessor
//        if(min!= nullptr && min->parent != nullptr)
//            min->parent->leftChild= nullptr;

        cout << "here= " << min->info.gpa << endl;
        tmp = min->parent;


        student->info = min->info;
        parent = min->parent;
        if(min->rightChild){
            min->parent->rightChild = min->rightChild;
        }
        ::free(min);

    }
    else{
        tmp = student->parent;

        if(student->leftChild){
            if(student> parent)
                parent->rightChild = student->leftChild;
            else
                parent->leftChild = student->leftChild;

            student->leftChild->parent = parent;
            free(student);
        }
        else{
            if(student > parent)
                parent->rightChild = student->rightChild;
            else
                parent->leftChild = student->rightChild;

            student->rightChild->parent = parent;
            free(student);
        }
    }
    Node* current = tmp;
    while(current!= nullptr){
        current->height = max(height(current->rightChild), height(current->leftChild))+1;
        current= current->parent;
    }
    while(tmp != nullptr){
       if( update(tmp)){
           break;
       }
        tmp = tmp->parent;

    }

}

bool  AVL::update(Node* & node){
    int bF = getBFactor(node);
    if(bF >1){
        rotateRight(node);
        return true;
    }
    else if(bF <-1){
        rotateLeft(node);
        return true;
    }
    return false;

}

Node* AVL::search(int id, Node* node) {
   if(node == nullptr || id == node->info.gpa){
       return node;
   }
   if(id < node->info.gpa){
       return search(id, node->leftChild);
   }
   else{
       return search(id, node->rightChild);
   }


}