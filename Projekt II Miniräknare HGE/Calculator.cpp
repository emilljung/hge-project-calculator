#include "Calculator.h"

Calculator::Calculator()
{}

Calculator::~Calculator()
{}

string Calculator::calculate(string calcThis)
{
	string ans;
	
	if(this->ts.errorSearch(calcThis))
		ans = this->simplify(calcThis);
	else
		ans = "Can't be calculated!\n";

	return ans;
}

string Calculator::simplify(string calcThis)
{
	//This version of simplify() ONLY CALCULATES + AND -. Multiplication & division will screw up the code!
	//Also, the Function cmplxRaisedCmplx() in Complex doesn't work, so ^ won't work.

	bool calculate = true;
	int i = 0, size = calcThis.size();
	ostringstream s;
	string ans;

	while(i < size && calculate == true)
	{
		if(i < size-1)
		{
			if(calcThis[i] == '(' && calcThis[i+1] != ')')
			{
				i++;
				s.str("");
				while(calcThis[i] != ')') //Puts for example "3+2i" from "(3+2i)" in the ostringstream.
				{
					s << calcThis[i];
					i++;
				}

				if(ts.complexCheck(s.str()))
					this->numStack.push(calcReIm(s.str())); //Gets a Complex obj, ex Complex(3,2), and pushes in to stack
				else
				{
					ans = "Error in a complex object.\n";
					calculate = false;
				}

			}
			if(i != size-1)
				this->charStack.push(calcThis[i+1]); //Pushes in the x "...)x(..."
		}

		i+=2;
	}

	if(calculate == true)
	{
		while(!this->charStack.isEmpty())
		{
			cout << this->charStack.peek() << endl;
			if(this->charStack.peek() == '+')
			{
				char c = this->charStack.pop();	//Only removes the top value

				//...(a+bi)+(c+di), c1 = c+di & c2 = a+bi
				Complex c1 = numStack.pop();
				Complex c2 = numStack.pop();

				if(this->charStack.peek() == '-') //if "-(a+bi)+(c+di)"
				{
					Complex inv(-1, 0);
					c2 = c2 * inv;

					char c = this->charStack.pop();
					this->charStack.push('+');
				}

				c2 = c1 + c2;

				numStack.push(c2);
			}
			else if(this->charStack.peek() == '-')
			{
				char c = this->charStack.pop();	//Only removes the top value

				//...(a+bi)-(c+di), c1 = c+di & c2 = a+bi
				Complex c1 = numStack.pop();
				Complex c2 = numStack.pop();
				
				Complex inv(-1, 0);
				c1 = c1 * inv;			//(a+bi)-(c+di) = (a+bi)+(-c-di)

				if(this->charStack.peek() == '-') //if "-(a+bi)-(c+di)"
					c2 = c2 * inv;

				c2 = c1 + c2;

				numStack.push(c2);
			}
		}
		ans = numStack.pop().getStringAns(); //The only value in this stack is now the answer.
	}

	return ans;
}

Complex Calculator::calcReIm(string calcThis)
{
	//(3+i) ger a = 0 och b = 3
	double a = 0, b = 0, lowVal = pow((double)10, (double)-10);
	int stringSize = calcThis.size(), numID = 0;
	char *ptr = new char[stringSize];

	//Separates the real and imaginary parts, ex [-,2,+,1,0,i] gives [0,0,1,0,0,0]
	for(int i = 0; i < stringSize; i++)
	{
		ptr[i] = calcThis[i];		//Puts the entire calculation in ptr[]
		if(ptr[i] == '+' || ptr[i] == '-')
			numID = i; //this spot separates real from imaginary
	}
	
	if(ptr[0] == 'i')	//check if there's only "i"
		b = 1;
	else if(ptr[0] == '-' && ptr[1] == 'i') //check if there's only "-i"
		b = -1;
	else
	{
		if(ptr[stringSize-1] == 'i')
		{
			//There is either only an imaginary part or there
			//are both imaginary and real parts in a+bi
			
			//if(numID > 1 || (numID < 1 && numID > 1-numID))
			if((numID >= 1+lowVal) || (numID < 1+lowVal && numID > 1-numID))
			{
				//There is a real and an imaginary part
				
				a = this->convCharsDouble(0, numID, ptr);

				if(ptr[numID] == '+') //checks if there is '+' in ptr[numID], example [-,2,'+',1,0,i]
				{
					if(ptr[numID+1] == 'i')
						b = 1;	//ex 32+i, which gives Im(a+bi) = 1
					else
						b = this->convCharsDouble(numID+1, stringSize-1, ptr); //ex 1+4i, you only need to keep "4" and not "+4"
				}
				else //if this->ptr[numID] == '-'
				{
					if(ptr[numID+1] == 'i')
						b = -1;	//ex 313472-i, which gives Im(a+bi) = -1
					else
						b = this->convCharsDouble(numID, stringSize-1, ptr);  //ex 1-4i, you get "-4"
				}
			}
			else
			{
				//There is only an imaginary part

				b = this->convCharsDouble(0, stringSize-1, ptr);
			}
		}
		else
		{
			//There is only a real part in a+bi since the final letter
			//has to be 'i' if an imaginary part is supposed to exist

			a = this->convCharsDouble(0, stringSize, ptr);
		}

		if(a < lowVal && a > -lowVal) //if(a == 0)
			a = 0;

		if(b < lowVal && b > -lowVal) //if(b == 0)
			b = 0;
	}
	delete [] ptr;
	
	return Complex(a, b);
}

double Calculator::convCharsDouble(int start, int end, char* ptr)
{
	double ans = 0;
	string convToDouble = "";

	//Converts char-array -> string
	for(int i = start; i < end; i++)
		convToDouble += ptr[i];

	//Converts string -> double
	ans = (double)atof(convToDouble.c_str());

	return ans;
}