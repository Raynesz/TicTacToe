#include <iostream>
#include "Game.h"

#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

int Game::mainLoop() {
	bool winner = false;
	char x;
	while (!winner) {
		std::cin >> x;
		if (validateInput(x)) {
			if (x == '0') {
				return 0;
				break;
			}
			else {

			}

		}
		else {
			std::cout << "Please provide valid input." << std::endl;
		}
	}
}

bool Game::validateInput(char& x) {
	char indices[10] = { '0', '1', '2', '3', '4' , '5' , '6' , '7' , '8' , '9' };
	
	return std::find(std::begin(indices), std::end(indices), x) != std::end(indices);
}

void Game::start() {
	int winner;

	std::cout << "----------- GAME START -----------" << std::endl;
	drawBoard();
	std::cout << "Use numbers 1-9 in the numpad to place your mark on the board. Type in 0 if you want to exit." << std::endl;
	winner = mainLoop();
	std::cout << winner << " player wins!!" << std::endl;
}

void Game::drawBoard() {
	std::cout << std::endl << UNDERLINE << board[0] << "|" << board[1] << "|" << board[2] << std::endl
		<< board[3] << "|" << board[4] << "|" << board[5] << CLOSEUNDERLINE << std::endl
		<< board[6] << "|" << board[7] << "|" << board[8] << std::endl;
}

void Game::set(char mark, int index) {
	board[index] = mark;
}