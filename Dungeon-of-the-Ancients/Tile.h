#pragma once

#include <iostream>
#include <vector>
#include <string>

/**
* The representation of a Tile of the grid.
*/
class Tile
{
public:
	Tile(char);
	char GetSymbol();
	void PrintTile(char);

	char m_symbol;

private:
};