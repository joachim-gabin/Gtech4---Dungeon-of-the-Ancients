#include "Tile.h"
#include <iostream>

Tile::Tile(char symbol)
{
	m_symbol = symbol;
	PrintTile(symbol);
}

void Tile::PrintTile(char symbol)
{
	switch (symbol) {
	case 'H':
		std::cout << "\033[32m";
		break;
	case 'G':
		std::cout << "\033[31m";
		break;
	case 'S':
		std::cout << "\033[31m";
		break;
	case 'F':
		std::cout << "\033[31m";
		break;
	default:
		break;
	}
	std::cout << " " << symbol << " \033[0m";
}
