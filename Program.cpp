
#include "Game.h"

int main()
{
	SmashBros::Game*game = new SmashBros::Game();
	game->Run();
	delete game;
	return 0;
}