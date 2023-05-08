//
// Created by Rana Essam on 5/2/2023.
//

#include "AVL.h"

Node *getMinNode(Node *node);

int getBFactor(Node *node);


int height(struct Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}


Node *rotateLeft(Node *&y) {
    Node *x = y->rightChild;

    Node *tmp = x->leftChild;

    x->leftChild = y;
    y->rightChild = tmp;

    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = max(height(y->leftChild), height(y->rightChild)) + 1;

    return x;
}


Node *rotateRight(Node *&y) {
    Node *x = y->leftChild;
    Node *tmp = x->rightChild;

    x->rightChild = y;
    y->leftChild = tmp;

    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = max(height(y->leftChild), height(y->rightChild)) + 1;

    return x;
}


Node *remove(int id, Node *root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (id < root->info.id) {
        root->leftChild = remove(id, root->leftChild);
    } else if (id > root->info.id) {
        root->rightChild = remove(id, root->rightChild);
    } else {
        if (!root->leftChild || !root->rightChild) {
            Node *tmp = root->leftChild ? root->leftChild : root->rightChild;
            if (tmp == nullptr) {
                tmp = root;
                root = nullptr;
            } else {
                *root = *tmp;
            }
            cout << "student removed\n";
            free(tmp);
        } else {
            Node *min = getMinNode(root->rightChild);
            root->info = min->info;
            root->rightChild = remove(min->info.id, root->rightChild);
        }


    }
    if (root == nullptr) {
        return root;
    }

    root->height = 1 + max(height(root->leftChild), height(root->rightChild));

    int bf = getBFactor(root);

    if (bf > 1) {
        if (getBFactor(root->leftChild) >= 0)
            return rotateRight(root);
        else {
            root->leftChild = rotateLeft(root->leftChild);
            return rotateRight(root);
        }
    } else if (bf < -1) {
        if (getBFactor(root->rightChild) <= 0)
            return rotateLeft(root);
        else {
            root->rightChild = rotateRight(root->rightChild);
            return rotateLeft(root);
        }
    }
    return root;
}


Node *insert(Node *node, Node *parent, Student info) {

    if (node == nullptr) {
        Node *newNode = new Node();
        newNode->info = info;
        return newNode;
    }

    if (node->info.id < info.id) {
        node->rightChild = insert(node->rightChild, node, info);
    } else if (node->info.id > info.id) { //    unique values only
        node->leftChild = insert(node->leftChild, node, info);
    }

    node->height = 1 + max(height(node->leftChild), height(node->rightChild));

    int bF = getBFactor(node);

    if (bF < -1 && node->rightChild->info.id < info.id) {
        node = rotateLeft(node);

    } else if (bF > 1 && node->leftChild->info.id >= info.id) {
        node = rotateRight(node);
    } else if (bF < -1 && node->rightChild->info.id >= info.id) {
        node->rightChild = rotateRight(node->rightChild);
        return rotateLeft(node);
    } else if (bF > 1 && node->leftChild->info.id < info.id) {
        node->leftChild = rotateLeft(node->leftChild);
        return rotateRight(node);
    }
    return node;

}


void print(Node *node) { // in order print to get the data sorted by id
    if (node != nullptr) {
        print(node->leftChild);
        std::cout << node->info.id << " ";
        print(node->rightChild);
    }
}

int getBFactor(Node *node) {

    return height(node->leftChild) - height(node->rightChild);
}


Node *getMinNode(Node *node) { // to get the successor
    if (node == nullptr) {
        return nullptr;
    }
    if (node->leftChild == nullptr) {
        return node;
    }
    return getMinNode(node->leftChild);
}


int main() {

    Node *root = nullptr;
    root = insert(root, nullptr, Student("Rana", 22, 40, "cs"));
    root = remove(40, root);

    root = insert(root, nullptr, Student("Rana", 22, 20, "cs"));

    root = insert(root, nullptr, Student("Rana", 22, 6, "cs"));

    root = insert(root, nullptr, Student("Rana", 22, 2, "cs"));


    root = insert(root, nullptr, Student("Rana", 22, 5, "cs"));

    root = remove(5, root);
    root = insert(root, nullptr, Student("Rana", 22, 3, "cs"));

    root = insert(root, nullptr, Student("Rana", 22, 8, "cs"));
    root = remove(2, root);
    root = insert(root, nullptr, Student("Rana", 22, 1, "cs"));
    root = insert(root, nullptr, Student("Rana", 22, 99, "cs"));

    root = remove(20, root);
    root = remove(1, root);
    root = remove(3, root);
    root = remove(8, root);
    root = remove(40, root);

    root = remove(99, root);
    root = remove(6, root);
    root = insert(root, nullptr, Student("Rana", 22, 99, "cs"));
    root = insert(root, nullptr, Student("Rana", 22, 99, "cs"));
    print(root);
}
