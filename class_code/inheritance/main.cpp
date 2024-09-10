#include "rectangleType.h"
#include "boxType.h"

int main()
{
	rectangleType myRectangle(3, 4);
	myRectangle.print();
	cout << "Area: " << myRectangle.getArea() << endl;
	cout << "Perimeter: " << myRectangle.getPerimeter() << endl;
	myRectangle.setDimension(8, 9);
	myRectangle.print();
	//other checks to still perform: default constructor, passing in negatives
	//to constructor or set dimension
	myRectangle.setDimension(-8, -9);
	myRectangle.print();

	//test boxType
	boxType myBox;
	myBox.print();
	myBox.setDimension(2, 7, 10);
	myBox.print();
	cout << "Surface Area: " << myBox.getArea() << endl;
	cout << "Volume: " << myBox.getVolume() << endl;



	return 0;
}