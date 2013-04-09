#include "CEntity.h"
#include "CApp.h"

//std::vector<CEntity*> CEntity::EntityList;

CEntity::CEntity(){
	Surf_Entity = NULL;

	X = Y = 0.0f;

	erase = false;

	Type = ENTITY_TYPE_NONE;

	movingUp = movingDown = false;

	xVel = yVel = 0;

	Width = Height = 0;

	AnimState = 0;
}

CEntity::~CEntity(){
}

void CEntity::OnLoop(){
	// Move the thing - if it is off the screen, delete it
	X += xVel;
	Y += yVel;
}

void CEntity::OnRender(SDL_Surface* Surf_Display) {
	if(Surf_Entity == NULL || Surf_Display == NULL) return;

	//CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y, Anim_Control.GetCurrentFrame() * Width, 0, Width, Height);
	CSurface::OnDraw(Surf_Display,Surf_Entity,this->X,this->Y);
}

void CEntity::OnCleanup() {
	if(Surf_Entity) {
		SDL_FreeSurface(Surf_Entity);
	}

	Surf_Entity = NULL;
}

float CEntity::distance(float otherX, float otherY) {
	float delX = (this->X) - otherX;
	float delY = (this->Y) - otherY;
	float distance = sqrt( (delX * delX) + (delY * delY) );
	std::cout << this->X << "," << this->Y << std::endl;
	std::cout << otherX << "," << otherY << std::endl;
	std::cout << distance << std::endl;
}
