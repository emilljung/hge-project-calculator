#include <hgeWrapper.h>
#include "MainObject.h"

int main ()
{
	// Initiate hge and check if it was successful
	if ( HgeWrapper::initiate() )
	{
		// Start hge with object derived from GameObject
		HgeWrapper::startHge(new MainObject());
	}

	return 0;
}