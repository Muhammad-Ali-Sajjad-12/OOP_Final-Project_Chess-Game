/* IMPLEMENTATION of Piece.h */
#include"Piece.h"

Piece::Piece(char color, char symbol, int row, int col):color(color), symbol(symbol), row(row), col(col) {}

char Piece::getColor()
{
	return color;
}

char Piece::getSymbol()
{
	return symbol;
}

char Piece::getRow()
{
	return row;
}

char Piece::getCol()
{
	return col;
}

void Piece::setPosition(int r, int c)
{
	row = r;
	col = c;
}