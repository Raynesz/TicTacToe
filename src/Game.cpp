#include <iostream>
#include <climits>
#include "Game.h"

#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

char Game::evaluateWinner(char& player) {
	return 'D';
}

char Game::mainLoop() {
	int input;
	char player = 'X', winner = '\n';
	while (winner == '\n') {
		drawBoard();

		for (int i = 0; i < 9; i++) {
			std::cout << i+1 << " : " << get(i) << std::endl;
		}

		std::cout << std::endl << "Player " << player << ": ";

		intInput(input);

		if (validateInput(input)) {
			if (input == 0) {
				return 'E';
			}
			else {
				set(player, input);
			}
			//winner = evaluateWinner(player);
			player == 'X' ? player = 'O' : player = 'X';
		}
		else {
			std::cout << std::endl << "!!! Please provide valid input. !!!" << std::endl;
		}
	}
	return winner;
}

void Game::intInput(int& input) {
	do {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> input;
	} while (std::cin.fail());
}

bool Game::validateInput(int& input) {
	bool a = false, b = false;
	int index = input-1;

	for (int i = -1; i < 9; i++) {
		if (index == i) {
			a = true;
			break;
		}
	}

	if (a) {
		if (index == -1) {
				b = true;
			}
		else {
			if (board[index] == ' ') {
				b = true;
			}
		}
	}

	return a && b;
	//return a;
}

void Game::start() {
	int winner;

	std::cout << "----------- GAME START -----------" << std::endl;
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
	std::cout << std::endl << UNDERLINE << board[6] << "|" << board[7] << "|" << board[8] << CLOSEUNDERLINE << std::endl
		<< UNDERLINE << board[3] << "|" << board[4] << "|" << board[5] << CLOSEUNDERLINE << std::endl
		<< board[0] << "|" << board[1] << "|" << board[2] << std::endl;
}

void Game::set(char& mark, int& input) {
	int index = input - 1;
	board[index] = mark;
}

char Game::get(int& input) {
	return board[input];
}