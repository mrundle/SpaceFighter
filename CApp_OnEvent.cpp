#include "CApp.h"
#include <iostream>
using namespace std;
 
//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
	CEvent::OnEvent(Event);
}

//==============================================================================
void CApp::OnLButtonDown(int mX, int mY) {
/*    // move the character
	//if(x_pos>500) CurrentPlayer*=-1;
	//if(x_pos<5) CurrentPlayer*=-1;
	if(CurrentPlayer==1){
		x_pos+=20;
		y_pos+=20;
	}
	if(CurrentPlayer==-1){
		x_pos-=20;
		y_pos-=20;
	}
*/
}

//==============================================================================
void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {	
	
	switch(sym) {

		case SDLK_UP: {
			Fighter.movingUp = true;
			break;
		}

		case SDLK_DOWN: {
			Fighter.movingDown = true;
			break;
		}

		case SDLK_RIGHT: {
			break;
		}
    	case SDLK_ESCAPE: {
    		OnExit();
			break;
    	}

		case SDLK_SPACE: {
			Mix_PlayChannel(-1, sfx2, 0); 
			Bullet* tempBullet= new Bullet;
			(*tempBullet).OnLoad();
			(*tempBullet).X = Fighter.X+31;
			(*tempBullet).Y = Fighter.Y+6;
			EntityList.push_back(tempBullet);
			break;
		}

		case SDLK_p: {
			EnemyShip* tempEnemyShip = new EnemyShip;
			(*tempEnemyShip).OnLoad();
			(*tempEnemyShip).X = WWIDTH;
			(*tempEnemyShip).Y = rand() % (WHEIGHT-(*tempEnemyShip).Height);
			EntityList.push_back(tempEnemyShip);
			break;
		}

		default: {
		}
	}
}

//------------------------------------------------------------------------------
void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {

		case SDLK_UP: {
			Fighter.movingUp = false;
			break;
		}

		case SDLK_DOWN: {
			Fighter.movingDown = false;
			break;
		}

		default: {
		}
	}
}


//------------------------------------------------------------------------------
void CApp::OnExit(){
	Running = false;
}
