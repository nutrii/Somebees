/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "ClassWindow.h"
int main( int argc, char* args[] )
{
	Window* a = new Window;
	//a->loadmedia("TDDI02/Picture.bmp");
	a->fillwhite();
	SDL_Delay( 2000 );
	delete a;
	return 0;
}