#include "rectangleType.h"
#include<iostream>

using namespace std;


rectangleType::rectangleType(double l, double w) //constructor with default params
{
	setDimensions(l, w);
}
double rectangleType::getPerimeter() const
{
	return 2 * length + 2 * width;
}
double rectangleType::getArea() const
{
	return length * width;
}
void rectangleType::print() const
{
	cout << "*************" << endl;
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Area: " << getArea() << endl;
	cout << "Perimeter: " << getPerimeter() << endl;
	cout << "*************" << endl;
}
double rectangleType::getLength() const
{
	return length;
}
double rectangleType::getWidth() const
{
	return width;
}
void rectangleType::setDimensions(double l, double w)
{
	if (l >= 0)
		length = l;
	else
	{
		cout << "Invalid length, setting it equal to 0" << endl;
		length = 0;
	}
	if (w >= 0)
		width = w;
	else
	{
		cout << "Invalid width, setting it equal to 0" << endl;
		width = 0;
	}


}

