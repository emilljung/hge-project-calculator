#ifndef MAINOBJECT_H
#define MAINOBJECT_H
#include <GameObject.h>

#include "ToScreen.h"

class MainObject : public GameObject
{
	private:
		ToScreen *Complex;
		
	public:
		MainObject ();				// Load Game Resources
		virtual ~MainObject ();		// Free Game Resources

		// Frame ( Game Loop )
		// ---------------------------------------------
		int update ();				// Update Game Logic
		void render ();				// Render Scene
		// ---------------------------------------------
};

#endif // _MAINOBJECT_H