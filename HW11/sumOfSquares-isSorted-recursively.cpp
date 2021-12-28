
//////////////////////////////////////////////////
// Author: Ana Patricia Balbon
// Email: apdlbalb@nyu.edu
// Homework 11 Q2
// Description: This program is comprised of recursive implementations of
// sumOfSquares and isSorted.
// Copyright (c) 2021. All rights reserved.
//////////////////////////////////////////////////

#include <iostream>

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main(){
    int arr[4] = {2, -1, 3, 10};
    int arr2[4] = {1, 2, 3, 4};
    int corrSum = 114;

    std::cout<<"sumOfSquares: ";

    int res = sumOfSquares(arr, 4);
    if (res == corrSum){
        std::cout<<"Passed";
    } else {
        std::cout<<res<<" Failed";
    }

    ////////////////////////////////////////////////
    ////////////////////////////////////////////////

    std::cout<<isSorted(arr, 4)<<isSorted(arr2, 4);

    return 0;
}

int sumOfSquares(int arr[], int arrSize){
    int sum = 0;
    int i = arr[0];

    if (arrSize == 1) {
        return i * i;
    } else {
        sum = sumOfSquares(arr + 1, arrSize - 1);
        sum += i * i;
        return sum;
    }
}

bool isSorted(int arr[], int arrSize){
    bool res;
    int i = 0;
    if (arrSize == 1){
        return true;
    } else {
        res = isSorted(arr + 1, arrSize - 1);
        return res && (arr[i] <= arr[i + 1]);
    }
}
