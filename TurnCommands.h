#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class TurnCommands
{
private:
	int commandOrder;
	string commandOne, commandTwo, commandThree, commandFour, commandFive, turnSkip;
	
	int moveNorth(int row, int col, char(*boards)[43]);
	int moveEast(int row, int col, char(*boards)[43]);
	int moveSouth(int row, int col, char(*boards)[43]);
	int moveWest(int row, int col, char(*boards)[43]);
	int doorEntered();


public:
	vector<string> playerCommands;
	vector<int> legalityChecker;
	
	vector<string> commandSetter(vector<int> legalityChecker);
	void commandDisplayer(vector<string> playerCommands);
	int commandDecider();
	void charInputValidator(int& chosenCommand);
	void turnCommandsBoardUpdater(int row, int col, char(*boards)[43]);
	int commandExecution(int ChosenCommand, char board[13][43], int row, int col/*, vector<string> playerCommands*/);
	
};