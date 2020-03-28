#include <iostream>
#include <climits>
#include "Game.h"

#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

void Game::evaluateWinner() {
	if (turns > 4) {
		if (turns == 9) {
			winner = 'D';
			return;
		}
		else {
			switch (input) {
			case 0:
				if (triple(0, 1, 2)) break;
				if (triple(0, 3, 6)) break;
				if (triple(0, 4, 8)) break;
				break;
			case 1:
				if (triple(0, 1, 2)) break;
				if (triple(1, 4, 7)) break;
				break;
			case 2:
				if (triple(0, 1, 2)) break;
				if (triple(2, 5, 8)) break;
				if (triple(2, 4, 6)) break;
				break;
			case 3:
				if (triple(3, 4, 5)) break;
				if (triple(0, 3, 6)) break;
				break;
			case 4:
				if (triple(3, 4, 5)) break;
				if (triple(2, 5, 8)) break;
				if (triple(0, 4, 8)) break;
				if (triple(2, 4, 6)) break;
				break;
			case 5:
				if (triple(3, 4, 5)) break;
				if (triple(2, 5, 8)) break;
				break;
			case 6:
				if (triple(6, 7, 8)) break;
				if (triple(0, 3, 6)) break;
				if (triple(2, 4, 6)) break;
				break;
			case 7:
				if (triple(6, 7, 8)) break;
				if (triple(1, 4, 7)) break;
				break;
			case 8:
				if (triple(6, 7, 8)) break;
				if (triple(2, 5, 8)) break;
				if (triple(0, 4, 8)) break;
				break;
			default:
				break;
			}
		}
	}
	return;
}

bool Game::triple(int x, int y, int z) {
	if (board[x] == board[y] && board[x] == board[z]) {
		winner = curr_player;
		return true;
	}
	else {
		return false;
	}
}

void Game::mainLoop() {
	while (winner == '\n') {
		drawBoard();
		printBoardList();
		std::cout << std::endl << "Player " << curr_player << ": ";
		intInput();
		if (validateInput()) {
			if (input == -1) {
				winner = 'E';
				return;
			}
			else {
				set(curr_player, input);
				turns++;
			}
			evaluateWinner();
			nextPlayer();
		}
		else {
			std::cout << std::endl << "!!! Please provide valid input. !!!" << std::endl;
		}
	}
	return;
}

void Game::nextPlayer() {
	curr_player == 'X' ? curr_player = 'O' : curr_player = 'X';
	return;
}

void Game::intInput() {
	std::cin >> input;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cin >> input;
	}
	input--;
	return;
}

bool Game::validateInput() {
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
	mainLoop();
	switch(winner) {
	case 'D':
		std::cout <<"Draw!!" << std::endl;
		break;
	case 'E':
		std::cout << "You exited the game." << std::endl;
		break;
	default:
		std::cout << winner << " wins!!" << std::endl;
	}
	std::cout << "----------- GAME END -----------" << std::endl;
	return;
}

void Game::drawBoard() {
	std::cout << std::endl << UNDERLINE << board[6] << "|" << board[7] << "|" << board[8] << CLOSEUNDERLINE << std::endl
		<< UNDERLINE << board[3] << "|" << board[4] << "|" << board[5] << CLOSEUNDERLINE << std::endl
		<< board[0] << "|" << board[1] << "|" << board[2] << std::endl;
	return;
}

void Game::set(char& mark, int& index) {
	board[index] = mark;
	return;
}

char Game::get(int& index) {
	return board[index];
}

void Game::printBoardList() {
	for (int i = 0; i < 9; i++) {
		std::cout << i + 1 << " : " << get(i) << std::endl;
	}
	return;
}