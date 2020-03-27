#pragma once
class Game
{
	char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };

	void drawBoard();
	void set(char, int);
	char get(int index);
	bool validateInput(char&);
	char mainLoop();
	char evaluateWinner(char&);

	public:
		void start();
};