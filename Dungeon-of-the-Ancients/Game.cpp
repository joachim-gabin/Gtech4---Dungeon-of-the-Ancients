#include "Game.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>


Game::Game()
{
	GameState = false;
}

void Game::SetGameState(bool state)
{
	GameState = state;
}


bool Game::GetGameState()
{
	return GameState;
}


bool Game::CheckSpace(Entity enemie, std::vector<int> testPos)
{
	if (grid.GetCharacter({ enemie.m_pos[0] + testPos[0], enemie.m_pos[1] + testPos[1]}) == ' ')
	{
		return true;
	}
	return false;
}

std::vector<int> Game::EnemyMoveCheck(Grid grid, Entity enemy)
{
	bool MoveCheck = false;
	while (!MoveCheck)
	{
		switch (enemy.m_character)
		{
		case 'G':			//Golem
		{
			int direction = std::rand() % 4;
			switch (direction)
			{
			case 0:	//haut
				if (CheckSpace(enemy, { -1, 0 }))
				{
					return { -1 ,0 };
				}
			case 1:	//bas
				if (CheckSpace(enemy, { 1, 0 }))
				{
					return { 1 ,0 };
				}
			case 2:	//gauche
				if (CheckSpace(enemy, { 0, -1 }))
				{
					return { 0 ,-1 };
				}
			case 3:	//droite
				if (CheckSpace(enemy, { 0, 1 }))
				{
					return { 0 ,1 };
				}
			default:
				break;
			}
		}


		case 'S':			//Spectre
		{
			if (grid.hero.m_pos[0] > enemy.m_pos[0])
			{
				if (CheckSpace(enemy, { -1, 0 }))
				{
					return { -1, 0 };
				}
			}
			else if (grid.hero.m_pos[0] < enemy.m_pos[0])
			{
				if (CheckSpace(enemy, { 1, 0 }))
				{
					return { 1, 0 };
				}
			}
			else if (grid.hero.m_pos[1] > enemy.m_pos[1])
			{
				if (CheckSpace(enemy, { 0, -1 }))
				{
					return { 0, -1 };
				}
			}
			else if (grid.hero.m_pos[1] < enemy.m_pos[1])
			{
				if (CheckSpace(enemy, { 0, 1 }))
				{
					return { 0, 1 };
				}
			}
			break;
		}
		case 'F':			//Faucheur
		{
			if (grid.hero.m_pos[0] > enemy.m_pos[0])
			{
				if (CheckSpace(enemy, { 1, 0 }))
				{
					return { 1, 0 };
				}
			}
			else if (grid.hero.m_pos[0] < enemy.m_pos[0])
			{
				if (CheckSpace(enemy, { -1, 0 }))
				{
					return { -1, 0 };
				}
			}
			else if (grid.hero.m_pos[1] > enemy.m_pos[1])
			{
				if (CheckSpace(enemy, { 0, 1 }))
				{
					return { 0, 1 };
				}
			}
			else if (grid.hero.m_pos[1] < enemy.m_pos[1])
			{
				if (CheckSpace(enemy, { 0, -1 }))
				{
					return { 0, -1 };
				}
			}
			break;
		}

		default:
			return { 0, 0 };	//default not moving
			break;
	}

		return { 0, 0 };
	}
}

