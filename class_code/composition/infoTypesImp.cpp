#include "infoTypes.h"  
#include<iostream>      


//implementation of personType

void personType::printInfo() const
{
    cout << "First name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
}
void personType::setName(string first, string last) //setter
{
    firstName = first;
    lastName = last;
}
string personType::getFirstName() const //getters
{
    return firstName;
}
string personType::getLastName() const
{
    return lastName;
}
personType::personType(string first = "Jane", string last = "Doe") //constructor with default parameters
{
    setName(first, last);
}

// implementation of date type
dateType::dateType(int m = 1, int d = 1, int y = 2000) //constructor with default parameters
{
    setDate(m,d,y);
}
//getters
int dateType::getMonth() const
{
    return month;
}
int dateType::getDay() const
{
    return day;
}
int dateType::getYear() const
{
    return year;
}
void dateType::printDate() const
{
    cout << month << "/" << day << "/" << year << endl;
}
void dateType::setDate(int m, int d, int y) //setter
{
    month = m;
    day = d;
    year = y;
}

//implementation for personal type

void personalInfo::setPersonalInfo(string first, string last, int m, int d, int y, string add) //setter
{
    name.setName(first,last);
    bDay.setDate(m,d,y);
    address = add;
}
void personalInfo::printPersonalInfo() const
{
    name.printInfo();
    bDay.printDate();
    cout << "Address: " << address << endl;
}
//constructor with default parameters
personalInfo::personalInfo(string first = "Jane", string last = "Doe", int m = 1, int d = 1, int y = 2000, string add = "123 Fake St")
{
    setPersonalInfo(first,last,m,d,y,add);
}
