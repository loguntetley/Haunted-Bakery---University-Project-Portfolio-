#include "BakeryBoard.h"

int BakeryBoard::boardSelecter()
{
	if (roomCounter < 1)
	{
		doorNum = 0;
	}
	else
	{
		srand(time(NULL));
		doorNum = (rand() % 8) / 2 + 1;
	}
	return doorNum;
}

int BakeryBoard::roomCounterFunc()
{
	return roomCounter++;
}

char BakeryBoard::boardInitializer(int doorNum, char boards[13][43])
{
	if (gameBoard.is_open())
	{
		gameBoard.trunc;
		gameBoard.close();
	}
	roomCounterFunc();
	switch (doorNum)
	{
	case 0:
		gameBoard.open("StartingRoom.txt");
		break;
	case 1:
		gameBoard.open("ConjoiningRoom.txt");
		break;
	case 2:
		gameBoard.open("MainRoomOne.txt");
		break;
	case 3:
		gameBoard.open("EmptyRoom.txt");
		break;
	case 4:
		gameBoard.open("BlankRoom.txt");
		break;
	default:
		break;
	}

	if (gameBoard.fail())
	{
		cerr << "File Error When Opening" << endl;
		exit(1);
	}

	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			gameBoard.get(boards[j][i]);
		}
	}
}

int BakeryBoard::boardPrint(char boards[13][43])
{
	int phase;
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			cout << boards[j][i];
		}
		cout << endl;
	}
	if (roomCounterFunc() == 10)
	{
		return 3;
	}
	return phase = 1;
}

void BakeryBoard::boardNorthCheck(char(*boards)[43], const size_t& j, const size_t& i, std::vector<int>& legalityChecker)
{
	if (boards[j][i] == '@')
	{
		if (boards[j - 1][i] == '.')//checks north for blank
		{
			legalityChecker.push_back(0);
			return;
		}
	}
}

void BakeryBoard::boardEastCheck(char(*boards)[43], const size_t& j, const size_t& i, std::vector<int>& legalityChecker)
{
	if (boards[j][i] == '@')
	{
		if (boards[j][i + 1] == '.')//checks east for blank
		{
			legalityChecker.push_back(1);
			return;
		}
	}
}

void BakeryBoard::boardSouthCheck(char(*boards)[43], const size_t& j, const size_t& i, std::vector<int>& legalityChecker)
{
	if (boards[j][i] == '@')
	{
		if (boards[j + 1][i] == '.')//checks south for blank
		{
			legalityChecker.push_back(2);
			return;
		}
	}
}

void BakeryBoard::boardWestCheck(char(*boards)[43], const size_t& j, const size_t& i, std::vector<int>& legalityChecker)
{
	if (boards[j][i] == '@')
	{
		if (boards[j][i - 1] == '.')//checks west for blank
		{
			legalityChecker.push_back(3);
			return;
		}
	}
}

void BakeryBoard::doorCheck(char(*boards)[43], const size_t& j, const size_t& i, std::vector<int>& legalityChecker)
{
	if (boards[j][i] == '@')
	{
		if (boards[j - 1][i] == 'D' || boards[j + 1][i] == 'D' || boards[j][i - 1] == 'D' || boards[j][i + 1] == 'D')//checks for doors
		{
			legalityChecker.push_back(4);
		}
	}
}

vector<int> BakeryBoard::boardChecker(char boards[13][43], vector<int> legalityChecker)
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			if (boards[j][i] == '@')
			{
				boardNorthCheck(boards, j, i, legalityChecker);
				boardEastCheck(boards, j, i, legalityChecker);
				boardSouthCheck(boards, j, i, legalityChecker);
				boardWestCheck(boards, j, i, legalityChecker);
				doorCheck(boards, j, i, legalityChecker);
				return legalityChecker;
			}
		}
	}
}

void BakeryBoard::boardUpdater(int row, int col, char boards[13][43])
{
	gameBoard.open("UpdatedBoard");

	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			gameBoard.get(boards[j][i]);
		}
	}

	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			cout << boards[j][i];
		}
		cout << endl;
	}
	return;
}