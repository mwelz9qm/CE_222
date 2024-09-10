#include "rectangleType.h"

//implementation of our rectangle class

//default constructor
rectangleType::rectangleType()
{
	length = 1;
	width = 1;
}

//constructor with parameters
rectangleType::rectangleType(double l, double w)
{
	setDimension(l, w);
}

//getters
double rectangleType::getLength() const
{
	return length;
}
double rectangleType::getWidth() const
{
	return width;
}
double rectangleType::getArea() const
{
	return length * width;
}
double rectangleType::getPerimeter() const
{
	return 2 * length + 2 * width;
}
void rectangleType::print() const
{

	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
}
//setter
void rectangleType::setDimension(double l, double w)
{
	if (l >= 0)
		length = l;
	else
		length = 1;
	if (w >= 0)
		width = w;
	else
		width = 1;
}