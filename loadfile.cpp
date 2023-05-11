#ifndef LOAD_FILE
#define LOAD_FILE

#include <bits/stdc++.h>
#include "Student.h"

using namespace std;

vector<Student> loadfile(){
    vector<Student> students;
    ifstream fs("../input.txt");
    int n;
    fs >> n;
    for(int i = 0; i < n; i++){
        string name, dep;
        int id;
        float gpa;
        fs >> id;
        fs.ignore();
        getline(fs, name);
        fs >> gpa >> dep;
        students.push_back(Student(name, id, gpa, dep));
    }
    fs.close();
    return students;
}

#endif