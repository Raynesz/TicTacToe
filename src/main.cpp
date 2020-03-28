#include <iostream>
#include "Game.h"

int main() {
	Game *game;

	game = new Game;
	game->start();
	delete(game);

	//char x; int a;
	// = std::cin.get();
	//std::cout << x << std::endl;
	//a = (int)(x);
	//std::cin >> a;
	//std::cout << a << std::endl;

	return 0;
}