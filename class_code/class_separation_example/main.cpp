#include "bankAccount.h"

//code for testing out the bankAccount class

int main()
{
    bankAccount myAccount(476);

    cout << "Intial balance: $" << myAccount.getBalance() << endl << endl;
    
    myAccount.deposit(1000);
    myAccount.setName("Matt W");
    cout << "New balance: $" << myAccount.getBalance() << endl;
    cout << "Account Name: " << myAccount.getName() << endl << endl;

    myAccount.withdrawal(465);
    myAccount.setName("Matthew W");
    cout << "New balance: $" << myAccount.getBalance() << endl;
    cout << "Account Name: " << myAccount.getName() << endl<<endl;

    return 0;
}