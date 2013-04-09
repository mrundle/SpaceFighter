#include "CApp.h"

CApp::CApp() {
	// Initialize the surfaces to NULL to avoid errors
	Surf_BG = NULL;
	Surf_Display = NULL;
	Message = NULL;

	font = NULL;
	textColor.r=0;
	textColor.g=255;
	textColor.b=0;
	testColor.r=255;
	testColor.g=0;
	testColor.b=0;

	isMoving = false;

	bgVel = -.1;
	bgPos = 0;

	scoreNumber = 0;

	// Initialize the maxFrames for teh animation
	Anim_Char.MaxFrames=3;
		// If animation should oscillate, set Anim_Char.Oscillate = true;
	
	Running = true;

	srand (time(NULL));
}
 
int CApp::OnExecute() {
	// Initialize the game; if it fails, return error code and close program
	if(OnInit() == false){
		return -1;
	}

	SDL_Event Event;

	while(Running){
		// check for events (user input), pass one at a time to OnEvent()
		while(SDL_PollEvent(&Event)){
			OnEvent(&Event);
		}

		// Manipulate data
		OnLoop();
		// Render the output
		OnRender();
	}

	

	OnCleanup();

	return 0;
}
 
int main(int argc, char* argv[]) {
    CApp theApp;
 
    return theApp.OnExecute();
}
