#ifndef TROUBLESHOOT_H
#define TROUBLESHOOT_H

#include "Stack.h"

class Troubleshoot
{
private:
	bool doTheCalc;

public:
	Troubleshoot();
	~Troubleshoot();

	bool errorSearch(string calculation);			//This function will call the other functions except complexCheck().
	
	bool checkIfEmpty(string calculation);	//Check if the string have any empty parts.
	bool parenthesesCheck(string calculation);		//Checks that the numbers of '(' and ')' matches etc.
	bool charCheck(string calculation);				//Checks for "+-", "*/+" etc.
	bool charParenthesesCheck(string calculation);	//Checks if the combination of for example '(' & '-' is used correctly.
	bool complexCheck(string complexPart);			//Checks if the string which will be used in a Complex object is written correctly.

};

#endif