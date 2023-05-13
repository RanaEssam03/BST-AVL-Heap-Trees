// Created by NourEdin on 4/5/2023

#include <bits/stdc++.h>
#include "../Student.h"
#include "../loadfile.cpp"

using namespace std;

template<class T>
class min_heap
{
private:
    vector<T> arr;
public:
    min_heap(vector<T> arr);
    void min_heapify(int index);
    void build_min_heap();
    void insert(T element);
    T min();
    T extract_min();
    vector<T> heapSort();
    void print(int index);
};

template<class T>
min_heap<T>::min_heap(vector<T> arr)
{
    this->arr = arr;
    build_min_heap();
}

template<class T>
void min_heap<T>::min_heapify(int index)
{
    int l = 2*index;
    int r = 2*index + 1;
    int smallest = index;
    if(l < arr.size() && arr[smallest].gpa > arr[l].gpa)
        smallest = l;

    if(r < arr.size() && arr[smallest].gpa > arr[r].gpa)
        smallest = r;
    
    if(smallest != index){
        swap(arr[smallest], arr[index]);
        min_heapify(smallest);
    }
}

template<class T>
void min_heap<T>::build_min_heap()
{
    for(int i = arr.size()/2; i >= 0; i--){
        min_heapify(i);
    }
}

template<class T>
void min_heap<T>::insert(T element)
{
    int index = arr.size();
    arr.push_back(element);
    while (index > 0 && arr[((index+1)/2)-1].gpa > arr[index].gpa)
    {
        swap(arr[index], arr[((index+1)/2)-1]);
        index = ((index+1)/2)-1;
    }
}

template<class T>
T min_heap<T>::min(){
    try{
        T min = arr[0];
        return min;
    }
    catch(...){
        cout << "heap underflow";
        throw "heap underflow";
    }
}

template<class T>
T min_heap<T>::extract_min(){
    try{
        T min = arr[0];
        swap(arr[0], arr[arr.size()-1]);
        arr.pop_back();
        min_heapify(0);
        return min;
    }
    catch(...){
        cout << "heap underflow";
        throw "heap underflow";
    }
}

template<class T>
vector<T> min_heap<T>::heapSort(){
    vector<T> tmp = arr;
    vector<T> sorted;
    while(!arr.empty()){
        T min = this->extract_min();
        sorted.push_back(min);
    }
    arr = tmp;
    return sorted;
}

template<class T>
void min_heap<T>::print(int index){
    cout << arr[index-1] << ' ';

    if((index*2)-1 < arr.size())
        cout << arr[(index*2)-1] << ' ';

    if((index*2) < arr.size())
        cout << arr[(index*2)] << ' ';

    cout << endl;

    if((index*2)-1 < arr.size())
        print((index*2));

    if((index*2) < arr.size())
        print((index*2)+1);
}


int startMinHeap(){
    vector<Student> students = loadfile();
    min_heap<Student> heap(students);
    while (true)
    {
        cout << "Choose one of the following options:" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Print All (sorted by gpa)" << endl;
        cout << "3. Return to main menu" << endl;
        int choice;
        cin >> choice;
        string name, dep;
        int id;
        float gpa;
        switch (choice)
        {
        case 1:
            cin.ignore();
            cout << "id: ";
            cin >> id;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "GPA: ";
            cin >> gpa;
            cout << "Department: ";
            cin >> dep;
            cout << endl; 
            heap.insert(Student(name, gpa, id, dep));
            break;
        
        case 2:
            students = heap.heapSort();
            for(auto s: students)
                cout << s << endl;
            cout << endl;
            break;
        case 3:
            return 0;
        
        default:
            break;
        }
    }
    return 0;
}