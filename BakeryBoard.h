#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class BakeryBoard
{
private:
	int doorNum = 0, roomCounter = -1;
	ifstream gameBoard;

	void boardNorthCheck(char(*boards)[43], const size_t& j, const size_t& i, std::vector<int>& legalityChecker);
	void boardEastCheck(char(*boards)[43], const size_t& j, const size_t& i, std::vector<int>& legalityChecker);
	void boardSouthCheck(char(*boards)[43], const size_t& j, const size_t& i, std::vector<int>& legalityChecker);
	void boardWestCheck(char(*boards)[43], const size_t& j, const size_t& i, std::vector<int>& legalityChecker);
	void doorCheck(char(*boards)[43], const size_t& j, const size_t& i, std::vector<int>& legalityChecker);

protected:

public:
	static const int row = 13, col = 43;
	char boards[row][col];

	int boardSelecter();
	char boardInitializer(int doorNum, char boards[13][43]);
	int boardPrint(char boards[13][43]);
	vector<int> boardChecker(char boards[13][43], vector<int> legalityChecker);
	void boardUpdater(int row, int col, char boards[13][43]);
	int roomCounterFunc();

};