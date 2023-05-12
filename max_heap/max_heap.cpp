// Created by NourEdin on 4/5/2023

#include <bits/stdc++.h>
#include "../Student.h"
#include "../loadfile.cpp"

using namespace std;

template<class T>
class max_heap
{
private:
    vector<T> arr;
public:
    max_heap(vector<T> arr);
    void max_heapify(int index);
    void build_max_heap();
    void insert(T element);
    T max();
    T extract_max();
    vector<T> heapSort();
    void print(int index);
};

template<class T>
max_heap<T>::max_heap(vector<T> arr)
{
    this->arr = arr;
    build_max_heap();
}

template<class T>
void max_heap<T>::max_heapify(int index)
{
    int l = 2*index;
    int r = 2*index + 1;
    int largest = index;
    if(l < arr.size() && arr[largest] < arr[l])
        largest = l;

    if(r < arr.size() && arr[largest] < arr[r])
        largest = r;
    
    if(largest != index){
        swap(arr[largest], arr[index]);
        max_heapify(largest);
    }
}

template<class T>
void max_heap<T>::build_max_heap()
{
    for(int i = arr.size()/2; i >= 0; i--){
        max_heapify(i);
    }
}

template<class T>
void max_heap<T>::insert(T element)
{
    int index = arr.size();
    arr.push_back(element);
    while (index > 0 && arr[((index+1)/2)-1] < arr[index])
    {
        swap(arr[index], arr[((index+1)/2)-1]);
        index = ((index+1)/2)-1;
    }
}

template<class T>
T max_heap<T>::max(){
    try{
        T max = arr[0];
        return max;
    }
    catch(...){
        cout << "heap underflow";
        throw "heap underflow";
    }
}

template<class T>
T max_heap<T>::extract_max(){
    try{
        T max = arr[0];
        swap(arr[0], arr[arr.size()-1]);
        arr.pop_back();
        max_heapify(0);
        return max;
    }
    catch(...){
        cout << "heap underflow";
        throw "heap underflow";
    }
}

template<class T>
vector<T> max_heap<T>::heapSort(){
    vector<T> tmp = arr;
    vector<T> sorted;
    while(!arr.empty()){
        T max = this->extract_max();
        sorted.push_back(max);
    }
    reverse(sorted.begin(), sorted.end());
    arr = tmp;
    return sorted;
}

template<class T>
void max_heap<T>::print(int index){
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


int main(){
    vector<Student> students = loadfile();
    max_heap<Student> heap(students);
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
            heap.insert(Student(name, id, gpa, dep));
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