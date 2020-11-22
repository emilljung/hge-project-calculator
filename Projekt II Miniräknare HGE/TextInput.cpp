#include "TextInput.h"

TextInput::TextInput()
{
	//Set font for textinput
	mFont = new hgeFont( "ComicSans.fnt" );
	mFont->SetScale(0.8f);
}

TextInput::~TextInput()
{
	delete mFont;
}

int TextInput::update()
{
	// Handle Text Input
	// ----------------------------------------
	int c = hge->Input_GetKey(); // This will return 0, if no key was pressed

	// Check if any key was pressed
	if ( c )
	{
		// Filter the valid keycodes, only add numbers, character or spacebar inputs
		if ( c >= '0' && c <= '9') // || c >= 'A' && c <= 'F'
		{
			//When c == HGEK_NUMPAD1, mText.push_back(c) returns 'a', not '1'
			mText.push_back(c);
		}
		if(c == HGEK_NUMPAD1)
		{
			mText.push_back('1');
		}
		if(c == HGEK_NUMPAD2)
		{
			mText.push_back('2');
		}
		if(c == HGEK_NUMPAD3)
		{
			mText.push_back('3');
		}
		if(c == HGEK_NUMPAD4)
		{
			mText.push_back('4');
		}
		if(c == HGEK_NUMPAD5)
		{
			mText.push_back('5');
		}
		if(c == HGEK_NUMPAD6)
		{
			mText.push_back('6');
		}
		if(c == HGEK_NUMPAD7)
		{
			mText.push_back('7');
		}
		if(c == HGEK_NUMPAD8)
		{
			mText.push_back('8');
		}
		if(c == HGEK_NUMPAD9)
		{
			mText.push_back('9');
		}
		if(c == HGEK_NUMPAD0)
		{
			mText.push_back('0');
		}
		if(c == HGEK_I)
		{
			mText.push_back('i');
		}
		if(c == HGEK_ADD)
		{
			mText.push_back('+');
		}
		if(c == HGEK_SUBTRACT)
		{
			mText.push_back('-');
		}
		// Delete character with backspace
		if ( c == HGEK_BACKSPACE && !mText.empty() )
		{
			mText.pop_back();
		}
		if(c == 'C')
		{
			//Empty stack
			while(!mText.empty())
				mText.pop_back();
		}
		if ( c == HGEK_ENTER )
		{
			string ans;
			ans = this->calc.calculate(mText); //Skicka sträng till Calculator
			mText.push_back('\n');
			int size = ans.size();

			for(int i = 0; i < size; i++)
				mText.push_back(ans[i]);
		}
	}
	// ----------------------------------------

	return 0;
}

void TextInput::pushChar(char character)
{
	mText.push_back(character);
}

void TextInput::render()
{	
	//The text is written at pos (100,100) and from left to right
	mFont->Render( 100.0f, 100.0f, HGETEXT_LEFT, mText.c_str() );
}