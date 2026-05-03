#include"Pawn.h"
#include<cmath>//For using absolute value function.

Pawn::Pawn(char color, int row, int col) :Piece(color, 'P', row, col) {}

bool Pawn::isValidMove(int toRow, int toCol, Piece* board[8][8])
{
	int fromRow = getRow();
	int fromCol = getCol();
	char myColor = getColor();//Either Black or White

	/*
	White moves up (decreasing row)
	Black moves down (increasing row)
	*/
	int direction = (myColor == 'W') ? -1 : 1;//Using Ternary Operator.

	//One Square Forward Move
	if (toCol == fromCol && toRow == fromRow + direction)//toCol==fromCol (indicates that Pawn doesn't move Left or Right) & toRow==fromRow + direction (indicates that Pawn moves only 1 Step forward)
		if (board[toRow][toCol] == nullptr)//nullptr indicates empty space
			return true;//A Pawn can never move forward if something is blocking

	//Two Square Forward on First Move
	int startRow = (myColor == 'W') ? 6 : 1;//Bcz White color is at 6th row from top to bottom
	//Below If-Condition indicates that Pawn moves two squares forward on first move either from White's side or Black
	if (toCol == fromCol && fromRow == startRow && toRow == fromRow + 2 * direction)//'2*direction' in order to move 2 squares forward from either side
		if (board[toRow][toCol] == nullptr && board[fromRow + direction][fromCol] == nullptr)//To check whether middle and destination square is empty or not.
			return true;

	//Diagonal Move (1 Step forward + 1 Step Sideways)
	/*
	Below if-condition ensures that pawn moves one square forward and moves one square left or right if and only if there is an enemy Piece there.
	*/
	if (toRow == fromRow + direction && abs(toCol - fromCol) == 1 && board[toRow][toCol] != nullptr && board[toRow][toCol]->getColor() != myColor)//'abs' is used to check both left and right capture directions otherwise we had to use two conditions for '+1' and '-1'
		return true;

	//If all possible movement conditions are not available 
	return false;//Invalid Move

	/* - - - ADDITIONAL MOVEMENT INFO. - - -
	Case 1 - Normal move:
		Same column, 1 step forward, destination empty

	Case 2 - First move:
		Same column, currently on start row,
		2 steps forward, both squares empty

	Case 3 - Capture:
		1 step forward + 1 step sideways,
		iff destination has an enemy piece
	*/
}