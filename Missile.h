#ifndef MISSILE_H_
	#define MISSILE_H_

#include "CApp.h"
#include "CEntity.h"

class Missile : public CEntity {

	public:

	virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);

};

#endif
