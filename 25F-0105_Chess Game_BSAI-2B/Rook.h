#pragma once
#include"Piece.h"

class Rook : public Piece
{
public:
	Rook(char color, int row, int col);
	bool isValidMove(int toRow, int toCol, Piece* board[8][8])override;
};