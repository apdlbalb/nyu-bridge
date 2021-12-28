
//////////////////////////////////////////////////
// Author: Ana Patricia Balbon
// Email: apdlbalb@nyu.edu
// Homework 10 Q3
// Description: This program prints all the line numbers in a sequence
// entered by the user that contain a number of interest or a message saying
// it does not show at all in the sequence.
// Copyright (c) 2021. All rights reserved.
//////////////////////////////////////////////////

// main1() prints all the line numbers in a sequence entered by the user that
// contain a number of interest or a message saying it does not show at all in
// the sequence using an array

// main2() prints all the line numbers in a sequence entered by the user that
// contain a number of interest or a message saying it does not show at all in
// the sequence using a vector

//////////////////////////////////////////////////

#include <iostream>
#include <vector>

int main1();
int main2();

int main(){
    main1();
    std::cout<<std::endl<<std::endl;
    main2();
    return 0;
}

int main1(){
    std::cout<<"Please enter a sequence of positive integers, each "
             <<"in a separate line."<<std::endl
             <<"End your input by typing -1."<<std::endl;
    bool isEndOfInput = false;
    int n = 0;
    int *numsSeq = new int[1];
    int nums = 0;
    int numsSeqPhysicalSize = 1;

    while (!isEndOfInput){
        std::cin>>n;
        if (n == -1){
            isEndOfInput = true;
        } else {
            if (nums == numsSeqPhysicalSize){
                int *newNumsArr;
                newNumsArr = new int[2 * numsSeqPhysicalSize];
                for (int i = 0; i < nums; ++i) {
                    newNumsArr[i] = numsSeq[i];
                }
                delete [] numsSeq;
                numsSeq = newNumsArr;
                numsSeqPhysicalSize *= 2;
            }
            numsSeq[nums] = n;
            ++nums;
        }
    }

    int query;
    std::cout<<"Please enter a number you want to search."<<std::endl;
    std::cin>>query;

    int line;
    bool firstLineFound = false;

    for (int i = 0; i < nums; ++i){
        if (numsSeq[i] == query){
            if (!firstLineFound) {
                std::cout<<query<<" shows in lines ";
            }
            line = i + 1;
            if (firstLineFound) {
                std::cout << ", ";
            }
            std::cout<<line;
            firstLineFound = true;
        }
    }

    if (!firstLineFound) {
        std::cout << query << " does not show at all in the sequence.";
    } else {
        std::cout<<".";
    }

    delete [] numsSeq;

    return 0;
}

int main2(){
    std::cout<<"Please enter a sequence of positive integers, each "
             <<"in a separate line."<<std::endl
             <<"End your input by typing -1."<<std::endl;
    bool isEndOfInput = false;
    int n = 0;
    std::vector<int> numsSeq;

    while (!isEndOfInput){
        std::cin>>n;
        if (n == -1) {
            isEndOfInput = true;
        } else {
            numsSeq.push_back(n);
        }
    }

    int query;
    std::cout<<"Please enter a number you want to search."<<std::endl;
    std::cin>>query;

    int nums = numsSeq.size();
    int line;
    bool firstLineFound = false;
    for (int i = 0; i < nums; ++i){
        if (numsSeq[i] == query){
            if (!firstLineFound) {
                std::cout<<query<<" shows in lines ";
            }
            line = i + 1;
            if (firstLineFound) {
                std::cout << ", ";
            }
            std::cout<<line;
            firstLineFound = true;
        }
    }
    if (!firstLineFound) {
        std::cout << query << " does not show at all in the sequence.";
    } else {
        std::cout<<".";
    }
    return 0;
}
