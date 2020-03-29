#include <iostream>
#include "Game.h"

int main() {
	///*
	char play;
	Game *game;

	do {
		game = new Game;
		game->start();
		delete(game);

		std::cout << std::endl << "----------- PLAY AGAIN? (Press 'y' if yes or anything else to close the game.) -----------" << std::endl << std::endl;
		std::cin >> play;
	} while (play == 'y');

	std::cout << std::endl << "----------- PROGRAM TERMINATED -----------" << std::endl;
	//*/
	
	/*

	int x;
	do {
		std::cin >> x;
	} while (isalpha(x));
	std::cout << x << std::endl;
	//*/

	return 0;
}