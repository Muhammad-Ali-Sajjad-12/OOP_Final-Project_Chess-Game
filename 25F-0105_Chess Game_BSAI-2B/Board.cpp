#include"Board.h"

//Cnstructor - For initializing board
Board::Board()
{
	//Initializing Board and placing all PIECES
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			grid[r][c] = nullptr;//Initialize Piece

	//Placing BLACK pieces at the top of Board
	//In Order: Rook Knight Bishop Queen King Bishop Knight Rook
	grid[0][0] = new Rook('B', 0, 0);
	grid[0][1] = new Knight('B', 0, 1);
	grid[0][2] = new Bishop('B', 0, 2);
	grid[0][3] = new Queen('B', 0, 3);
	grid[0][4] = new King('B', 0, 4);
	grid[0][5] = new Bishop('B', 0, 5);
	grid[0][6] = new Knight('B', 0, 6);
	grid[0][7] = new Rook('B', 0, 7);

	//Black Pawns in ROW # 1
	for (int c = 0; c < 8; c++)
		grid[1][c] = new Pawn('B', 1, c);

	//Placing WHITE pieces in last and 2nd last Rows (i.e 6 & 7)
	grid[7][0] = new Rook('W', 7, 0);
	grid[7][1] = new Knight('W', 7, 1);
	grid[7][2] = new Bishop('W', 7, 2);
	grid[7][3] = new Queen('W', 7, 3);
	grid[7][4] = new King('W', 7, 4);
	grid[7][5] = new Bishop('W', 7, 5);
	grid[7][6] = new Knight('W', 7, 6);
	grid[7][7] = new Rook('W', 7, 7);

	//White Pawns in ROW # 6
	for (int c = 0; c < 8; c++)
		grid[6][c] = new Pawn('W', 6, c);
}

//Destructor - Freeing All D.M
Board::~Board()
{
	for(int r=0; r<8; r++)
		for (int c = 0; c < 8; c++)
		{
			if (grid[r][c] != nullptr)
			{
				delete grid[r][c];
				grid[r][c] = nullptr;
			}
		}
}

//Showing BOARD on console screen
void Board::display()
{
	cout << "\n    a   b   c   d   e   f   g   h\n\n";//For COLUMNS
	for (int r = 0; r < 8; r++)
	{
		//Printing Row number on left side
		//Row 0 = number 8 & Row 7 = number 1 (SEQUENCE: Top to bottom 0-7)
		cout << " " << (8 - r) << "  ";

		for (int c = 0; c < 8; c++)
		{
			if(grid[r][c]==nullptr)
				cout << ".   ";//Showing 'DOT' on empty square
			else
			{
				char symbol = grid[r][c]->getSymbol();
				char color = grid[r][c]->getColor();

				/*
				REPRESENTING:
				WHITE pieces: UPPERCASE LETTERS
				BLACK pieces: lowercase LETTERS
				*/
				if (color == 'W')
					cout << (char)toupper(symbol) << "   ";//C++ builtin function to make UPPERCASE
				else
					cout << (char)tolower(symbol) << "   ";
			}
		}
		//Printing Row Number of right side as well
		cout << " " << (8 - r) << "\n\n";
	}
	//Printing COLUMNS on bottom side as well
	cout << "a   b   c   d   e   f   g   h\n\n";
}

//Checking for VALID MOVE
bool Board::isValidMove(int fromRow, int fromCol, int toRow, int toCol, char currentPlayer)
{
	//Checking if square at starting position has a PIECE or no
	if (grid[fromRow][fromCol] == nullptr)
	{
		cout << "    No Piece at that Position!\n";
		return false;
	}

	//Checking if current position piece belongs to current player
	if (grid[fromRow][fromCol]->getColor() != currentPlayer)
	{
		cout << "    That is not your piece!\n";
		return false;
	}

	//Asking the piece itself that is the move valid for it or not
	//This concept caters POLYMORPHISM as the correct 'isValidMove()' is called based on PIECE type
	if (!grid[fromRow][fromCol]->isValidMove(toRow, toCol, grid))//returns true if move is valid then this condition would become false and break
	{//This condition only checks if move is invalid with help of '!-SIGN'
		cout << "    Invalid move for this particular PIECE!\n";
		return false;
	}

	return true;//Otherwise Valid Move
}

bool Board::movePiece(int fromRow, int fromCol, int toRow, int toCol, char currentPlayer)
{
	//This Function helps in executing the move on board

	//Checking for Move Validation
	if(!isValidMove(fromRow,fromCol,toRow,toCol,currentPlayer))
		return false;//If not Valid MOVE
	
	//Checking if Destination has ENEMY PIECE -> ( KILL :( )
	//ADDITIONALLY, the FRIEND PIECE presence is already been confirmed in 'isValidMove()'
	if (grid[toRow][toCol] != nullptr)
	{
		cout << "  " << currentPlayer<< " captures "<< grid[toRow][toCol]->getSymbol()<< "!\n";//ENEMY executred successfully
		delete grid[toRow][toCol];
	}

	//Moving piece to destination
	grid[toRow][toCol] = grid[fromRow][fromCol];

	//Updating Piece's internal position (FROM PIECE Class)
	grid[toRow][toCol]->setPosition(toRow, toCol);

	//Clearing the square from where piece was moved
	grid[fromRow][fromCol] = nullptr;

	return true;//PIECE successfuly moved
}

//Checking whether KING is captured or not
bool Board::isKingCaptured(char color)
{
	//Searching Entire board for KING of given color
	for(int r=0; r<8; r++)
		for (int c = 0; c < 8; c++)
		{
			if (grid[r][c] != nullptr && grid[r][c]->getColor() == color && grid[r][c]->getSymbol() == 'K')
				return false;//King (Alive)
		}

	return true;//King not found (DEAD)
}

//Getter for Grid
Piece* Board::getGrid(int row, int col)
{
	return grid[row][col];
}