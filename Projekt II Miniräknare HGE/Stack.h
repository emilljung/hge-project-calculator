#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack
{
private:
	T *stackPtr;
	int capacity, top;

public:
	Stack()
	{
		this->capacity = 5;
		this->top = 0;
		this->stackPtr = new T[this->capacity];
	}
	~Stack(){ delete [] this->stackPtr; }

	void push(T val)
	{
		//if stack is full, expand array
		if(this->top == this->capacity)
		{
			this->capacity += 5;
			T *tmp = new T[this->capacity];

			for(int i = 0; i < this->top; i++)
				tmp[i] = this->stackPtr[i];

			delete [] this->stackPtr;

			this->stackPtr = tmp;
		}
		//add value to stack
		this->stackPtr[this->top] = val;
		this->top++;
	}
	T pop() //Use only if there is a value in the Stack
	{
		this->top--;
		return this->stackPtr[this->top]; //return top value
	}
	T peek() //returns the top value
	{
		return this->stackPtr[this->top-1];
	}
	bool isEmpty() const
	{
		if(this->top == 0)
			return true;
		return false;
	}
	void print() const
	{
		for(int i = 0; i < this->top; i++)
			cout << this->stackPtr[i];
		cout << endl;
	}
};

#endif