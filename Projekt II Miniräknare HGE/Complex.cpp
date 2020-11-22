#include "Complex.h"

Complex::Complex(double a, double b)
{
	this->a = a;
	this->b = b;
}

Complex::~Complex()
{}

Complex Complex::operator+(Complex& cmplx)
{
	double a = this->a + cmplx.a;
	double b = this->b + cmplx.b;
	Complex ans(a, b);

	return ans;
}

Complex Complex::operator-(Complex& cmplx)
{
	double a = this->a - cmplx.a;
	double b = this->b - cmplx.b;
	Complex ans(a, b);
	
	return ans;
}

Complex Complex::operator*(Complex& cmplx)
{
	double a = (this->a * cmplx.a) - (this->b * cmplx.b);
	double b = (this->a * cmplx.b) + (this->b * cmplx.a);
	Complex ans(a, b);

	return ans;
}

Complex Complex::operator/(Complex& cmplx)
{
	double a = 0, b = 0, lowVal = pow((double)10, (double)-10);

	//if(c == 0 && d == 0)
	if((cmplx.a < lowVal && cmplx.a > -lowVal) 
		&& ((cmplx.b < lowVal && cmplx.b > -lowVal)))
	{
		//x/0, "ERR: DIVIDE BY 0". To make this simple the answer is simply 0.
	}
	else
	{
		a = ((this->a * cmplx.a) + (this->b * cmplx.b)) / (pow(cmplx.a, 2) + pow(cmplx.b, 2));
		b = ((this->b * cmplx.a) - (this->a * cmplx.b)) / (pow(cmplx.a, 2) + pow(cmplx.b, 2));

		//if(a == 0 && b == 0)
		if((this->a < lowVal && this->a > -lowVal) 
			&& ((this->b < lowVal && this->b > -lowVal)))
		{
			//0/x  where x!=0
			a = 0;	
			b = 0;
		}
	}

	Complex ans(a, b);

	return ans;
}

Complex Complex::operator=(const Complex& cmplx)
{
	if(this == &cmplx)
		return *this;

	this->a = cmplx.a;
	this->b = cmplx.b;
	return *this;
}

Complex::Complex(const Complex& cmplx)
{
	this->a = cmplx.a;
	this->b = cmplx.b;
}

string Complex::getStringAns()
{
	double lowVal = pow((double)10, (double)-10);
	string strAns;
	ostringstream s;

	//if(a == 0 && b == 0)
	if((this->a < lowVal && this->a > -lowVal) && (this->b < lowVal && this->b > -lowVal))
	{
		strAns = "0";
	}
	else if(this->a < lowVal && this->a > -lowVal) //else if(a == 0)
	{
		if(this->b < 1+lowVal && this->b > 1-lowVal) //if(b == 1)
			s << "i";
		else if(this->b < -1+lowVal && this->b > -1-lowVal) //else if(b == -1)
			s << "-i";
		else
			s << this->b << "i";

		strAns = s.str();
	}
	else if(this->b < lowVal && this->b > -lowVal) // else if(b == 0)
	{
		s << this->a;
		strAns = s.str();
	}
	else
	{
		if(this->b > lowVal) //if(b > 0)
		{
			if(this->b < 1+lowVal && this->b > 1-lowVal) //if(b == 1)
				s << this->a << "+i";
			else
				s << this->a << "+" << this->b << "i";
		}
		else
		{
			if(this->b < -1+lowVal && this->b > -1-lowVal) //if(b == -1)
				s << this->a << "-i";
			else
				s << this->a << this->b << "i";
		}
		strAns = s.str();
	}
	return strAns;
}