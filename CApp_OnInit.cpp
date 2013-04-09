#include "CApp.h"

bool CApp::OnInit() {

//=====================================================================================
// Initialize all SDL components

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		return false;
	}

	if( TTF_Init() == -1 ){
		return false;
	}

	font = TTF_OpenFont("./fonts/future.ttf",12);
	if(font == NULL){
		return false;
	}

//======================================================================================
// Load the graphics

	/*
	Create window and surface
	SDL_SetVideoMode(window width, window height, bit resolution [16 or 32 recommended],display flags)
	SDL_HWSURFACE tells SDL to use hardware memory for storing images and such
	SDL_DOUBLEBUF tells SDL to use double buffering, important to keep screen from flickering
	another flag of interest is SDL_FULLSCREEN which makes the window go full screen
	*/
	if((Surf_Display = SDL_SetVideoMode(WWIDTH,WHEIGHT,32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL){
		return false;
	}

	// Name the window
	SDL_WM_SetCaption("SpaceShooter",NULL);

	// Load the background
	if((Surf_BG = CSurface::OnLoad("./gfx/SideScroll_Bkg01.png")) == NULL){
		return false;
	}

//==========================================================================
// Load the entities

if(Fighter.OnLoad() == false) {
	return false;
}

Fighter.X = 30;
Fighter.Y = 30;

EntityList.push_back(&Fighter);

//==========================================================================
// Load sound bites and play the music

// Open audio player
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );

	// Load the music file
	mus = Mix_LoadMUS("./sounds/ObstacleCourse.wav");
	if(mus==NULL){
	std::cout << "Error loading sounds." << std::endl;
	return false;
	}

	// Load the sound effects
	// http://rpg.hamsterrepublic.com/ohrrpgce/Free_Sound_Effects#Battle_Sounds
	//sfx1 = Mix_LoadWAV("./sounds/DrainMagic.ogg");
	//sfx2 = Mix_LoadWAV("./sounds/MediumExplosion.ogg");
	sfx2 = Mix_LoadWAV("./sounds/laser01.ogg");
	sfx1 = Mix_LoadWAV("./sounds/SmallExplosion.ogg");
	if(sfx1==NULL || sfx2==NULL){
	return false;
	}

	if(Mix_PlayingMusic() == 0){
	Mix_PlayMusic(mus,-1);
	}
	// if everything loaded without errors
	return true;
}
