#include "Ship.h"

bool Ship::OnLoad() {

	Type = ENTITY_TYPE_SHIP;

	if((Surf_Entity = CSurface::OnLoad("./gfx/fighter.png")) == NULL) {
		return false;
	}

	CSurface::Transparent(Surf_Entity, 255, 0, 255);

	this->Width = 32;
	this->Height = 16;

	Anim_Control.MaxFrames = 1;

	return true;
}
