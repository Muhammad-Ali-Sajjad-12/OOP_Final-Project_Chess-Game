#pragma once
#include"Piece.h"

class Bishop : public Piece
{
public:
	Bishop(char color, int row, int col);
	bool isValidMove(int toRow, int toCol, Piece* board[8][8])override;
};