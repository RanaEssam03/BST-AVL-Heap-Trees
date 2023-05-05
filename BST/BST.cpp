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
//void BST::removeStudent(int ID) {
//    if (root == nullptr){
//        cout << "There are no students in the list.\n";
//        return;
//    }
//    if (root->info.id == ID){
//
//    }
//    node* current = root;
//
//}
void BST::search(int ID) {
    
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
    cout << node->info;
    print(node->left);
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
//    v.removeStudent(2);
    v.print(v.getRoot());
}

