#include<iostream>
#include "info.h"
using namespace std;

int main()
{
    
    //quick test that things are working
    personalInfo myPerson(3789, "Matt", "Welz", 3,3,1983);
    myPerson.print();
    myPerson.setPersonalInfo(387489, "Tony", "the Tiger", 1,1,1995);
    myPerson.print();

    return 0;
}