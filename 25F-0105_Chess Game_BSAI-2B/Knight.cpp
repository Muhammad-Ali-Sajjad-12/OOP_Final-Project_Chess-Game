#include"Knight.h"
#include<cmath>

Knight::Knight(char color, int row, int col): Piece(color,'N',row, col) {}

bool Knight::isValidMove(int toRow, int toCol, Piece* board[8][8])
{
	int fromRow = getRow();
	int fromCol = getCol();
	char myColor = getColor();

	/*
	- - - KNIGHT MOVEMENT INFO. - - -
	Knight moves in 'L-Shape' and important thing is that it can jump over other pieces.
	Two Possible Movement Options:
	1- Two squares in one direction + one square sideways
	2- One square in one direction + two squares sideways
	*/

	//Checking for how many squares we have to move in each direction
	int rowDiff = abs(toRow - fromRow);//'abs()' used bcz we don't care about direction, just checking number of squares moved
	int colDiff = abs(toCol- fromCol);

	//Checking for 'L-Shape'
	bool isLShape = (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);//Returns true only on valid L-Shape movement

	if (!isLShape)
		return false;

	//Checking three posibilities for Destination
	//1- Destination is empty (MOVE)
	if (board[toRow][toCol] == nullptr)
		return true;
	//2- Destination has Enemy piece (KILL)
	if (board[toRow][toCol]->getColor()!=myColor)
		return true;
	//3- Destination has Friend (Invalid)
	return false;
}
