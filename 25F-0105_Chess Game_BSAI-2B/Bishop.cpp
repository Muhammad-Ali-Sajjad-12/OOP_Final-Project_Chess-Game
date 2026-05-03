#include"Bishop.h"
#include<cmath>

Bishop::Bishop(char color, int row, int col): Piece(color,'B',row,col) {}

bool Bishop::isValidMove(int toRow, int toCol, Piece* board[8][8])
{
    int fromRow = getRow();
    int fromCol = getCol();
    char myColor = getColor();

	/*
	- - - BISHOP MOVEMENT INFO. - - -
	Bishop moves DIAGONALLY only in any direction, provided any number of square
	but like Rook it cannot jump over pieces in its path 
	Additionally, Bishop only moves when number of columns and rows in a diagonal are equal.
	*/

	//Checking for Number of squares moved in each direction irrespective of specific direction sign.
	int rowDiff = abs(toRow - fromRow);//'abs()' - just to count number of squares without any specific direction 
	int colDiff = abs(toCol- fromCol);

	//Checking DIAGONAL MOVE (i.e SAME number of rows and columns)
	if (rowDiff != colDiff)
		return false;

	//Checking DIRECTION (i.e either UP/DOWN or LEFT/RIGHT)
	int rowStep = (toRow > fromRow) ? 1 : -1;//1= DOWN, -1=UP
	int colStep = (toCol> fromCol) ? 1 : -1;//1=RIGHT, -1=LEFT

	//Checking if there is any PIECE in our path or no
	int r = fromRow + rowStep;//indicates ROW movement
	int c = fromCol + colStep;//indicates COL movement

	while (r != toRow && c != toCol)//CONDITION: untill they reach their fixed destination
	{
		if (board[r][c] != nullptr)//Checking for piece in way
			return false;

		//Moving one step further if no piece in between
		r += rowStep;
		c += colStep;
	}

	//Checking for DESTINATION
	//if EMPTY square (MOVE)
	if (board[toRow][toCol] == nullptr)
		return true;
	//if ENEMY PIECE (KILL)
	if (board[toRow][toCol]->getColor() != myColor)
		return true;
	//if FRIEND PIECE (INVALID)
	return false;
}