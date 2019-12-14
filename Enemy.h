#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Enemy
{
private:


	
	int enemyMoveNorth(int row, int col, char(*boards)[43]);
	int enemyMoveEast(int row, int col, char(*boards)[43]);
	int enemyMoveSouth(int row, int col, char(*boards)[43]);
	int enemyMoveWest(int row, int col, char(*boards)[43]);

protected:
	int health, damage;
	char enemyIcon;
	
	

public:
	//void enemyStatUpdate();
	
	int directionSelector(vector<int> enemyMovementChecker);
	int enemyMovemntExacutor(int directionSelected, int row, int col, char boards[13][43]);
	bool playerFollow(vector<int> enemyPlayerTracker, int row, int col, char boards[13][43]);
	int enemyAttack();

};

class Freezer : public Enemy
{
private:
	char enemyIcon = 'F';
	string blockSpawnQuote = "The Freezer has spawned a block of ice blocking your path ";

protected:
	//int health = 5, damage = 1;

public:
	void spawnBlocker(char board[13][43], int row, int col);

};

class Oven : public Enemy
{
private:
	char enemyIcon = 'O';

protected:
	//int health = 10, damage = 2;

public:
	void spawnLoafs();

};

class Loaf : public Enemy
{
private:
	char enemyIcon = 'L';

protected:
	//int health = 1, damage = 1;

public:
	void playerActionFatigue();

};