void Game::PrintEntityStats(Entity* entity)
{
	std::cout << "=============================================================" << std::endl << std::endl;

	if (entity) {
		std::cout << "       " << entity->m_character << std::endl << "           Health : ";
		for (int i = 0; i < entity->m_health; i++) {
			std::cout << "\033[31m" << static_cast<char>(254) << "\033[0m";
		}
		std::cout << std::endl << "           Damage : ";
		for (int i = 0; i < entity->m_damage; i++) {
			std::cout << "\033[33m" << static_cast<char>(254) << "\033[0m";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << std::endl << std::endl << std::endl;
	}

	std::cout << "=============================================================" << std::endl;
}

void Game::PrintHeroStats()
{
	std::cout << "=============================================================" << std::endl << std::endl << "	Hero" << std::endl << "	       Health : ";
	for (int i = 0; i < grid.hero.m_health; i++) {
		std::cout << "\033[31m" << static_cast<char>(254) << "\033[0m";
	}
	std::cout << std::endl << "	       Damage : ";
	for (int i = 0; i < grid.hero.m_damage; i++) {
		std::cout << "\033[33m" << static_cast<char>(254) << "\033[0m";
	}
	std::cout << std::endl << "=============================================================";
}

void Game::EnemyDeathCapacity(Grid& grid, Entity enemie)
{
	switch (enemie.m_character)
	{
	case 'G':
	{
		grid.hero.UpAttack(1);
		break;
	}
	case 'S':
	{
		grid.hero.UpHealth(10);
		break;
	}
	case 'F':
	{
		for (Entity* enemie : m_enemyList)
		{
			int randomDamage = 1 + std::rand() % 3;
			enemie->LoseHealth(randomDamage);
		}
		break;
	}

	default:
		break;
	}
}

void Game::HeroAttack()
{
	for (Entity* enemy : m_enemyList)
	{
		if (grid.CheckDistanceToEntity(enemy->m_pos, 1, grid.hero))
		{
			enemy->LoseHealth(grid.hero.m_damage);
		}
	}
}

void Game::CreateEntity(char symbol, std::vector<int> position)
{
	switch (symbol) {
	case 'G':
	{
		Golem golem(position);
		golem.m_character = symbol;
		m_enemyList.push_back(new Golem(golem));
		break;
	}

	case 'F':
	{
		Faucheur faucheur(position);
		faucheur.m_character = symbol;
		m_enemyList.push_back(new Faucheur(faucheur));
		break;
	}

	case 'S':
	{
		Spectre spectre(position);
		spectre.m_character = symbol;
		m_enemyList.push_back(new Spectre(spectre));
		break;
	}

	default:
		break;
	}
}


void Game::SetEnemyList()
{
	for (int i = 0; i < grid.size; i++) {
		for (int j = 0; j < grid.size; j++) {
			if (grid.m_grid[grid.currentLevel][i][j] != ' ') {
				CreateEntity(grid.m_grid[grid.currentLevel][i][j], { i, j });
			};
		}
	}
}


void Game::PlayerTurn()
{
	bool playerPlay = true;
	while (playerPlay)
	{
		//TODO teste -32
		unsigned char ch = _getch(); // Lire la touche pressée
		if (ch == 224)
		{
			ch = _getch(); // Lire le code de la touche spéciale
			switch (ch) {
			case 72: // Haut
				if (!grid.Move({ -1, 0 }, grid.hero))
				{
					continue;
				};
				playerPlay = false;
				break;

			case 80: // Bas
				if (!grid.Move({ 1, 0 }, grid.hero))
				{
					continue;
				};
				playerPlay = false;
				break;

			case 75: // Gauche
				if (!grid.Move({ 0, -1 }, grid.hero))
				{
					continue;
				};
				playerPlay = false;
				break;

			case 77: // Droite
				if (!grid.Move({ 0, 1 }, grid.hero))
				{
					continue;
				};
				playerPlay = false;
				break;
			}
		}
		else
		{
			if (ch == 13)
			{
				HeroAttack();

				playerPlay = false;
			}
		}
	}
}

void Game::EnemyTurn()
{
	bool IAPlay = true;
	while (IAPlay)
	{

		int index = 0;
		int indexToDelete = -1;

		for (Entity* enemy : m_enemyList)
		{
			index++;

			if (enemy->DeathCheck())			//check if entity is dead
			{
				grid.ClearTile(enemy->m_pos);
				indexToDelete = index;
				closeEntity = nullptr;
				EnemyDeathCapacity(grid, *enemy);
				IAPlay = false;
			}
			else if (grid.CheckDistanceToEntity(grid.hero.m_pos, 1, *enemy))		//Check if Hero is close to be attacked
			{
				grid.hero.LoseHealth(enemy->m_damage);
				IAPlay = false;
			}
			else								//move to new location
			{
				grid.Move(EnemyMoveCheck(grid, *enemy), *enemy);

				if (grid.CheckDistanceToEntity(enemy->m_pos, 2, grid.hero.m_pos)) {
					closeEntity = enemy;
				}

				IAPlay = false;
			}
		}
		if (indexToDelete != -1) {
			m_enemyList.erase(m_enemyList.begin() + indexToDelete - 1);
			indexToDelete = -1;
		}
	}
}

void Game::GameLoop()
{
	SetEnemyList();
	PrintEntityStats(closeEntity);
	grid.PrintGrid();
	PrintHeroStats();
	SetGameState(true);
	while (GameState)
	{
		PlayerTurn();
		EnemyTurn();

		if (grid.hero.DeathCheck()) //if player dead end the game
		{
			GameState = false;
		}			

		else if (m_enemyList.size() == 0)	//if no enemies alive start new level
		{
			std::system("cls");
			std::cout << "Level completed!";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			grid.ChangeLevel();
			if (grid.currentLevel == grid.GetLevelCount()) {
				std::system("cls");
				std::cout << "Well done! You beat the game!";
				std::this_thread::sleep_for(std::chrono::seconds(2));
				exit(0);
			}
			SetEnemyList();
		}

		if (closeEntity != nullptr && !grid.CheckDistanceToEntity(closeEntity->m_pos, 2, grid.hero.m_pos)) {
			closeEntity = nullptr;
		}

		
		std::system("cls");
		PrintEntityStats(closeEntity);
		grid.PrintGrid();
		PrintHeroStats();
	}
}




