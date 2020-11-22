#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Complex
{
private:
	double a, b;				//a & b or "a+bi"

public:
	Complex(double a = 0, double b = 0);	//If no a or b is sent to constructor, then this->a=0 & this->b=0
	~Complex();
	
	Complex operator+(Complex&);		//(a+bi)+(c+di)
	Complex operator-(Complex&);		//(a+bi)-(c+di)
	Complex operator*(Complex&);		//(a+bi)*(c+di)
	Complex operator/(Complex&);		//(a+bi)/(c+di)
	Complex operator=(const Complex&);
	Complex(const Complex&);
	
	string getStringAns();				//Returns "a+bi"
};

#endif