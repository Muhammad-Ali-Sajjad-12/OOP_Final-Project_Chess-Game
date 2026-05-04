/* Board class manages three things:
1- Place all pieces at correct position
2- Show the board on console screen
3- Move piece from one square to other
Board contains all pieces
*/
#pragma once
#include"Piece.h"
#include"Pawn.h"
#include"Rook.h"
#include"Bishop.h"
#include"Knight.h"
#include"Queen.h"
#include"King.h"

class Board
{
private:
	Piece* grid[8][8];//The 8x8 Grid of Piece Pointers

public:
	Board();//To set up the board

	~Board();//For cleaning all PIECES from memory

	void display();//For displaying board

	bool isValidMove(int fromRow, int fromCol,int toRow, int toCol,char currentPlayer);//For checking if a move is valid (this is not a overridden function)

	bool movePiece(int fromRow, int fromCol, int toRow, int toCol, char currentPlayer);//To move piece on board

	bool isKingCaptured(char color);//Checking if King of either color is captured or not

	Piece* getGrid(int row, int col);//Getter for Grid (required for Game Class)
};