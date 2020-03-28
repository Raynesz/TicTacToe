#pragma once
class Game
{
	char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

	void drawBoard();
	void set(char&, int&);
	char get(int&);
	bool validateInput(int&);
	char mainLoop();
	char evaluateWinner(char&);

	public:
		void start();
};