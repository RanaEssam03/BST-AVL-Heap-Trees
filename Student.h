//
// Created by Rana Essam on 5/2/2023.
//

#ifndef BST_AVL_HEAP_TREES_STUDENT_H
#define BST_AVL_HEAP_TREES_STUDENT_H
#include <iostream>
#include <utility>

using namespace std;
struct Student {
    int id{};
    string name;
    float gpa{};
    string dep;
    Student(string name, int id, float gpa, string dep){
        this->gpa = gpa;
        this->name = name;
        this->id = id;
        this->dep = dep;
    }
    Student()= default;
};


#endif //BST_AVL_HEAP_TREES_STUDENT_H
