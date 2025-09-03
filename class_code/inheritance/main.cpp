#include "rectangleType.h"
#include "boxType.h"
#include <iostream>
using namespace std;


int main()
{

	rectangleType myR;

	myR.print();
	myR.setDimensions(7, 17);
	myR.print();

	boxType myBox(3000000000000000000,4000000000000000000,5000000000000000000);
	myBox.print();
	myBox.setDimensions(3.3, -12, 9.4);
	cout << "The new height is " << myBox.getHeight() << endl;

	return 0;
}
