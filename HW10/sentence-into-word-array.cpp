
//////////////////////////////////////////////////
// Author: Ana Patricia Balbon
// Email: apdlbalb@nyu.edu
// Homework 10 Q1
// Description: This program creates a new array that contains all the words
// in a line of text "sentence" and counts the number of words
// Copyright (c) 2021. All rights reserved.
//////////////////////////////////////////////////

// numSpaces(sentence, sentenceLen) counts the number of spaces in a string
// "sentence"

// getFirstWord(sentence) slices string "sentence" and returns all the
// characters before a space as a string

// createWordsArray(sentence, outWordsArrSize) takes a string "sentence" and
// creates an array storing all the words in "sentence"

//////////////////////////////////////////////////

#include <iostream>
#include <string>

int numSpaces(std::string sentence, int sentenceLen);
std::string getFirstWord(std::string sentence);
std::string *createWordsArray(std::string sentence, int& outWordsArrSize);

int main(){
    std::string sentence;
    int strArrSize;

    std::cout<<"Please type your sentence:"<<std::endl;

    std::getline(std::cin, sentence);
    std::string *test = createWordsArray(sentence, strArrSize);

    std::cout<<"Your sentence has "<<strArrSize<<" word(s):"<<std::endl;
    for (int i = 0; i < strArrSize; ++i){
        std::cout<<i + 1<<'\t'<<test[i]<<std::endl;
    }

    delete [] test;
    return 0;
}

std::string getFirstWord(std::string sentence){
    int wordLen;
    std::string word;
    wordLen = sentence.find(" ");
    word = sentence.substr(0, wordLen);
    return word;
}

int numSpaces(std::string sentence, int sentenceLen){
    int numSpaces = 0;
    int currLen =  sentenceLen;
    int i = 0;

    while (i != std::string::npos){
        i = sentence.find(" ");
        if (i != std::string::npos) {
            ++numSpaces;
            if(currLen > 1){
                ++i;
                currLen = currLen - i;
                sentence = sentence.substr(i, currLen);
            }
        }
    }

    return numSpaces;
}

std::string *createWordsArray(std::string sentence, int& outWordsArrSize){
    int wordCount = 0;
    int wordLen = 0, sentenceLength;
    std::string word;
    sentenceLength = sentence.length();
    int currLen = sentenceLength;
    int i = 0;

    int wordsArrLen = numSpaces(sentence, sentenceLength) + 2;
    std::string *wordsArr = new std::string[wordsArrLen];

    while (currLen > 0){
        if (sentence[0] != ' '){
            word = getFirstWord(sentence);
            wordsArr[wordCount] = word;
            wordLen = word.length();
            ++wordCount;
            currLen -= (wordLen + 1);
            if (currLen > 0) {
                sentence = sentence.substr(wordLen + 1, currLen);
            }
        } else {
            --currLen;
            sentence = sentence.substr(1, currLen);
        }
    }
    outWordsArrSize = wordCount;
    return wordsArr;
}
