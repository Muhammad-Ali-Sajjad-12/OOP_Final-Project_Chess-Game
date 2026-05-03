#pragma once
#include"Piece.h"
//Since Queen has combined movement of Rook & Bishop, so we use their movement instead of rewriting
#include"Rook.h"
#include"Bishop.h"

class Queen : public Piece
{
public:
	Queen(char color, int row, int col);
	bool isValidMove(int toRow, int toCol, Piece* board[8][8])override;
};