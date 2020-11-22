#ifndef TOSCREEN_H
#define TOSCREEN_H

#include <sstream>

#include "TextInput.h"

//This part is necessary since GuiButton is a part of
//Guibutton ToScreen and ToScreen is a part of GuiButton
//--------------------------
class hgeGUIObject;
#include <hgeGUI.h>;
//--------------------------

class ToScreen : public GameObject
{

	private:
		hgeGUI mGuiManager;			// An object used to hold and manage a set of gui components.
		hgeGUIObject* guiObj;		// Pointer to GuiButton.
		TextInput* textInput;		// Pointer to textInput.

	public:
		ToScreen();
		~ToScreen();

		int update();				// Checks if filter is changed & updates the active ToScreen object
		void render();				// Renders the active ToScreen object

		void complex();				// Adds all buttons for the Complex filter

		void pushChar(char character);
		void addButton(int id, float x, float y, string file);
};

#endif