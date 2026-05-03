#pragma once
#include"Piece.h"

class Pawn :public Piece
{
public:
	Pawn(char color, int row, int col);//Constructor
	
	//Overriding Movement Validation from Base class
	bool isValidMove(int toRow, int toCol, Piece* board[8][8])override;
};