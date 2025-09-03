#pragma once
#include "rectangleType.h"


class boxType : public rectangleType
{
private:
	double height;
public:
	boxType(double l = 0, double w = 0, double h = 0); //constructor
	void setDimensions(double l, double w, double h);
	double getHeight() const;
	double getVolume() const;
	double getArea() const; //surface area of the box
	void print() const;
};


//print, getArea, and setDimensions all appear in the base class
//setDimensions is overloaded, so there is no ambiguity: the different versions take different parameters
//getArea and print are overridden because the prototypes are identical
//for example, to distinguish the print functions use:
// rectangleType::print() vs boxType::print()
