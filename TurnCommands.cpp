#include "TurnCommands.h"

vector<string> TurnCommands::commandSetter(vector<int> legalityChecker)
{
	for (size_t commandOrderCheck = 0; commandOrderCheck < legalityChecker.size(); commandOrderCheck++)
	{
		switch (legalityChecker[commandOrderCheck])
		{
		case 0:
				commandOrder++;
				commandOne = " " + to_string(commandOrder) + ". Move North ";
				playerCommands.push_back(commandOne);
			break;
		case 1:
				commandOrder++;
				commandTwo = " " + to_string(commandOrder) + ". Move East ";
				playerCommands.push_back(commandTwo);
			break;
		case 2:
				commandOrder++;
				commandThree = " " + to_string(commandOrder) + ". Move South ";
				playerCommands.push_back(commandThree);
			break;
		case 3:
				commandOrder++;
				commandFour = " " + to_string(commandOrder) + ". Move West ";
				playerCommands.push_back(commandFour);
			break;
		case 4:
			commandOrder++;
			commandFive = " " + to_string(commandOrder) + ". Enter the Door ";
			playerCommands.push_back(commandFive);
			break;
		/*case 5:
			if (legalityChecker[commandOrderCheck] == -1)
			{
				commandOrder++;
				commandSix = " " + to_string(commandOrder) + ". Search mysterious Item ";
				playerCommands.push_back(commandSix);
			}
			break;
		case 6:
			if (legalityChecker[commandOrderCheck] == -1)
			{
				commandOrder++;
				commandSeven = " " + to_string(commandOrder) + ". Enter Door to next area ";
				playerCommands.push_back(commandSeven);
			}
			break;
		case 7:
			if (legalityChecker[commandOrderCheck] == -1)
			{
				commandOrder++;
				commandEight = " " + to_string(commandOrder) + ". Attack the closest Enemy ";
				playerCommands.push_back(commandEight);
			}
			break;*/

		default:
			turnSkip = " You are unable to make any moves this turn ";
			playerCommands.push_back(turnSkip);
			break;
		}
	}
	legalityChecker.clear();
	return playerCommands;
}

void TurnCommands::commandDisplayer(vector<string> playerCommands)
{

	for (size_t i = 0; i < playerCommands.size(); i++)
	{
		cout << playerCommands[i] << endl;
	}
}

int TurnCommands::commandDecider()
{
	int chosenCommand;
	cout << "which Command would you like to preform " << endl;
	//cin >> chosenCommand;

	charInputValidator(chosenCommand);
	while (chosenCommand < 0 || chosenCommand > playerCommands.size())
	{
		cin.clear(); // clear the error flags
		cin.ignore(INT_MAX, '\n'); // discard the row
		cout << "Invalid input, Try entering a value from the commands: ";
		cin >> chosenCommand;
		charInputValidator(chosenCommand);
	}
	if (chosenCommand > 0 || chosenCommand < playerCommands.size())
	{
		return chosenCommand;
	}

}

void TurnCommands::charInputValidator(int& chosenCommand)
{
	while (!(cin >> chosenCommand))
	{
		cin.clear(); // clear the error flags
		cin.ignore(INT_MAX, '\n'); // discard the row
		cout << "Invalid input, Try entering a value from the commands: ";
	}
}

int TurnCommands::moveNorth(int row, int col, char(*boards)[43])
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			if (boards[j][i] == '@')
			{
				boards[j][i] = '.';
				boards[j - 1][i] = '@';
				return 2;
			}
		}
	}
}

int TurnCommands::moveEast(int row, int col, char(*boards)[43])
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			if (boards[j][i] == '@')
			{
				boards[j][i] = '.';
				boards[j][i + 1] = '@';
				return 2;
			}
		}
	}
}

int TurnCommands::moveSouth(int row, int col, char(*boards)[43])
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			if (boards[j][i] == '@')
			{
				boards[j][i] = '.';
				boards[j + 1][i] = '@';
				return 2;
			}
		}
	}
}

int TurnCommands::moveWest(int row, int col, char(*boards)[43])
{
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			if (boards[j][i] == '@')
			{
				boards[j][i] = '.';
				boards[j][i - 1] = '@';
				return 2;
			}
		}
	}
}

void TurnCommands::turnCommandsBoardUpdater(int row, int col, char(*boards)[43])
{
	ofstream newBoard;
	newBoard.open("UpdatedBoard");
	for (size_t j = 0; j < row; j++)
	{
		for (size_t i = 0; i < col; i++)
		{
			newBoard << boards[j][i];
		}
		newBoard << endl;
	}
	newBoard.close();
}

int TurnCommands::doorEntered()
{
	return 0;
}

int TurnCommands::commandExecution(int ChosenCommand, char boards[13][43], int row, int col/*, vector<string> playerCommands*/)
{
	int phase;
	if (playerCommands[ChosenCommand - 1] == commandOne)//move north
	{
		phase = moveNorth(row, col, boards);
	}
	if (playerCommands[ChosenCommand - 1] == commandTwo)//move east
	{
		phase = moveEast(row, col, boards);
	}
	if (playerCommands[ChosenCommand - 1] == commandThree)//move south
	{
		phase = moveSouth(row, col, boards);
	}
	if (playerCommands[ChosenCommand - 1] == commandFour)//move west
	{
		phase = moveWest(row, col, boards);
	}
	if (playerCommands[ChosenCommand - 1] == commandFive)//enter door
	{
		phase = doorEntered();
	}
	playerCommands.clear();
	commandOrder = 0;
	turnCommandsBoardUpdater(row, col, boards);
	return phase;
}
