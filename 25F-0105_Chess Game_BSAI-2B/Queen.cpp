#include"Queen.h"

Queen::Queen(char color, int row, int col) : Piece(color, 'Q', row, col) {}

bool Queen::isValidMove(int toRow, int toCol, Piece* board[8][8])
{
    int fromRow = getRow();
    int fromCol = getCol();
    char myColor = getColor();

	/*
	- - - QUEEN MOVEMENT INFO. - - -
	Queen has combined movement of Rook and Bishop (i.e straight lines, and diagonal lines)
	So instead of rewriting we create a temporary Rook & Bishop at same position 
	and check if this move is valid for them; if yes Queen can move
	*/

	//Temporary Rook at Queen's current position
	Rook tempRook(myColor, fromRow, fromCol);
	//Temporary Bishop at Queen's current position
	Bishop tempBishop(myColor, fromRow, fromCol);

	//Checking that is Rook and Bishop's move is valid
	bool validAsRook = tempRook.isValidMove(toRow, toCol, board);//If yes; Queen can move as Rook to that square 
	bool validAsBishop= tempBishop.isValidMove(toRow, toCol, board);//If yes; Queen can move as Bishop to that square

	return validAsRook || validAsBishop;//If anyone is true Queen can move like it respectively
}