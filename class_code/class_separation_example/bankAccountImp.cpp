#include "bankAccount.h"

//implementation of bankAccount class

bankAccount::bankAccount(double amount,string n)
{
    balance = amount;
    name = n;
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
