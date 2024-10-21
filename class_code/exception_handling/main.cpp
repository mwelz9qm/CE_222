#include<iostream>
#include<cmath>
#include "badmeans.h"
using namespace std;

double hmean(double a, double b);
double gmean(double a, double b);
void means(double a, double b);

int main()
{
	double x, y;
	cout << "Enter two numbers that we'll find the means of of. Q to quit. " << endl;
	while (cin >> x >> y)
	{
		try {
			means(x,y);
			cout << "Enter two numbers that we'll find the means of of. Q to quit. " << endl;

		}
		catch (bad_gmean bg)
		{
			cout << bg.what() << endl;
			cout << "The values " << bg.a << " and " << bg.b << " cannot be used in a geometric mean." << endl;
			break;
		}
		catch (bad_hmean bh)
		{
			cout << bh.what() << endl;
			cout << "The values " << bh.a << " and " << bh.b << " cannot be used in a harmonic mean." << endl;
			continue;
		}
	}
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a,b);
	return (2 * a * b) / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a,b);
	return sqrt(a*b);
}
void means(double a, double b)
{
	double am, hm, gm;
	am = (a + b)/2;
	hm = hmean(a,b);
	gm = gmean(a,b);

	cout << "The mean of your numbers is: " << am << "." << endl;
	cout << "The harmonic mean of your numbers is: " << hm << "." << endl;
	cout << "The geometric mean of your numbers is: " << gm << "." << endl;
}
