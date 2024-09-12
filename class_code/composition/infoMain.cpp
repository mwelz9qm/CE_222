#include "infoTypes.h"

int main()
{
    personalInfo myPerson;
    myPerson.printPersonalInfo();
    myPerson.setPersonalInfo("Matt", "Welz", 4,4,1983,"456 Main St");
    myPerson.printPersonalInfo();
    return 0;
}