//
// Created by Noor on 5/3/2023.
//

#include "BST.h"

void BST::addStudent(Student& student) {
    node* newNode = new node(student);
    if (root == nullptr){
        root = newNode;
        return;
    }
    node* current = root;
    node* pointer = nullptr;
    while (current != nullptr){
        pointer = current;
        if (newNode->info.gpa < current->info.gpa){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    if (newNode->info.gpa < pointer->info.gpa){
        pointer->left = newNode;
        newNode->parent = pointer;
    }
    else{
        pointer->right = newNode;
        newNode->parent = pointer;
    }
}
node* BST::minValueNode(node* pointer){
    node* current = pointer;
    while (current != nullptr && current->left != nullptr){
        current = current->left;
    }
    return current;
}
node* BST::removeStudent(int ID, node* pointer) {
    if (search(ID, getRoot()) == nullptr){
        return nullptr;
    }
    if (pointer == nullptr){
        return pointer;
    }
    if (ID < pointer->info.id){
        pointer->left = removeStudent(ID, pointer->left);
    }
    else if (ID > pointer->info.id){
        pointer->right = removeStudent(ID, pointer->right);
    }
    else{
        if (pointer->left == nullptr && pointer->right == nullptr){
            node* temp = pointer->right;
            free(pointer);
            cout << "Student removed\n";
            return temp;
        }
        else if (pointer->left == nullptr){
            node* temp = pointer->right;
            free(pointer);
            cout << "Student removed\n";
            return temp;
        }
        else if (pointer->right == nullptr){
            node* temp = pointer->left;
            free(pointer);
            cout << "Student removed\n";
            return temp;
        }
        node* temp = minValueNode(pointer->right);
        pointer->info = temp->info;
        pointer->right = removeStudent(temp->info.id, pointer->right);
    }
    return pointer;
}
node* BST::search(int ID, node* pointer) {
    if (pointer == nullptr){
        return nullptr;
    }
    if (ID < pointer->info.id){
        return search(ID, pointer->left);
    }
    else if (ID > pointer->info.id){
        return search(ID, pointer->right);
    }
    if (ID == pointer->info.id){
        return pointer;
    }
}
node* BST::getRoot(){
    return root;
}
void BST::print(node* node) {
    if (root == nullptr){
        cout << "Tree is empty.\n";
        return;
    }
    if (node == nullptr){
        return;
    }
    print(node->left);
    cout << node->info;
    print(node->right);
}

int main(){
    Student s1("noor", 1, 3.2, "CS");
    Student s2("noor", 2, 3.2, "CS");
    Student s3("noor", 3, 3.2, "CS");
    Student s4("noor", 4, 3.2, "CS");
    Student s5("noor", 5, 3.2, "CS");
    Student s6("noor", 6, 3.2, "CS");
    Student s7("noor", 7, 3.2, "CS");
    BST v{};
    v.addStudent(s1);
    v.addStudent(s2);
    v.addStudent(s3);
    v.addStudent(s4);
    v.addStudent(s5);
    v.addStudent(s6);
    v.addStudent(s7);
    v.print(v.getRoot());
    node* n = v.search(3, v.getRoot());
    if (n!= nullptr){
        cout << "Student Found.\n";
        cout << n->info;
    }else{
        cout << "Student not found.\n";
    }
    node* nn = v.removeStudent(2, v.getRoot());
    if (nn == nullptr){
        cout << "Student not found.\n";
    }
    v.print(v.getRoot());
    cout << endl;
    Student s8("noor", 8, 3.2, "CS");
    v.addStudent(s8);
    v.print(v.getRoot());
    v.removeStudent(3, v.getRoot());
    v.print(v.getRoot());
    cout << endl;
    v.removeStudent(2, v.getRoot());
    v.removeStudent(1, v.getRoot());
    v.print(v.getRoot());
//    cout << endl;
//    Student s9("noor", 2, 3.2, "CS");
//    v.addStudent(s9);
//    v.print(v.getRoot());
//    cout << endl;
//    Student s10("noor", 1, 3.2, "CS");
//    v.addStudent(s10);
//    v.print(v.getRoot());
//    cout << endl;
}

