#ifndef __GUIBUTTON_H__
#define __GUIBUTTON_H__
#include <hgegui.h>
#include <hgesprite.h>
#include <string>

#include "ToScreen.h"

using namespace std;

class GuiButton : public hgeGUIObject
{
	private:
		// Dimensions of the Textures
		float mWidth, mHeight;

		char character;
		ToScreen* toScreen;
		string fileName;

		// Texture for Button States
		HTEXTURE mButtonDefaultTex, mButtonPressingTex;

		// Sprite for Button States
		hgeSprite *mButtonDefault, *mButtonPressing;

		// Pointer to the current State
		hgeSprite *mButtonState;

	public:
		GuiButton ( int id, float x, float y, string file );
		virtual ~GuiButton ();

		// Function to handle hovering
		bool MouseLButton ( bool bDown );

		// Overridden pure virtual function
		void Render ();

		char getChar() const;
		void setPtr(ToScreen* toScreen);
};

#endif //__GUIBUTTON_H__
