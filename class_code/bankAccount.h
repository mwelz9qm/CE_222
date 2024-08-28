#pragma once
#include<iostream>
#include<string>

using namespace std;


//interface for account class
class bankAccount
{
    //data members
    private:
        double balance;
        string name;
    //class methods
    public:
        bankAccount(); //constructor
        //getters
        double getBalance() const;
        string getName() const;

        //setters
        void deposit(double amount);
        void withdrawal(double amount);
        void setName(string newName);
};

//implementation of account class methods

bankAccount::bankAccount()
{
    balance = 0;
    name = " ";
}

double bankAccount::getBalance() const
{
    return balance;
}

string bankAccount::getName() const
{
    return name;
}

void bankAccount::deposit(double amount)
{
    if (amount >=0)
        balance += amount;
    else
        cout << "Cannot deposit a negative amount!!" << endl;
}

void bankAccount::withdrawal(double amount)
{
    if (amount >= 0 && amount <= balance)
        balance -= amount;
    else
        cout << "Illegal withdrawal amount: it was either negative or more than your balance!" << endl;
}

void bankAccount::setName(string newName)
{
    name = newName;
}

