#pragma once

#include <vector>
#include <cmath>
#include "Tile.h"

/**
 * The game grid which the player and the enemies will move on
 */
class Grid
{

public:
	Grid();
	void SetGridSize(int);
	void PrintGrid();
	bool Move(std::vector<int>);
	void ChangeLevel();

private:
	void FindHero();
	std::vector<int> m_heroPos;

	void PrintLine(int);
	void PrintWall();
	int m_size = 15;

	static const int size = 15;
	static const int levelCount = 3;
	char m_grid[levelCount][size][size];

	int currentLevel = 0;
};