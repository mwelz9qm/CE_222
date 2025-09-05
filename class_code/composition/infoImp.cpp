#include "info.h"
#include <iostream>
using namespace std;

//personType impelmentation
personType::personType(string first, string last)
{
	setName(first, last);
}
void personType::setName(string first, string last)
{
	firstName = first;
	lastName = last;
}
void personType::print() const
{
	cout << "Name: " << firstName << " " << lastName << endl;
}


//dateType implementation

dateType::dateType(int m, int d, int y)
{
	setDate(m, d, y);
}
void dateType::setDate(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}
void dateType::print() const
{
	cout << month << "/" << day << "/" << year << endl;
}


personalInfo::personalInfo(int id, string first, string last, int m
	, int d, int y)
	: name(first, last), bDay(m, d, y) //existing constructor
{
	idNumber = id;
}
void personalInfo::setPersonalInfo(int id, string first, string last, int m, int d, int y)
{
	name.setName(first, last);
	bDay.setDate(m, d, y);
	idNumber = id;
}
void personalInfo::print() const
{
	name.print();
	bDay.print();
	cout << "ID number: " << idNumber << endl;
}