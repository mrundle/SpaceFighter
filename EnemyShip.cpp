#include "EnemyShip.h"

bool EnemyShip::OnLoad() {

	Type = ENTITY_TYPE_ENEMYSHIP;

	if((Surf_Entity = CSurface::OnLoad("./gfx/enemyfighter.png")) == NULL) {
		return false;
	}

	CSurface::Transparent(Surf_Entity, 255, 0, 255);

	this->Width = 32;
	this->Height = 16;

	this->xVel = -.2;

	Anim_Control.MaxFrames = 1;

	return true;
}
