//this code creates exception classes for the harmonic and geometric means
//it inherits from <exception> which is the base class for <stdexcept>

#pragma once
#include<iostream>
#include<stdexcept>
using namespace std;

class bad_hmean: public exception
{
public:
	double a;
	double b;
	bad_hmean(double x = 0, double y = 0): a(x),b(y) {}
	string what() {return "Bad arguments to hmean.";}
};

class bad_gmean: public exception
{
	public:
		double a;
		double b;
		bad_gmean(double x = 0, double y = 0): a(x),b(y) {}
		string what() {return "Bad arguments to gmean";}

};