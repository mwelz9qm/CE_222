#pragma once
#include<string>
using namespace std;

//personType interface
class personType
{
private:
	string firstName;
	string lastName;

public:
	personType(string first = "Jane", string last = "Doe");
	void setName(string first, string last);
	void print() const;
};


class dateType
{
private:
	int month;
	int day;
	int year;
public:
	dateType(int m = 1, int d = 1, int y = 1970);
	void setDate(int m, int d, int y);
	void print() const;
};


class personalInfo
{
private:
	int idNumber;
	personType name;
	dateType bDay;
public:
	personalInfo(int id = 1, string first = "Jane", string last = "Doe", int m = 1
		, int d = 1, int y = 1970);
	void setPersonalInfo(int id = 1, string first, string last, int m, int d, int y);
	void print() const;
};

