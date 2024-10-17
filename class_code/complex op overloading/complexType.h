#pragma once
#include<iostream>

using namespace std;

class complexType
{
private:
	double real;
	double imag;
public:
	complexType(double a = 0, double b = 0);
	bool operator==(const complexType& complex2) const;
	complexType operator+(const complexType& complex2) const;
	friend ostream& operator<<(ostream& outObj, const complexType &obj);
	friend istream& operator>>(istream& inObj, complexType &obj);
	void display() const;
};