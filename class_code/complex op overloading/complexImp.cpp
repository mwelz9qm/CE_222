#include "complexType.h"


complexType::complexType(double a, double b)
{
	real = a;
	imag = b;
}


bool complexType::operator==(const complexType& complex2) const
{
	return (real == complex2.real && imag == complex2.imag);
}

complexType complexType::operator+(const complexType& complex2) const
{
	complexType sum;
	sum.real = real + complex2.real;
	sum.imag = imag + complex2.imag;
	return sum;
}

void complexType::display() const
{
	cout << real << " + " << imag << "i";
}

ostream& operator<<(ostream& outObj, const complexType &obj)
{
	outObj << obj.real << " + " << obj.imag<<"i";
	return outObj;
}

istream& operator>>(istream& inObj, complexType &obj)
{
	char ch;
	inObj >> obj.real;
	inObj >> ch;
	inObj >> obj.imag;
	if (ch == '-')
		obj.imag *= -1;
	inObj >> ch;
	return inObj;
}