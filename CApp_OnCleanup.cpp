#include "CApp.h"
 
void CApp::OnCleanup() {
	// Free the surfaces
	SDL_FreeSurface(Surf_BG);
	SDL_FreeSurface(Surf_Display);
	SDL_FreeSurface(Message);

	for(int i=0;i<EntityList.size();i++){
		if(!EntityList[i]) continue;

		EntityList[i]->OnCleanup();
	}

	EntityList.clear();

	TTF_CloseFont(font);

	TTF_Quit();

	Mix_FreeMusic(mus);
	Mix_FreeChunk(sfx1);
	Mix_FreeChunk(sfx2);

	Mix_CloseAudio();

	// Quit out of SDL
	SDL_Quit();
}
