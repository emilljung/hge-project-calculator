#include "ToScreen.h"
#include "GuiButton.h"


ToScreen::ToScreen()
{
	this->textInput = new TextInput();
	this->complex();
}

ToScreen::~ToScreen()
{
	delete this->textInput;
}

int ToScreen::update()
{
	// This will update all gui components
	// that are added to the manager ( needed
	// for events to work ).
	mGuiManager.Update( hge->Timer_GetDelta() );

	//Update TextInput
	textInput->update();

	return 0;
}

void ToScreen::render()
{
	// Render all added gui components
	mGuiManager.Render();

	//Render TextInput
	textInput->render();
}

void ToScreen::complex()
{
	ostringstream s;
	int id = 1;

	//Add 1-9 buttons
	for( int i = 0; i < 3; i++ )
		for ( int j = 0; j < 3; j++ )
		{
			s << id;

			this->addButton(id, 300.0f + j*50.0f, 400.f - i*50.0f, s.str());

			id++;
			s.str("");
		}

	//Add 0, i and ',' buttons
	this->addButton( 0, 300.0f, 450.0f, "0" );
	this->addButton( 10, 350.0f, 450.0f, "i" );
	this->addButton( 11, 400.0f, 450.0f, "dot" );

	//Add +, -, ( and ) buttons
	this->addButton( 12, 475.0f, 300.0f, "add" );
	this->addButton( 13, 475.0f, 350.0f, "minus" );
	this->addButton( 14, 475.0f, 400.0f, "left" );
	this->addButton( 15, 475.0f, 450.0f, "right" );
}

void ToScreen::pushChar(char character)
{
	this->textInput->pushChar(character);
}

void ToScreen::addButton(int id, float x, float y, string file)
{
	this->guiObj = new GuiButton( id, x, y, file );
	mGuiManager.AddCtrl( this->guiObj );
	dynamic_cast<GuiButton*>( this->guiObj )->setPtr( &(*this) );	//The GuiButton will now have a pointer to ToScreen
}