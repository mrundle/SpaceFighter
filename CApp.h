#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include "CEvent.h"
#include "Define.h"
#include "CEntity.h"
#include "CSurface.h"
#include "CAnimation.h"
#include "CEntity.h"
#include "Ship.h"
#include "Bullet.h"
#include "EnemyShip.h"
#include "EnemyBullet.h"
#include <iostream>
#include <stdlib.h> // srand(), rand()
#include <time.h> // time


class CApp : public CEvent {
    private:
	bool Running;

	// SDL surfaces
	SDL_Surface* Surf_Display;
	SDL_Surface* Surf_BG;
	SDL_Surface* Message;

	TTF_Font* font;
	SDL_Color textColor;
	SDL_Color testColor;

	Mix_Music *mus;
	Mix_Chunk *sfx1;
	Mix_Chunk *sfx2;

	CAnimation Anim_Char;

	Ship Fighter;

	int scoreNumber;

    private:

	bool isMoving;

	public:

	std::vector<CEntity*> EntityList;

    public:

		float bgVel,bgPos;

        CApp();
 
        int OnExecute();


    public:

		bool OnInit();
 
        void OnEvent(SDL_Event* Event);

		// When left mouse button clicks, gets position 
		void OnLButtonDown(int mX, int mY);

		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

		void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

		void OnExit();
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();
};
 
#endif
