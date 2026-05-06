#include"Game.h"

int main()
{
	Game gameObj;//This automatically creates the Chess board with 32 pieces aligned in their position

	gameObj.start();//Runs until the KING gets KILLED!

	system("pause");
	return 0;
}