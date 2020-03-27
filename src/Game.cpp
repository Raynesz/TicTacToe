#include <iostream>
#include "Game.h"

#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

char Game::evaluateWinner(char& player) {
	return 'D';
}

char Game::mainLoop() {
	char x, player = 'X', winner = ' ';
	while (winner == ' ') {
		std::cin >> x;
		if (validateInput(x)) {
			if (x == '0') {
				return 'E';
			}
			else {
				set(player, x-1);
			}
			winner = evaluateWinner(player);
		}
		else {
			std::cout << "Please provide valid input." << std::endl;
		}
		player == 'X' ? player = 'O' : player = 'X';
	}
	return winner;
}

bool Game::validateInput(char& x) {
	char indices[10] = { '0', '1', '2', '3', '4' , '5' , '6' , '7' , '8' , '9' };
	bool a, b;
	
	a = std::find(std::begin(indices), std::end(indices), x) != std::end(indices);

	if (board[x-1] == ' ') {
		b = true;
	}
	else {
		b = false;
	}

	return !a && b;
}

void Game::start() {
	int winner;

	std::cout << "----------- GAME START -----------" << std::endl;
	drawBoard();
	std::cout << "Use numbers 1-9 in the numpad to place your mark on the board. Type in 0 if you want to exit." << std::endl;
	winner = mainLoop();
	switch(winner) {
	case 'D':
		std::cout <<"Draw!!" << std::endl;
		break;
	case 'E':
		break;
	default:
		std::cout << winner << " wins!!" << std::endl;
	}
	std::cout << "----------- GAME END -----------" << std::endl;
}

void Game::drawBoard() {
	std::cout << std::endl << UNDERLINE << board[0] << "|" << board[1] << "|" << board[2] << std::endl
		<< board[3] << "|" << board[4] << "|" << board[5] << CLOSEUNDERLINE << std::endl
		<< board[6] << "|" << board[7] << "|" << board[8] << std::endl;
}

void Game::set(char mark, int index) {
	board[index] = mark;
}

char Game::get(int index) {
	return board[index];
}