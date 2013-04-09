#ifndef _CSURFACE_H_
    #define _CSURFACE_H_
 
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
 
class CSurface {
    public:
        CSurface();
 
    public:
	// simple static function that will load a surface for us
    static SDL_Surface* OnLoad(char* File);

	// function to draw (blit) images
	static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
	
	// function to select a part of the source image, and then draw to screen
	static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);

	// make a color transparent
	static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};
 
#endif
