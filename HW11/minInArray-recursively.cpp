
//////////////////////////////////////////////////
// Author: Ana Patricia Balbon
// Email: apdlbalb@nyu.edu
// Homework 11 Q3
// Description: This program is comprised of two recursive functions that
// take a sequence of elements and returns the minimum value in that sequence.
// Copyright (c) 2021. All rights reserved.
//////////////////////////////////////////////////


//////////////////////////////////////////////////

#include <iostream>

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main(){

    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    std::cout<<res1<<" "<<res2<<std::endl;

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr + 2, 4);
    std::cout<<res3<<" "<<res4<<std::endl;

    return 0;
}

int minInArray1(int arr[], int arrSize){
    int min;
    if (arrSize == 1){
        return arr[0];
    } else {
        min = minInArray1(arr + 1, arrSize - 1);
        if (min > arr[0]) {
            return arr[0];
        } else {
            return min;
        }
    }
}

int minInArray2(int arr[], int low, int high){
    int min;
    if (low == high){
        return arr[low];
    } else {
        min = minInArray2(arr, low + 1, high);
        if (min > arr[low]) {
            return arr[low];
        } else {
            return min;
        }
    }
}
