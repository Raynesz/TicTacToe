#pragma once
class Game
{
	char curr_player = 'X', winner = '\0';
	int input = 9, turns = 0;
	char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

	void drawBoard();
	void set(char&, int&);
	char get(int&);
	bool validateInput();
	void mainLoop();
	void evaluateWinner();
	void intInput();
	void nextPlayer();
	void printBoardList();
	bool triple(int, int, int);

	public:
		void start();
};