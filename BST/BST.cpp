// Author: Noor Eyad
// Created on 5/3/2023.
// ID: 20210499

#include "BST.h"

void BST::addStudent(Student student) {
    node* newNode = new node(student);
    if (root == nullptr){
        root = newNode;
        studentsPerDepartment[newNode->info.dep]++;
        return;
    }
    node* current = root;
    node* pointer = nullptr;
    while (current != nullptr){
        pointer = current;
        if (newNode->info.id < current->info.id){
            current = current->left;
        }
        else{
            current = current->right;
        }
    }
    if (newNode->info.id < pointer->info.id){
        pointer->left = newNode;
        newNode->parent = pointer;
        studentsPerDepartment[newNode->info.dep]++;
    }
    else{
        pointer->right = newNode;
        newNode->parent = pointer;
        studentsPerDepartment[newNode->info.dep]++;
    }
}
node* BST::minValueNode(node* pointer){
    node* current = pointer;
    while (current != nullptr && current->left != nullptr){
        current = current->left;
    }
    return current;
}
node* BST::removeStudent(int ID, node* pointer, bool f) {
    if (search(ID, getRoot()) == nullptr){
        cout << "Student not found.\n";
        return nullptr;
    }
    else{
        if (!f){
            cout << "Student found.\n";
            f = true;
        }
    }
    if (pointer == nullptr){
        return pointer;
    }
    if (ID < pointer->info.id){
        pointer->left = removeStudent(ID, pointer->left, f);
    }
    else if (ID > pointer->info.id){
        pointer->right = removeStudent(ID, pointer->right, f);
    }
    else{
        if (pointer->left == nullptr && pointer->right == nullptr){
            node* temp = pointer->right;
            if(root == pointer) root = nullptr;
            cout << pointer->info;
            studentsPerDepartment[pointer->info.dep]--;
            free(pointer);
            cout << "Student removed\n";
            return temp;
        }
        else if (pointer->left == nullptr){
            node* temp = pointer->right;
            if(root == pointer) root = temp;
            cout << pointer->info;
            studentsPerDepartment[pointer->info.dep]--;
            free(pointer);
            cout << "Student removed\n";
            return temp;
        }
        else if (pointer->right == nullptr){
            node* temp = pointer->left;
            if(root == pointer) root = temp;
            cout << pointer->info;
            studentsPerDepartment[pointer->info.dep]--;
            free(pointer);
            cout << "Student removed\n";
            return temp;
        }
        node* temp = minValueNode(pointer->right);
        pointer->info = temp->info;
        pointer->right = removeStudent(temp->info.id, pointer->right, f);
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
    return nullptr;
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
void BST::printStudentsPerDepartment(){
    cout << "\nStudents per Departments:\n";
    for (const auto& item : studentsPerDepartment){
        cout << item.first << " " << item.second << " Students\n";
    }
}
void BST::startBST(){
    vector<Student>students = loadfile();
    for(const auto& std: students){
        addStudent(std);
    }
    while (true){
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
                addStudent(Student(name, gpa, id, dep));
                cout << "The student is added\n";
                break;
            }
            case 2: {
                int id;
                bool f = false;
                cout << "ID: "; cin>> id;
                removeStudent(id, getRoot(), f);
                break;
            }
            case 3:{
                int id ;
                cout << "ID: "; cin >>id;
                search(id, getRoot());
                break;
            }
            case 4: {
                print(getRoot());
                printStudentsPerDepartment();
                break;
            }
            default:{
                return;
            }
        }
    }
}

