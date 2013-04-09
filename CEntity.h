#ifndef CENTITY_H_
	#define CENTITY_H_

#include <vector>

#include "CAnimation.h"
#include "CSurface.h"
#include <math.h>

enum {
	ENTITY_TYPE_NONE = 0,

	ENTITY_TYPE_SHIP,
	ENTITY_TYPE_BULLET,
	ENTITY_TYPE_ENEMYSHIP,
	ENTITY_TYPE_ENEMYBULLET
};

class CEntity {

	protected:

		CAnimation Anim_Control;

		SDL_Surface* Surf_Entity;

	public:

		//static std::vector<CEntity*> EntityList;

		float X;
		float Y;

		bool erase;

		float xVel;
		float yVel;

		int Type;

		bool movingUp;
		bool movingDown;

		int Width;
		int Height;

		int AnimState;

		float distance(float,float);

	public:

	 	CEntity();
		virtual ~CEntity();

	public:

		virtual bool OnLoad() = 0;

		virtual void OnLoop();

		virtual void OnRender(SDL_Surface* Surf_Display);

		virtual void OnCleanup();

};

#endif
