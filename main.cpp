/// @author Nour El-din Ahmed 20210430
/// @author Noor Eyad 20210499
/// @authors Rana Essam 20210133
/// date 5/2/2023..

#include <bits/stdc++.h>
#include "AVL.h"
using namespace std;

int main(){
    AVL t;
    Node * root = t.getRoot();
    t.insert(root, nullptr,  Student("Rana", 22, 40, "cs"));
    t.insert(root, nullptr,  Student("Rana", 22, 20, "cs"));
    t.insert(root, nullptr,  Student("Rana", 22, 10, "cs"));
    t.print(t.getRoot());
    cout << endl;
    t.insert(root, nullptr,  Student("Rana", 22, 5, "cs"));
    t.insert(root, nullptr,  Student("Rana", 22, 7, "cs"));

    t.print(t.getRoot());
    t.remove(10);
    cout << endl;
    t.print(t.getRoot());

}


