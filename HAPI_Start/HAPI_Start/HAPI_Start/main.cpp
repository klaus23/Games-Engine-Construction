/*
	HAPI Start
	----------
	This solution contains an already set up HAPI project and this main file
	
	The directory structure and main files are:

	HAPI_Start - contains the Visual Studio solution file (.sln)
		HAPI_Start - contains the Visual Studio HAPI_APP project file (.vcxproj) and source code
			HAPI - the directory with all the HAPI library files
			Data - a place to put your data files with a few sample ones provided

	Additionally in the top directory there is a batch file for creating a redistributable Demo folder

	For help using HAPI:
	https://scm-intranet.tees.ac.uk/users/u0018197/hapi.html
*/

// Include the HAPI header to get access to all of HAPIs interfaces
#include <HAPI_lib.h>
#include <time.h>
#include "Sprite.h"
#include "Visualisation.h"
#include <time.h>
#include <cstdlib>
#include "World.h"
// HAPI itself is wrapped in the HAPISPACE namespace
using namespace HAPISPACE;

void HAPI_Main()
{
	
	//fix movement
	//xbox movement to work
	World world;
	world.Initialise(1024,768);
	world.LoadLevel();
	world.Run();
		
		
}

