
//////////////////////////////////////////////////
// Author: Ana Patricia Balbon
// Email: apdlbalb@nyu.edu
// Homework 16 Q1
// Description: This program includes a function that checks the symbol
// balance for the Pascal programming language.
// Copyright (c) 2021. All rights reserved.
//////////////////////////////////////////////////

#include <stack>
#include <iostream>
#include <fstream>

using namespace std;

void openInputFile(ifstream& inFile);
bool isBalanced(ifstream* inFile);
bool isValidClose(stack<char> openSymbols, char c);

int main(){
    ifstream inFile;
    openInputFile(inFile);
    if (isBalanced(&inFile)) {
        cout<<"true";
    }else {
        cout<<"false";
    }
    inFile.close();
    return 0;
}

void openInputFile(ifstream& inFile) {
    string filename;
    cout << "What file name:";
    cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        cout << "BAD FILENAME!"<<endl;
        cout << "What file name:";
        cin >> filename;
        inFile.clear(); //may not be necessary in newer versions of C++
        inFile.open(filename);
    }
}

bool isValidClose(stack<char> openSymbols, char c){
    if (openSymbols.empty()) return false;

    char top = openSymbols.top();
    if (top == '{'){
        if (c == '}') return true;
    } else if (top == '(') {
        if (c == ')') return true;
    } else if (top == '[') {
        if (c == ']') return true;
    }

    return false;
}

bool isBalanced(ifstream* inFile){
    stack<char> openSymbols;

    if (!inFile->peek()) return true; // return true if file is empty

    char c;
    while (*inFile >> c){
        if (c == '{' || c == '(' || c == '['){
            openSymbols.push(c);
        } else if (c == '}' || c == ')' || c == ']'){
            if (isValidClose(openSymbols, c)){
                openSymbols.pop();
            } else return false;
        }
    }

    if (openSymbols.empty()){
        return true;
    } else {
        return false;
    }
}
