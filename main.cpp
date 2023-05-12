///// @author Nour El-din Ahmed 20210430
///// @author Noor Eyad 20210499
///// @authors Rana Essam 20210133
///// date 5/2/2023..
//
//#include <bits/stdc++.h>
//
#include "AVL.cpp"


int main(){

    AVL tree;
    tree.insertByInfo( Student("Rana", 22, 40, "cs"));
    tree.insertByInfo(Student("Rana", 22, 2, "cs"));
    tree.removeById(40);
    tree.printStudents();
}
