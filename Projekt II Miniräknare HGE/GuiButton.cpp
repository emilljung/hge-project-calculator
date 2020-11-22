#include "GuiButton.h"

GuiButton::GuiButton ( int id, float x, float y, string file )
{
	// Set Sprite size in pixels
	mWidth = 40.0f;
	mHeight = 40.0f;

	// hgeGUIObject properties ( must be set )
	// ------------------------------
	this->id = id;
	bStatic = false;	//What?
	bVisible = true;	//Buttons are invisible if false. You can still press buttons if invis.
	bEnabled = true;	//Buttons can be pressed etc if true.

	rect.x1 = x;
	rect.y1 = y;
	rect.x2 = x + mWidth;
	rect.y2 = y + mHeight;	
	// ------------------------------

	// Load Button State Textures
	// ------------------------------
	fileName = file + "Default.png";
	mButtonDefaultTex = hge->Texture_Load( fileName.c_str() );

	fileName = file + "Pressing.png";
	mButtonPressingTex = hge->Texture_Load( fileName.c_str() );
	// ------------------------------

	// Create Button Sprites
	// ------------------------------
	mButtonDefault = new hgeSprite( mButtonDefaultTex, 0.0f, 0.0f, mWidth, mHeight );
	mButtonPressing = new hgeSprite( mButtonPressingTex, 0.0f, 0.0f, mWidth, mHeight );
	// ------------------------------

	//Each button will have char value which will
	//be returned after being pressed.

	if(file == "dot")
		character = '.';
	else if(file == "add")
		character = '+';
	else if(file == "minus")
		character = '-';
	else if(file == "left")
		character = '(';
	else if(file == "right")
		character = ')';
	else
		character = file[0];

	// Set initial state
	mButtonState = mButtonDefault;
}

GuiButton::~GuiButton ()
{
	// Deallocate Button Sprites
	// ------------------------------
	delete mButtonDefault;
	delete mButtonPressing;
	// ------------------------------

	// Free Texture Resources
	// ------------------------------
	hge->Texture_Free( mButtonDefaultTex );
	hge->Texture_Free( mButtonPressingTex );
	// ------------------------------
}

bool GuiButton::MouseLButton ( bool bDown )
{
	// If mouse is pressing button, change texture
	if ( bDown )
	{
		mButtonState = mButtonPressing;
		this->toScreen->pushChar(this->getChar());
	}
	else
		mButtonState = mButtonDefault;

	return true;
}

void GuiButton::Render()
{
	// Render current Button state
	mButtonState->Render( rect.x1, rect.y1 );
}

char GuiButton::getChar() const
{
	return this->character;
}

void GuiButton::setPtr(ToScreen* toScreen)
{
	this->toScreen = toScreen;
}