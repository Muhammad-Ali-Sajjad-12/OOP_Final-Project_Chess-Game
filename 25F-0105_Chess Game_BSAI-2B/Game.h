/*
Game Class is the BRAIN of the program as it handles three things:
1- Alternate TURNS between WHITE & BLACK
2- Input moves from the user in chess notation
3- Check for WIN (If the KING is killed or not)
*/
#pragma once
#include"Board.h"
#include<string>

class Game
{
private:
	Board board;//Composition
	char currentPlayer;//Tracking turns (W=WHITE or B=BLACK)
	bool gameOver;//For checking if game is still running
	//Some METHODS only required for GAME class
	bool parseInput(string input, int& row, int& col);//For converting chess notation(i.e 'a2' for row=6 & column=0)
	void switchTurn();
	void displayTurn();

public:
	Game();
	void start();//For starting the game
};