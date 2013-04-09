#include "Missile.h"

bool Missile::OnLoad(char* File, int Width, int Height, int MaxFrames) {
	if((Surf_Entity = CSurface::OnLoad("./gfx/missile.png")) == NULL) {
		return false;
	}

	CSurface::Transparent(Surf_Entity, 255, 0, 255);

	this->Width = Width;
	this->Height = Height;

	Anim_Control.MaxFrames = MaxFrames;

	return true;
}
