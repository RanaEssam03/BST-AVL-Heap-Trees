//
// Created by Rana Essam on 5/2/2023.
//

#include "AVL.h"

Node* getMinNode(Node* node);
int getBFactor(Node *node);


int height(struct Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}



Node* rotateLeft(Node *&y) {
    Node * x = y->rightChild;

    Node * tmp= x->leftChild;

    x->leftChild = y;
    y->rightChild = tmp;

    x->height = max(height(x->leftChild), height(x->rightChild))+1;
    y->height = max(height(y->leftChild), height(y->rightChild))+1;

    return x;
}



// left = y    t3 = rightOfL z = node
Node* rotateRight(Node * & y) {
    Node* x = y->leftChild;
    Node* tmp = x->rightChild;

    x->rightChild = y;
    y->leftChild = tmp;

    x->height = max(height(x->leftChild), height(x->rightChild))+1;
    y->height = max(height(y->leftChild), height(y->rightChild))+1;

    return x;
}


Node* remove(int id, Node* root){
    if(root == nullptr){
        return nullptr;
    }
    if(id < root->info.id){
        root->leftChild=remove(id, root->leftChild);
    }
    else if (id > root->info.id){
        root->rightChild= remove(id, root->rightChild);
    }
    else{
        if(!root->leftChild || !root->rightChild){
            Node *tmp = root->leftChild ? root->leftChild : root->rightChild;
            if(tmp == nullptr){
                tmp= root;
                root= nullptr;
            }
            else{
                *root = *tmp;
            }
            free(tmp);
        }
        else{
            Node* min = getMinNode(root->rightChild);
            root->info= min->info;
            root->rightChild = remove(min->info.id, root->rightChild);
        }


    }
    if(root== nullptr){
        return root;
    }

    root->height = 1 + max(height(root->leftChild), height(root->rightChild));

    int bf = getBFactor(root);

    if(bf> 1 ){
        if(getBFactor(root->leftChild) >=0 )
            return rotateRight(root);
        else{
            root->leftChild = rotateLeft(root->leftChild);
            return rotateRight(root);
        }
    }
    else if (bf< -1 ){
        if(getBFactor(root->rightChild) <=0 )
            return rotateLeft(root);
        else{
            root->rightChild = rotateRight(root->rightChild);
            return rotateLeft(root);
        }
    }


    return root;
}

Node* insert(Node*  node, Node* parent ,  Student info ) {

    if(node == nullptr){
        Node* newNode = new Node();
        newNode->info = info;
        return  newNode;
    }
    if(node->info.id < info.id){
        node->rightChild = insert(node->rightChild, node, info);
    }
    else{
        node->leftChild = insert(node->leftChild, node, info);
    }

    node->height = 1 + max(height(node->leftChild), height(node->rightChild));

    int bF = getBFactor(node);

    if(bF <-1 && node->rightChild->info.id <info.id){
        node = rotateLeft(node);

    }
    else if(bF > 1 && node->leftChild->info.id >= info.id){

        node = rotateRight(node);

    }
    else if(bF < -1 && node->rightChild->info.id >= info.id){
        node->rightChild =   rotateRight(node->rightChild);
        return   rotateLeft(node);

    }
    else if(bF >1 && node->leftChild->info.id < info.id){

        node ->leftChild =rotateLeft(node->leftChild);
        return  rotateRight(node);

    }
    return node;

}



void print(Node* node) {
    if(node != nullptr){
        print(node->leftChild);
        std::cout << node->info.id << " ";

        print(node->rightChild);
    }
}

int getBFactor(Node *node) {

    return height(node->leftChild)- height(node->rightChild);
}


Node* getMinNode(Node* node){
    if(node== nullptr){
        return nullptr;
    }
    if (node->leftChild == nullptr){
        return node;
    }
    return getMinNode(node->leftChild);
}


bool  update(Node* & node){
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

Node* search(int id, Node* node) {
   if(node == nullptr || id == node->info.id){
       return node;
   }
   if(id < node->info.id){
       return search(id, node->leftChild);
   }
   else{
       return search(id, node->rightChild);
   }
}


int main(){

    Node * root= nullptr;
root=    insert(root, nullptr,  Student("Rana", 22, 40, "cs"));

   root=  insert(root, nullptr,  Student("Rana", 22, 20, "cs"));

    root=insert(root, nullptr,  Student("Rana", 22, 6, "cs"));

    root=insert(root, nullptr,  Student("Rana", 22, 2, "cs"));


    root= insert(root, nullptr,  Student("Rana", 22, 5, "cs"));


    root=insert(root, nullptr,  Student("Rana", 22, 3, "cs"));

    root= insert(root, nullptr,  Student("Rana", 22, 8, "cs"));
    root= insert(root, nullptr,  Student("Rana", 22, 1, "cs"));
    root= insert(root, nullptr,  Student("Rana", 22, 99, "cs"));

    root= remove(20, root);
    print(root);
}
