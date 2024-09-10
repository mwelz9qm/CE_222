#pragma once
#include<iostream>

using namespace std;

class rectangleType
{
private:
	double length;
	double width;
public:
	rectangleType(); //default constructor
	rectangleType(double l, double w); //constructor with parameters
	//getters
	double getLength() const;
	double getWidth() const;
	double getArea() const;
	double getPerimeter() const;
	void print() const;
	//setter
	void setDimension(double l, double w);
};