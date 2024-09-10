#pragma once
#include"rectangleType.h" 
//box class that inherits from our rectangleType

class boxType : public rectangleType
{
private:
	double height;
	//length and width are also member variables, but they are technically private
	//so we can't access them directly
public:
	boxType(); //default constructor
	boxType(double l, double w, double h); //constructor with parameters
	
	//getters
	double getHeight() const; //we inherit getLength() and getWidth()
	double getArea() const; //surface area
	double getVolume() const; 
	void print() const;

	//setter
	void setDimension(double l, double w, double h);
};