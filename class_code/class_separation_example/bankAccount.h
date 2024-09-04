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