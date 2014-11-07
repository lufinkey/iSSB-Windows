
#include "Game.h"

#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

int main(int argc, char* argv[])
{
	SmashBros::Game*game = new SmashBros::Game();
	game->Run();
	delete game;
	return 0;
}