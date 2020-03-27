#include <iostream>
#include "Game.h"

int main() {
	Game *game;

	game = new Game;
	game->start();
	delete(game);

	return 0;
}