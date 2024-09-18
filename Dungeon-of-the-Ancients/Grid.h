#pragma once

#include <vector>
#include <cmath>
#include "Tile.h"
#include "Entity.h"
#include "Hero.h"

/**
 * The game grid which the player and the enemies will move on
 */
class Grid
{

public:
	Grid();
	void SetGridSize(int);
	void PrintGrid();
	void Move(std::vector<int>, Entity&);
	void ChangeLevel();
	char GetCharacter(std::vector<int>);
	bool CheckDistanceToEntity(std::vector<int>, int, Entity);
	void ClearTile(std::vector<int>);
	Hero hero;

	static const int size = 15;
	static const int levelCount = 3;
	char m_grid[levelCount][size][size];

	int currentLevel = 0;

private:

	void SwapSymbol(Entity&, std::vector<int>);
	void SetNewHeroPos();

	void PrintLine(int);
	void PrintWall();
	int m_size = 15;
};