#include"Game.h"

Game::Game()
{
	//As WHITE always go first in chess so CONSTRUCTOR assigns:
	currentPlayer = 'W';
	gameOver = false;
}

/*
For Parse Input some prior DETAILS
as CHESS uses LETTERS for columns and NUMBERS for rows
e.g
columns: a=0,b=1, so on..., h=7
rows: 8=0, 7=1, so on..., 1=7
*/
bool Game::parseInput(string input, int& row, int& col)
{
	//Input must be letter 
	//That is First Character must be LETTERS (a-h)
	//Second Character must be NUMBERS (1-8)
	if (input.length() != 2)//Input validation
		return false;

	//Dealing both input characters separately
	char colChar = input[0];//for Letters
	char rowChar = input[1];//for Numbers

	//Validating Column Letter
	if (colChar < 'a' || colChar>'h')
		return false;//Out of Bounds

	//Validating Row Number
	if (rowChar < '1' || rowChar>'8')
		return false;//Out of Bounds

	//Converting Letter to Column index
	col = colChar - 'a';//e.g 'a' - 'a' = 0, 'b' - 'a' = 1, etc.
	//Same for Row index
	row = 8 - (rowChar - '0');//e.g '8' means row = 0, '1' means row = 7

	return true;//After all parsing is done
}

//Alternating turns between players
void Game::switchTurn()
{
	if (currentPlayer == 'W')
		currentPlayer = 'B';
	else
		currentPlayer = 'W';
}

void Game::displayTurn()
{
	if (currentPlayer == 'W')
		cout << "   WHITE's Turn\n";
	else
		cout << "   BLACK's Turn\n";
}

//Main game loop for Main Interface
void Game::start()
{
	cout << "===============================\n";
	cout << "     CHESS GAME IN C++         \n";
	cout << "     OOP Lab Semester Project  \n";
	cout << "===============================\n\n";
	cout << "  HOW TO ENTER MOVES:\n";
	cout << "  Type column (a-h) + row (1-8)\n";
	cout << "  Example: e2 e4\n";
	cout << "  (move piece FROM e2 TO e4)\n";
	cout << "WHITE pieces: UPPERCASE LETTERS\n";
	cout << "BLACK pieces: LOWERCASE LETTERS\n\n";

	//MAIN GAME LOOP (Keeps running until a KING is Killed)
	while (!gameOver)
	{
		board.display();//Current board state

		displayTurn();//For showing whose turn it is

		//getting inputs from player
		string fromInput;//Starting Point
		string toInput;//Destination

		cout << "   Enter starting Square's position: ";
		cin >> fromInput;

		cout << "   Enter Destination Square's position: ";
		cin >> toInput;

		//input PARSING
		int fromRow, fromCol, toRow, toCol;

		bool fromValid = parseInput(fromInput, fromRow, fromCol);
		bool toValid = parseInput(toInput, toRow, toCol);

		if (!fromValid || !toValid)//Input Validation
		{
			cout << "\nERROR! Invalid Input, use format like a2\n";
			cout << "Try Again!\n";
			continue;
		}

		bool moveMade = board.movePiece(fromRow, fromCol, toRow, toCol, currentPlayer);//For Making the Move

		if (!moveMade)
		{
			//Move Validation Check
			cout << "\nTry Again!\n";
			continue;
		}

		//Checking If KING is captured or Not
		char opponent = (currentPlayer == 'W') ? 'B' : 'W';//TERNARY OPERATOR

		if (board.isKingCaptured(opponent))
		{
			board.display();//Showing Board after Game is finished

			cout << "===============================\n";
			if (currentPlayer == 'W')
				cout << "\nWHITE WINS! BLACK KING CAPTURED\n";
			else
				cout << "\nBLACK WINS! WHITE KING CAPTURED\n";

			gameOver = true;
			break;
		}

		switchTurn();
	}
	cout << "\n\n- - - THANK YOU FOR PLAYING - - -\n";
}