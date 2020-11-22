#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Complex.h"
#include "Troubleshoot.h"
#include "Stack.h"

class Calculator
{
private:
	Stack<char> charStack;		//Contains '+', '-' etc.
	Stack<Complex> numStack;	//Contains Complex objects
	Troubleshoot ts;

public:
	Calculator();
	~Calculator();

	string calculate(string calcThis);			//Just a function that calls the other functions. 
	string simplify(string calcThis);			//Calculates for example "(2)*(2+i)+(-2i)"

	Complex calcReIm(string calcThis);			//Expects a+bi as string, returns Complex(a,b);

	double convCharsDouble(int start, int end, char* ptr);	//Is used in calcReIm()
};

#endif