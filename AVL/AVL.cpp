/// @author: Rana Essam
/// @created on  5/2/2023.
/// ID: 20210133

#include "AVL.h"

#include <utility>
#include <vector>
#include "Node.h"
#include "../loadfile.cpp"


int AVL::height(struct Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}


Node *AVL::rotateLeft(Node *&y) {
    Node *x = y->rightChild;

    Node *tmp = x->leftChild;

    x->leftChild = y;
    y->rightChild = tmp;

    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = max(height(y->leftChild), height(y->rightChild)) + 1;

    return x;
}


Node *AVL::rotateRight(Node *&y) {
    Node *x = y->leftChild;
    Node *tmp = x->rightChild;

    x->rightChild = y;
    y->leftChild = tmp;

    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = max(height(y->leftChild), height(y->rightChild)) + 1;

    return x;
}


Node *AVL::remove(int id, Node *root) {
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
            cout << "student is Found";
            cout << root->info;
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


Node *AVL::insert(Node *node, Student info) {

    if (node == nullptr) {
        Node *newNode = new Node();
        newNode->info = info;
        return newNode;
    }

    if (node->info.id < info.id) {
        node->rightChild = insert(node->rightChild, info);
    } else if (node->info.id > info.id) { //    unique values only
        node->leftChild = insert(node->leftChild,  info);
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


void AVL::print(Node *node) { // in order print to get the data sorted by id
    if (node != nullptr) {
        print(node->leftChild);
        std::cout << node->info ;
        print(node->rightChild);
    }
}

int AVL::getBFactor(Node *node) {

    return height(node->leftChild) - height(node->rightChild);
}


Node *AVL::getMinNode(Node *node) { // to get the successor
    if (node == nullptr) {
        return nullptr;
    }
    if (node->leftChild == nullptr) {
        return node;
    }
    return getMinNode(node->leftChild);
}

Node *AVL::search(int id, Node *node) {
    if (node == nullptr || id == node->info.id) {
        return node;
    }
    if (id < node->info.id) {
        return search(id, node->leftChild);
    } else {
        return search(id, node->rightChild);
    }
}

void AVL::removeById(int id) {  //  interface function
    root = remove(id, root);
}

void AVL::searchById(int id) {    // interface function
    Node *ans = search(id, root);
    if (ans != nullptr) {
        cout << "student is found\n";
        cout << ans->info ;
        freqMp[ans->info.dep]--;
    } else {
        cout << "student is not found\n";
    }
}

void AVL::insertByInfo(Student info) {
    freqMp[info.dep]++;// interface function
    root = insert(root, std::move(info));
}


void AVL::printStudents() {   // interface function
    print(root);
   string deps[]= {"CS", "IT" , "DS" , "IS"};
   for(auto dep : deps){
       cout << dep <<" "<<freqMp[dep] << " Students\n";
   }
}

void AVL::startAVL() {
    vector<Student>students = loadfile();
    for(auto std: students){
        insertByInfo(std);
    }
    while (true)
    {
        cout << "\nChoose one of the following options:\n";
        cout << "1. Add student \n";
        cout << "2. Remove student\n";
        cout << "3. Search student\n";
        cout << "4. Print All (sorted by id)\n";
        cout << "5. Return to main menu\n->";
        int option;
        cin >> option;
        switch (option) {
            case 1: {
                string name;
                int id;
                string dep;
                float gpa;
                cout << "id:"; cin >> id;
                cin.ignore();
                cout << "Name: "; getline(cin, name);
                cout << "GPA: "; cin >> gpa;
                cout << "Department: "; cin >> dep;
                transform(dep.begin(), dep.end(), dep.begin(),::toupper);
                insertByInfo(Student(name, gpa, id, dep));
                cout << "The student is added\n";
                break;
            }
            case 2: {
                int id;
                cout << "ID: "; cin>> id;
                removeById(id);
                break;
            }
            case 3:{
                int id ;
                cout << "ID: "; cin >>id;
                searchById(id);
                break;
            }
            case 4: {
                printStudents();
                break;
            }
            default:{
                return;
            }
        }
    }

}

