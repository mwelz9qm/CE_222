#include "boxType.h"
#include <iostream>
using namespace std;

boxType::boxType(double l, double w, double h)
	:rectangleType(l, w)  //calls rectangleType constructor
{
	if (h >= 0)
		height = h;
	else
	{
		cout << "You entered a negative height, so default to 0." << endl;
		height = 0;
	}
}
//constructor
void boxType::setDimensions(double l, double w, double h)
{
	rectangleType::setDimensions(l, w); // call the rectangle set dimensions
	if (h >= 0)
		height = h;
	else
	{
		cout << "You entered a negative height, so default to 0." << endl;
		height = 0;
	}

}
double boxType::getHeight() const {
	return height;
}
double boxType::getVolume() const
{
	return length * width * height;
}
double boxType::getArea() const //surface area of the box
{
	return 2 * rectangleType::getArea() + 2 * width * height + 2 * length * height;
}
void boxType::print() const
{
	cout << "*************" << endl;
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
	cout << "Surface Area: " << getArea() << endl;
	cout << "Base Perimeter: " << getPerimeter() << endl;
	cout << "Volume: " << getVolume() << endl;
	cout << "*************" << endl;
}