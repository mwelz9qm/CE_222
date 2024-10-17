#include "complexType.h"

int main()
{
	complexType z1(2,5);
	cout << z1 << endl;
	cout << "Enter a complex number (in the form a + bi)" << endl;
	cin >> z1;
	cout << z1 << endl;

	return 0;
}
