#include"King.h"
#include<cmath>

King::King(char color, int row, int col): Piece(color,'K',row,col) {}

bool King::isValidMove(int toRow, int toCol, Piece* board[8][8])
{
	int fromRow = getRow();
	int fromCol = getCol();
	char myColor = getColor();

	
	/*
	- - - KING MOVEMENT INFO. - - -
	King can move in all directions but only one square at a time.
	King cannot capture its own Piece
	King can capture the ENEMY
	*/

	//Checking for number of squares moved only irrespective of the direction (SAME AS KNIGHT & BISHOP)
	int rowDiff = abs(toRow - fromRow);
	int colDiff = abs(toCol - fromCol);

	/* 
	King can move at least in one direction either row or column but its
	rowDiff & colDiff cannot be zero at the same time which indicates no movement
	*/

	//Checking for these zero movement and more than one square movement error conditions
	//These conditions check all the possible 8 directions
	//As if there is rowDiff=1 & colDiff=1 then the direction indicates towards the diagonal movement
	//2- if rowDiff=1 & colDiff=0 (UP/DOWN)
	//3- if rowDiff=0 & colDiff=1 (RIGHT/LEFT)
	if (rowDiff > 1 || colDiff > 1)
		return false;//Trying to move more than one square
	if (rowDiff == 0 && colDiff == 0)
		return false;

	//Checking DESTINATION Square
	if (board[toRow][toCol] == nullptr)//Checking empty square
		return true;
	if (board[toRow][toCol]->getColor() != myColor)//ENEMY SQUARE check
		return true;

	//FRIENDLY PIECE in between (INVALID)
	return false;
}