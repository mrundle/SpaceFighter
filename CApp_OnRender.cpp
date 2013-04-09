#include "CApp.h"
 
void CApp::OnRender() {

	std::string scoreString;
	std::stringstream out;
	out << scoreNumber;
	scoreString = out.str();

	Message = TTF_RenderText_Solid( font, scoreString.c_str(), textColor);
	if(Message == NULL){
		std::cout << "Error\n";
	}

	if(bgPos <= 0){
		bgPos = WWIDTH;
	}
	bgPos += bgVel;
	// Draw background to screen 
	CSurface::OnDraw(Surf_Display,Surf_BG,bgPos,0,0,0,WWIDTH-bgPos,WHEIGHT);
	CSurface::OnDraw(Surf_Display,Surf_BG,0,0,WWIDTH-bgPos,0,bgPos,WHEIGHT);
	CSurface::OnDraw(Surf_Display,Message,WWIDTH/2,WHEIGHT/2);

	// Draw the entities
	for(int i=0;i<EntityList.size();i++){
		if(!EntityList[i]) continue;

		EntityList[i]->OnRender(Surf_Display);
	}

	// Refreshes the buffer and displays Surf_Display to screen
	SDL_Flip(Surf_Display);
}
