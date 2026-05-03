#pragma once
#include"Piece.h"

class Knight : public Piece
{
public:
	Knight(char color, int row, int col);
	bool isValidMove(int toRow, int toCol, Piece* board[8][8])override;
};