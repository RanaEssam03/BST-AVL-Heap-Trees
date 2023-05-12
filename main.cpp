///// @author Nour El-din Ahmed 20210430
///// @author Noor Eyad 20210499
///// @authors Rana Essam 20210133
///// date 5/2/2023..

#include "AVL/AVL.cpp"
#include "max_heap/max_heap.cpp"
#include "min_heap/min_heap.cpp"

int main(){

    while (true){
       cout << " Choose Data Structure:\n";
       cout <<    "1. BST \n2. AVL  \n3. Min Heap\n4. Max Heap\n5. Exit Program\n";
       cout << "Please pick one option->";
       int option;
       cin >> option;
        switch (option) {
            case 1:{
                //TODO BST menu
                break;
            }
            case 2:{
                AVL tree;
                tree.startAVL();
                break;
            }
            case 3:{
                startMinHeap();
                break;
            }
            case 4:{
                startMaxHeap();
                break;
            }
            case 5:{
                return 0 ;
            }


        }

    }
}
