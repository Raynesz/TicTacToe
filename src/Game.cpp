#include <iostream>
#include <climits>
#include "Game.h"

#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

char Game::evaluateWinner(char& player, int& input) {
	int index = input - 1;


	return 'D';
}

char Game::mainLoop() {
	while (winner == '\n') {
		drawBoard();
		printBoardList();
		std::cout << std::endl << "Player " << curr_player << ": ";
		intInput(input);
		if (validateInput(input)) {
			if (input == -1) {
				return 'E';
			}
			else {
				set(curr_player, input);
			}
			//winner = evaluateWinner(player, input);
			nextPlayer();
		}
		else {
			std::cout << std::endl << "!!! Please provide valid input. !!!" << std::endl;
		}
	}
	return winner;
}

void Game::nextPlayer() {
	curr_player == 'X' ? curr_player = 'O' : curr_player = 'X';
}

void Game::intInput(int& input) {
	std::cin >> input;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> input;
	}
	input--;
}

bool Game::validateInput(int& input) {
	bool a = false, b = false;

	for (int i = -1; i < 9; i++) {
		if (input == i) {
			a = true;
			break;
		}
	}

	if (a) {
		if (input == -1) {
				b = true;
			}
		else {
			if (board[input] == ' ') {
				b = true;
			}
		}
	}

	return a && b;
}

void Game::start() {
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

void Game::set(char& mark, int& index) {
	board[index] = mark;
}

char Game::get(int& index) {
	return board[index];
}

void Game::printBoardList() {
	for (int i = 0; i < 9; i++) {
		std::cout << i + 1 << " : " << get(i) << std::endl;
	}
}