#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <GameObject.h>
#include <hgefont.h>

#include <string>
using namespace std;

#include "Calculator.h"

class TextInput : public GameObject
{
	private:
		hgeFont*	mFont;			// The font style to be used for text.
		string		mText;			// The collected text.
		Calculator	calc;


	public:
		TextInput();
		~TextInput();

		int update();
		void render();

		void pushChar(const char character);

};

#endif