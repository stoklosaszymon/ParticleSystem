#include "Game.h"
#include <iostream>


int main()
{
	std::unique_ptr<Game> game = std::make_unique<Game>();
	game->run();
}


	