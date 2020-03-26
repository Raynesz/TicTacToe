#pragma once
class Game
{
	char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };

	void drawBoard();
	void set(char, int);
	bool validateInput(char&);
	int mainLoop();

	public:
		void start();
};