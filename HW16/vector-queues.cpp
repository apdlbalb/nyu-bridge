
//////////////////////////////////////////////////
// Author: Ana Patricia Balbon
// Email: apdlbalb@nyu.edu
// Homework 16 Q2
// Description: This program includes a class that implements a queue using
// vectors.
// Copyright (c) 2021. All rights reserved.
//////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Queue {
    int iFront;
    int iBack;
    int n;
    vector<T> items;
public:
    Queue() : iFront(0), iBack(0), n(0) {}
    void enqueue(T val);
    T dequeue();
    T front();
    bool isEmpty();
    void clear();
    int size();
};

int main(){

    Queue<int> test;
    test.enqueue(1);
    if (!test.isEmpty()){
        cout<<"Passed"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }
    if (test.size() == 1){
        cout<<"Passed"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }
    test.enqueue(2);
    if (test.front() == 1){
        cout<<"Passed"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }
    if (test.size() == 2){
        cout<<"Passed"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }
    test.dequeue();
    if (test.front() == 2){
        cout<<"Passed"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }
    test.clear();
    if (test.isEmpty()){
        cout<<"Passed"<<endl;
    } else {
        cout<<"Failed"<<endl;
    }

    return 0;
}

template <class T>
void Queue<T>::enqueue(T val) {
    items.push_back(val);
    n += 1;
    if (n > 1) {
        iBack += 1;
    }
}

template <class T>
T Queue<T>::dequeue(){
    if (n == 0) {
        throw;
    }

    T front = items[iFront];
    iFront += 1;
    n -= 1;

    if (n == 0) {
        items.clear();
    }

    return front;
}

template<class T>
T Queue<T>::front(){
    if (n == 0){
        throw;
    } else {
        return items[iFront];
    }
}

template<class T>
bool Queue<T>::isEmpty(){
    if (n == 0){
        return true;
    } else {
        return false;
    }
}

template<class T>
void Queue<T>::clear() {
    items.clear();
    n = 0;
    iFront = 0;
    iBack = 0;
}

template<class T>
int Queue<T>::size() {
    return n;
}
