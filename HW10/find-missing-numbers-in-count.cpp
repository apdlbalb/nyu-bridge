
//////////////////////////////////////////////////
// Author: Ana Patricia Balbon
// Email: apdlbalb@nyu.edu
// Homework 10 Q2
// Description: This program evaluates numbers which are missing
// in an array of 0 to n
// Copyright (c) 2021. All rights reserved.
//////////////////////////////////////////////////

// findMissing(arr, n, resArrSize) evaluates the numbers which are missing
// in an array of 0 to n
// Input: array "arr" which contains integers from 0 to "n"; "n" the logical
// size of the array; output parameter "resArrSize" which stores the logical
// size of the result array
// Requires: n >= 1
// Output: returns a dynamic array of all the missing numbers

//////////////////////////////////////////////////

#include <iostream>

int *findMissing(int arr[], int n, int& resArrSize);

int main(){
    int arr[6] = {0, 0, 4, 2, 1, 1};
    int resArrSize;
    int *missingNums;
    missingNums = findMissing(arr, 6, resArrSize);
    std::cout<<"Size: "<<resArrSize<<std::endl;

    std::cout<<"Missing numbers: ";
    for (int i = 0; i < resArrSize; ++i){
        std::cout<<missingNums[i]<<' ';
    }

    delete [] missingNums;
    return 0;
}

int *findMissing(int arr[], int n, int& resArrSize){
    int *missingNums = new int[n];
    int countMissing = 0;
    bool foundVal = false;

    for (int i = 0; i <= n; ++i){
        for (int j = 0; j < n && !foundVal; ++j){
            if (arr[j] == i){
                foundVal = true;
            }
        }
        if (!foundVal) {
            missingNums[countMissing] = i;
            ++countMissing;
        }
        foundVal = false;
    }

    resArrSize = countMissing;
    return missingNums;
}
