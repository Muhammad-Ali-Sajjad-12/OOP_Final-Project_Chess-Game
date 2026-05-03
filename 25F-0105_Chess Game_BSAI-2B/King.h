#pragma once
#include"Piece.h"

class King : public Piece
{
public:
	King(char color, int row, int col);
	bool isValidMove(int toRow, int toCol, Piece* board[8][8])override;
};