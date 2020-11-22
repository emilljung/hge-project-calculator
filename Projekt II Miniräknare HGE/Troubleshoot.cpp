#include "Troubleshoot.h"

Troubleshoot::Troubleshoot()
{
	this->doTheCalc = true;
}

Troubleshoot::~Troubleshoot()
{}

bool Troubleshoot::errorSearch(string calculation)
{
	this->doTheCalc = this->checkIfEmpty(calculation);
	if(doTheCalc)
	{
		this->doTheCalc = this->charCheck(calculation);
		if(doTheCalc)
		{
			this->doTheCalc = this->parenthesesCheck(calculation);
			if(doTheCalc)
			{
				this->doTheCalc = this->charParenthesesCheck(calculation);
			}
		}
	}

	return this->doTheCalc;
}
	
bool Troubleshoot::checkIfEmpty(string calculation)
{
	int size = calculation.size();
	bool calculate = true;

	if(size == 0)
		calculate = false;

	return calculate;
}

bool Troubleshoot::parenthesesCheck(string calculation)
{
	int size = calculation.size();
	bool calculate = true;
	Stack<char> stack;
	char one;

	if(calculation[0] != '(')
		calculate = false;
	else
	{
		int i = 0;
		while(calculate == true && i < size)
		{
			if(calculation[i] == '(')
				stack.push(calculation[i]);
			else if(calculation[i] == ')')
				one = stack.pop();

			//Check if the parentheses are correctly used
			if(i < size-1)
			{
				if(calculation[i] == '(' && calculation[i+1] == ')')
					calculate = false;
				else if(calculation[i] == ')' && calculation[i+1] == '(')
					calculate = false;
			}

			i++;
		}

		if(!stack.isEmpty())	//If there are more '(' than ')'
			calculate = false;
	}

	return calculate;
}
	
bool Troubleshoot::charCheck(string calculation)
{
	int size = calculation.size(), i = 0;
	bool calculate = true;

	if(size == 1 || size == 2)	//There is no way you can calculate anything with just 1/2 char/s
	{
		calculate = false;
	}
	else
	{
		while(calculate == true && i < size)
		{
			//Checks if there are any combinations of '+', '-' etc.
			if((calculation[i] == '+' || calculation[i] == '*' || calculation[i] == '/' || calculation[i] == '^' || calculation[i] == '-') &&
				(calculation[i+1] == '+' || calculation[i+1] == '*' || calculation[i+1] == '/' || calculation[i+1] == '^' || calculation[i+1] == '-'))
			{	
				calculate = false;
			}

			i++;
		}
	}
	return calculate;
}
	
bool Troubleshoot::charParenthesesCheck(string calculation)
{
	int size = calculation.size(), i = 0;
	bool calculate = true;

	//Check if there are any combinations of '(', '+' etc that aren't correct
	while(calculate == true && i < size)
	{
		if(i < size-1)
		{
			if(calculation[i] == '(' && ( calculation[i+1] == '+' || calculation[i+1] == '*'
				||calculation [i+1] == '/' || calculation[i+1] == '^') )
			{
				//A Complex object may not start with either '+', '*', '/' or '^'.
				//'-' however, is ok.
				calculate = false;
			}
			else if( (calculation[i] == '+' || calculation[i] == '-' || calculation[i] == '*' || 
				calculation[i] == '/' || calculation[i] == '^') && calculation[i+1] == ')')
			{
				//A calculation cannot be like "...*)..."
				calculate = false;
			}
			else if(calculation[i] == ')' &&  i < size  && (calculation[i+1] == '0' || calculation[i+1] == '1' || calculation[i+1] == '2' 
				|| calculation[i+1] == '3' || calculation[i+1] == '4' || calculation[i+1] == '5' || calculation[i+1] == '6'
				|| calculation[i+1] == '7' || calculation[i+1] == '8' || calculation[i+1] == '9' || calculation[i+1] == 'i') )
			{
				//A calculation cannot be like "...)123(..."
				calculate = false;
			}
		}
		
		i++;
	}

	return calculate;
}

bool Troubleshoot::complexCheck(string complexPart)
{
	int size = complexPart.size()-1, i = 0;
	bool calculate = true, aChecked = false, bChecked = false;

	while(calculate == true && i < size)
	{
		//The other functions in this class makes sure that
		//complexPart cannot start with either '+', '*', '/' or '^'.
		//The string won't have '(' and/or ')' either.

		if(complexPart[i] == 'i')
		{
			if(aChecked == false && (complexPart[i+1] == '+' || complexPart[i+1] == '-'))
				calculate = false; //The calculation is written like bi+a
			else
			{
				bChecked = true; //Calculation is written like a+bi
				
				if(complexPart[i+1] == '+' || complexPart[i+1] == '-')
					calculate = false;	//complexPart is written like a+bi+...
			}
		}

		if(aChecked == true && complexPart[i] != 'i' && (complexPart[i+1] == '+' || complexPart[i+1] =='-'))
			calculate = false; //complexPart is written like "5+8-7i"

		if(complexPart[i] != 'i' && (complexPart[i+1] == '+' || complexPart[i+1] == '-'))
			aChecked = true; //There is a real number
				
		if(complexPart[i] == '+' || complexPart[i] == '-' && i != 0)
			aChecked = true; //There could be an imaginary part too

		i++;
	}

	return calculate;
}