#include "MainObject.h"

MainObject::MainObject ()
{
	// Set the mouse cursor to be visible
	hge->System_SetState( HGE_HIDEMOUSE, false );

	this->Complex = new ToScreen();	//Complex is rendered by default.
}

MainObject::~MainObject ()
{
	delete this->Complex;
}

int MainObject::update ()
{
	// Nothing needs to be updated
	this->Complex->update();
	return 0;
}

void MainObject::render ()
{
	this->Complex->render();
}