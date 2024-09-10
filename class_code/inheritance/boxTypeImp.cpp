#include "boxType.h"

//implementation of the box class

//default constructor
boxType::boxType()
{
	//rectangle default is auto-called to set the length and width
	height = 1;
}

//constructor with parameters

boxType::boxType(double l, double w, double h)
	:rectangleType(l,w)   //<- calls the rectangle parameter constructor
{
	if (h >= 0)
		height = h;
	else
		height = 1;
}

//getters

double boxType::getHeight() const
{
	return height;
}

double boxType::getVolume() const
{
	return getLength() * getWidth() * height;
}

/*
double boxType::getVolume() const
{
	return rectangleType::getArea() * height;
}
*/

double boxType::getArea() const
{
	//actually returns surface area
	// 2*length*width + 2*height*width + 2*height*length
	return 2 * getLength() * getWidth() + 2 * height * getWidth() + 2 * height * getLength();
}

void boxType::print() const
{
	rectangleType::print(); //using overidden function
	cout << "height: " << height << endl;
}

void boxType::setDimension(double l, double w, double h)
{
	rectangleType::setDimension(l,w);
	if (h >= 0)
		height = h;
	else
		h = 1;
}