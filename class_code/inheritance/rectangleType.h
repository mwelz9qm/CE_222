#pragma once

//rectangle type interface

class rectangleType {
protected:
	double length;
	double width;
public:
	rectangleType(double l = 0, double w = 0); //constructor with default params
	double getPerimeter() const;
	double getArea() const;
	void print() const;
	double getLength() const;
	double getWidth() const;
	void setDimensions(double l, double w);
};

