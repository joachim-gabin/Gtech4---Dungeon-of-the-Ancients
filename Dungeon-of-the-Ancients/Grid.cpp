#include "Grid.h"

//constexpr auto grille =
//"       "
//" H    G"
//"       ";

Grid::Grid()
{	
	char grid[3][15][15] = {
		{
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{'H', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
		},
		{
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'F', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
		},
		{
			{' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'H'},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
		}
	};

	hero.m_pos = { 7, 0 };
	hero.m_character = 'H';

	for (int i = 0; i < levelCount; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				m_grid[i][j][k] = grid[i][j][k];
			}
		}
	}
}

void Grid::SetGridSize(int newSize)
{
	m_size = newSize;
}

void Grid::PrintGrid()
{
	PrintWall();
	for (int line = 0; line < m_size; line++) {
		PrintLine(line);
		PrintWall();
	}
}

bool Grid::CheckDistanceToEntity(std::vector<int> position, int distance, Entity entity)
{
	return std::abs(entity.m_pos[0] - position[0]) + std::abs(entity.m_pos[1] - position[1]) <= distance;
}

void Grid::PrintLine(int line)
{
		std::cout << "|";
		for (int column = 0; column < m_size; column++) {
			bool distanceToHero = CheckDistanceToEntity({ line, column }, 1, hero);
			if (distanceToHero && m_grid[currentLevel][line][column] == ' ') {
				std::cout << "\033[44m";
				Tile tile(' ');
				std::cout << "\033[0m";
			}
			else {
				Tile tile(m_grid[currentLevel][line][column]);
			}
			std::cout << "|";
		}
		std::cout << std::endl;
}

void Grid::PrintWall()
{
	std::cout << "+";
	for (int i = 0; i < m_size; i++) {
		std::cout << "---+";
	}
	std::cout << std::endl;
}

void Grid::Move(std::vector<int> movement, Entity& entity)
{
	SwapSymbol(entity, movement);
}

void Grid::SwapSymbol(Entity& entity, std::vector<int> movement)
{
	if (entity.m_pos[0] + movement[0] < 0 || entity.m_pos[0] + movement[0] >= m_size || entity.m_pos[1] + movement[1] < 0 || entity.m_pos[1] + movement[1] >= m_size)
		return;

	if (m_grid[currentLevel][entity.m_pos[0] + movement[0]][entity.m_pos[1] + movement[1]] != ' ')
		return;

	m_grid[currentLevel][entity.m_pos[0]][entity.m_pos[1]] = ' ';
	entity.m_pos[0] += movement[0];
	entity.m_pos[1] += movement[1];
	m_grid[currentLevel][entity.m_pos[0]][entity.m_pos[1]] = entity.m_character;
}

void Grid::SetNewHeroPos()
{
	for (int i = 0; i < levelCount; i++) {
		for (int j = 0; j < size; j++) {
			if (m_grid[currentLevel][i][j] = 'H') {
				hero.m_pos = { i, j };
			}
		}
	}
}


void Grid::ChangeLevel()
{
	currentLevel++;
	SetNewHeroPos();
}

char Grid::GetCharacter(std::vector<int> pos)
{
	return m_grid[currentLevel][pos[0]][pos[1]];
}

void Grid::ClearTile(std::vector<int> position)
{
	m_grid[currentLevel][position[0]][position[1]] = ' ';
}
