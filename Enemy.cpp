#include "Enemy.h"
#include "TurnCommands.h"
#include "Player.h"

void Enemy::enemyStatUpdate()
{


}

bool Enemy::playerFollow(vector<int> enemyPlayerTracker, int row, int col, char boards[13][43])
{
	bool attackState = false;
	if (enemyPlayerTracker.size() > 0)
	{
		for (size_t moveDistance = 0; moveDistance < 4; moveDistance++)
		{
			switch (enemyPlayerTracker[0])
			{
			case 0:
				enemyMoveNorth(row, col, boards);
				break;
			case 1:
				enemyMoveEast(row, col, boards);
				break;
			case 2:
				enemyMoveSouth(row, col, boards);
				break;
			case 3:
				enemyMoveWest(row, col, boards);
				break;
			default:
				break;
			}
		}
		enemyPlayerTracker.clear();
		return attackState = true;
	}
	else
	{
		return attackState = false;
	}
	
}

int Enemy::enemyAttack()//bool attackState)
{
	return 0;
}

int Enemy::directionSelector(vector<int> enemyMovementChecker)
{
	int directionSeleted;
	int decreaser;
	srand(time(NULL));
	directionSeleted = (rand() % 8) / 2;
	while (enemyMovementChecker.size() == 3 && directionSeleted >= 3)
	{
		directionSeleted = (rand() % 8) / 2;
		//cout << "size 3" + directionSeleted << endl;
	}
	while (enemyMovementChecker.size() == 2 && directionSeleted >= 2)
	{
		directionSeleted = (rand() % 8) / 2;
		//cout << "size 2" + directionSeleted << endl;
	}
	while (enemyMovementChecker.size() == 1 && directionSeleted > 1)
	{
		directionSeleted = 0;
		//cout << "size 1" + directionSeleted << endl;
	}
	return enemyMovementChecker[directionSeleted];
}

int Enemy::enemyMovemntExacutor(int directionSelected, int row, int col, char boards[13][43])
{
	TurnCommands boardUpdate;
	int phase;
	switch (directionSelected)
	{
	case 0:
		phase = enemyMoveNorth(row, col, boards);
		break;
	case 1:
		phase = enemyMoveEast(row, col, boards);
		break;
	case 2:
		phase = enemyMoveSouth(row, col, boards);
		break;
	case 3:
		phase = enemyMoveWest(row, col, boards);
		break;
	default:
		break;
	}
	directionSelected = NULL;
	enemyMovementChecker.clear();
	boardUpdate.turnCommandsBoardUpdater(row, col, boards);
	return phase;
}

int Enemy::enemyMoveNorth(int row, int col, char(*boards)[43])
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			if (boards[j][i] == 'F')
			{
				if (boards[j - 1][i] != '.')
				{
					return 1;
				}
				boards[j][i] = '.';
				boards[j - 1][i] = 'F';
				return 1;
			}
		}
	}
}

int Enemy::enemyMoveEast(int row, int col, char(*boards)[43])
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			if (boards[j][i] == 'F')
			{
				if (boards[j][i + 1] != '.')
				{
					return 1;
				}
				boards[j][i] = '.';
				boards[j][i + 1] = 'F';
				return 1;
			}
		}
	}
}

int Enemy::enemyMoveSouth(int row, int col, char(*boards)[43])
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			if (boards[j][i] == 'F')
			{
				if (boards[j + 1][i] != '.')
				{
					return 1;
				}
				boards[j][i] = '.';
				boards[j + 1][i] = 'F';
				return 1;
			}
		}
	}
}

int Enemy::enemyMoveWest(int row, int col, char(*boards)[43])
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			if (boards[j][i] == 'F')
			{
				if (boards[j][i - 1] != '.')
				{
					return 1;
				}
				boards[j][i] = '.';
				boards[j][i - 1] = 'F';
				return 1;
			}
		}
	}
}

void Freezer::spawnBlocker(char boards [13][43], int row, int col)
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			if (boards[j][i] == 'F')
			{
				for (size_t c = 0; i < 4; c++)
				{
					switch (c)
					{
					case 0:
						if (boards[j + 3][i] == '@' && boards[j + 1][i] != '|' && boards[j + 1][i] != '_' && boards[j + 1][i] != 'L' && boards[j + 1][i] != 'O' && boards[j + 1][i] != '?' && boards[j + 1][i] != 'b' && boards[j + 1][i] != 'D')//check east
						{
							boards[j+1][i] == 'b';//spawn block
							cout << blockSpawnQuote << endl;
						}
						break;

					case 1:
						if (boards[j - 3][i] == '@' && boards[j - 1][i] != '|' && boards[j - 1][i] != '_' && boards[j - 1][i] != 'L' && boards[j - 1][i] != 'O' && boards[j - 1][i] != '?' && boards[j - 1][i] != 'b' && boards[j - 1][i] != 'D')//check west
						{
							boards[j - 1][i] == 'b';//spawn block
							cout << blockSpawnQuote << endl;
						}
						break;

					case 2:
						if (boards[j][i + 3] == '@' && boards[j][i + 1] != '|' && boards[j][i + 1] != '_' && boards[j][i + 1] != 'L' && boards[j][i + 1] != 'O' && boards[j][i + 1] != '?' && boards[j][i + 1] != 'b' && boards[j][i + 1] != 'D')//check north
						{
							boards[j][i + 1] == 'b';//spawn block
							cout << blockSpawnQuote << endl;
						}
						break;

					case 3:
						if (boards[j][i - 3] == '@' && boards[j][i - 1] != '|' && boards[j][i - 1] != '_' && boards[j][i - 1] != 'L' && boards[j][i - 1] != 'O' && boards[j][i - 1] != '?' && boards[j][i - 1] != 'b' && boards[j][i - 1] != 'D')//check south
						{
							boards[j][i - 1] == 'b';//spawn block
							cout << blockSpawnQuote << endl;
						}
						break;

					default:
						break;
					}
				}
			}
		}
	}
}

void Oven::spawnLoafs()
{

}

void Loaf::playerActionFatigue()
{

}