#include "Rook.h"

Rook::Rook(char color, int row, int col): Piece(color,'R', row, col) {}

bool Rook::isValidMove(int toRow, int toCol, Piece* board[8][8])
{
	int fromRow = getRow();
	int fromCol = getCol();
	char myColor = getColor();

	/*
	- - - ROOK MOVEMENT INFO. - - -
	Rook must move in straight line only and if a piece blocks its path Rook cannot jump over it
	Either the row changes OR the column changes  (never both)
	If both row and column change ? diagonal move ? invalid for Rook
	*/

	bool movingInRow = (toRow != fromRow && toCol == fromCol);//To move vertically that is changing rows (This returns true or false)
	bool movingInCol = (toCol != fromCol&& toRow == fromRow);//To move horizontally that is columns chage

	//Checking for diagonal path which are invalid to move
	if (!movingInRow && !movingInCol)
		return false;//False bcz diagonal movement is not allowed

	//Checking if a piece is blocking Rook's movement bcz Rook can't jump over and it stops moving further
	//Firstly for Row Movement
	if (movingInRow) 
	{
		//Checking if moving UP or DOWN
		int step = (toRow > fromRow) ? 1 : -1;//'1' for up and vice versa

		//For-Loop below checks each square in way that either it is occupied or not
		for (int r = fromRow + step; r != toRow; r += step)
			if (board[r][fromCol] != nullptr)
				return false;//IF some piece is present
	}

	//Now, for the Column Movement
	if (movingInCol)
	{
		//Checking if moving RIGHT or LEFT
		int step = (toCol > fromCol) ? 1 : -1;//'1' for RIGHT and vice versa

		for (int c = fromCol+ step; c != toCol; c += step)
			if (board[fromRow][c] != nullptr)
				return false;
	}

	//Checking for Destination that if
	//1- Destination is EMPTY (MOVE)
	//2- Destination has enemy piece (KILL)
	//3- Destiantion has friendly piece (INVALID; Change track)
	if (board[toRow][toCol] == nullptr)
		return true;//Empty square
	if (board[toRow][toCol]->getColor() != myColor)
		return true;//Capturing enemy
	
	return false;//Destination has friendly piece
}