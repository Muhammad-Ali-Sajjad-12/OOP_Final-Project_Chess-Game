#pragma once
#include<iostream>
using namespace std;

class Piece
{
protected:
	char color;//'W = White' & 'B = Black'
	char symbol;//P=Pawn, R=Rook, B=Bishop, Q=Queen, K=King, N=Knight
	int row, col;//Board Position

public:
	Piece(char color, char symbol, int row, int col);
	char getColor();
	char getSymbol();
	char getRow();
	char getCol();
	void setPosition(int r, int c);
	virtual bool isValidMove(int toRow, int toCol, Piece* board[8][8]) = 0;//Making it Pure Virtual (Which means it cannot be defined in base class but must be implemented in derived classes)
	virtual ~Piece();//DESTRUCTOR-Virtual bcz it can help in calling the appropriate Piece's Destructor first then of base class 
};