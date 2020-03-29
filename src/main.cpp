#include <iostream>
#include "Game.h"
#include "setupConsole.h"

int main() {
	///*
	char play;
	Game *game;

	setupVirtualConsole();

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

	//*/

	return 0;
}