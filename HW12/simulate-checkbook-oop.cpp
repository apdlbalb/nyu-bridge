
//////////////////////////////////////////////////
// Author: Ana Patricia Balbon
// Email: apdlbalb@nyu.edu
// Homework 12
// Description: This program simulates the balancing of a checkbook.
// Copyright (c) 2021. All rights reserved.
//////////////////////////////////////////////////

//////////////////////////////////////////////////

#include <iostream>
#include <vector>

class Money{
public:
    Money(){};
    Money(double inAmount){mAmount = inAmount;};
    void set(double setAmount);
    double get() const;
private:
    double mAmount;
};

class Check{
public:
    Check(){};
    Check(int newNumber, Money newAmount, bool newIsCashed);
    void set(int setNumber, double setAmount, bool setIsCashed);
    int getNumber() const;
    double getAmount() const;
    bool getIsCashed() const;
    void print() const;

private:
    int number;
    Money cAmount;
    bool isCashed;
};

int main(){
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    std::cout<<"Welcome! I'll help you balance your checkbook today."
    <<std::endl<<"To start, what was your previous balance? $";

    double oldBalance = 0;
    std::cin>>oldBalance;

    std::cout<<std::endl<<"Thanks! Now, let's record your transactions starting"
    <<" with your checks."<<std::endl
    <<std::endl<<"How many checks have you written since you last "
    <<"balanced your checkbook?";

    int checkCount = 0;
    std::cin>>checkCount;

    std::vector<Check> checkbook;
    int checkNum;
    double checkAmount;
    char checkIsCashedChar;
    bool checkIsCashedBool;
    double newTrueBalance = oldBalance;
    double newBalanceBank = oldBalance;
    for (int i = 1; i <= checkCount; ++i){
        std::cout<<std::endl;
        std::cout<<"What is the ID number of check "<<i<<"?";
        std::cin>>checkNum;
        std::cout<<"What was the amount? $";
        std::cin>>checkAmount;
        Money checkAmountMoney(checkAmount);
        std::cout<<"Has it been cashed? (Y/N)";
        std::cin>>checkIsCashedChar;

        if (checkIsCashedChar == 'Y') {
            checkIsCashedBool = true;
            newTrueBalance -= checkAmount;
            newBalanceBank -= checkAmount;
        } else {
            checkIsCashedBool = false;
            newTrueBalance -= checkAmount;
        }

        Check temp(checkNum, checkAmountMoney, checkIsCashedBool);
        checkbook.push_back(temp);
    }

    std::cout<<std::endl<<"Got it. Next, how many deposits have you made?";
    int depositsNum;
    std::cin>>depositsNum;

    if (depositsNum > 0){
        std::vector<double> deposits;
        double newDeposit;
        std::cout<<std::endl;
        for (int i = 1; i <= depositsNum; ++i){
            std::cout<<"What is the amount of deposit "<<i<<"?";
            std::cin>>newDeposit;
            deposits.push_back(newDeposit);
            newTrueBalance += newDeposit;
            newBalanceBank += newDeposit;
        }
    }

    double newBalanceDifference = newTrueBalance - newBalanceBank;
    std::cout<<std::endl<<"Alright then! Here is a summary of your "
    <<"account:"<<std::endl;
    std::cout<<"* New balance: $"<<newTrueBalance<<std::endl;
    std::cout<<"* New balance according to the bank: $"<<newBalanceBank<<
    std::endl;
    std::cout<<"* The difference between the new balance minus the new balance"
    <<std::endl<<" according to the bank is: $"<<newBalanceDifference;

    std::cout<<std::endl<<"* Cashed checks:"<<std::endl;
    Check tmp;
    if (checkCount > 0) {
        std::cout<<'\t'<<"Check no."<<'\t'<<"Amount"<<std::endl;
        for (int i = 0; i < checkCount; ++i){
            tmp = checkbook[i];
            if (tmp.getIsCashed()){
                std::cout<<'\t';
                tmp.print();
                std::cout<<std::endl;
            }
        }
    } else {
        std::cout<<'\t'<<"No checks have been cashed yet.";
    }

    std::cout<<std::endl<<"* Checks not yet cashed:"<<std::endl;
    if (checkCount > 0) {
        std::cout<<'\t'<<"Check no."<<'\t'<<"Amount"<<std::endl;
        for (int i = 0; i < checkCount; ++i){
            tmp = checkbook[i];
            if (!tmp.getIsCashed()){
                std::cout<<'\t';
                tmp.print();
                std::cout<<std::endl;
            }
        }
    } else {
        std::cout<<'\t'<<"There are no checks that have not yet been cashed.";
    }

    std::cout<<std::endl;
    return 0;
}

////////////////////////////////////////////////////////////////
///////////////////////// MONEY ////////////////////////////////
////////////////////////////////////////////////////////////////

void Money::set(double setAmount){
    mAmount = setAmount;
}

double Money::get() const{
    return mAmount;
}

////////////////////////////////////////////////////////////////
///////////////////////// CHECK ////////////////////////////////
////////////////////////////////////////////////////////////////

Check::Check(int newNumber, Money newAmount, bool newIsCashed) {
    number = newNumber;
    cAmount = newAmount;
    isCashed = newIsCashed;
}

void Check::set(int setNumber, double setAmount, bool setIsCashed) {
    number = setNumber;
    cAmount = setAmount;
    isCashed = setIsCashed;
}

int Check::getNumber() const{
    return number;
}

double Check::getAmount() const{
    return cAmount.get();
}

bool Check::getIsCashed() const{
    return isCashed;
}

void Check::print() const{
    std::cout<<number<<'\t'<<'\t'<<'$'<<cAmount.get();
}
