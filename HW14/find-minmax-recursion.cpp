
//////////////////////////////////////////////////
// Author: Ana Patricia Balbon
// Email: apdlbalb@nyu.edu
// Homework 14
// Description: This program includes a function which will take in a vector and
// finds the minimum and maximum.
// Copyright (c) 2021. All rights reserved.
//////////////////////////////////////////////////

#include <iostream>
#include <vector>

std::vector<int> findMinMax(std::vector<int> v);
void findMinMaxAcc(std::vector<int> v,
                   int low,
                   int high,
                   int& outMin,
                   int& outMax);

int main(){
    std::vector<int> test;
    test.push_back(2);
    test.push_back(1);
    test.push_back(3);
    test.push_back(8);
    test.push_back(15);
    test.push_back(0);
    test.push_back(5);

    std:: vector<int> res = findMinMax(test);

    std::cout<<"Min: "<<res[0]<<' '<<"Max: "<<res[1];

    return 0;
}

std::vector<int> findMinMax(std::vector<int> v){
    int len = v.size();
    std::vector<int> res;
    if (len == 1){
        res.push_back(v[0]);
        res.push_back(v[0]);
    } else if (len == 2){
        if (v[0] < v[1]){
            res.push_back(v[0]);
            res.push_back(v[1]);
        } else {
            res.push_back(v[1]);
            res.push_back(v[0]);
        }
    } else {
        int leftLow = 0;
        int leftHigh = len / 2;
        int rightLow = leftHigh + 1;
        int rightHigh = len - 1;

        int leftMin = v[leftLow];
        int leftMax = v[leftLow];

        int rightMin = v[rightLow];
        int rightMax = v[rightLow];

        findMinMaxAcc(v, leftLow, leftHigh, leftMin, leftMax);
        findMinMaxAcc(v, rightLow, rightHigh, rightMin, rightMax);

        if (leftMin < rightMin){
            res.push_back(leftMin);
        } else {
            res.push_back(rightMin);
        }

        if (leftMax > rightMax){
            res.push_back(leftMax);
        } else {
            res.push_back(rightMax);
        }

    }
    return res;
}

void findMinMaxAcc(std::vector<int> v,
                   int low,
                   int high,
                   int& outMin,
                   int& outMax){
    if (low == high){
        outMin = v[low];
        outMax = v[low];
    } else {
        findMinMaxAcc(v, low + 1, high, outMin, outMax);
        if (v[low] < outMin){
            outMin = v[low];
        }
        if(v[low] > outMax){
            outMax = v[low];
        }
    }
}
