#pragma once
class Game
{
	char curr_player = 'X', winner = '\n';
	int input;
	char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

	void drawBoard();
	void set(char&, int&);
	char get(int&);
	bool validateInput(int&);
	char mainLoop();
	char evaluateWinner(char&, int&);
	void intInput(int&);
	void nextPlayer();
	void printBoardList();

	public:
		void start();
};