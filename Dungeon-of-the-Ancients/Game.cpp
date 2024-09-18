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
	int faucheurChoice = 0;
	int spectreChoice = 0;
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
			if (spectreChoice == 0)		//move y
			{
				if (grid.hero.m_pos[0] > enemy.m_pos[0])
				{
					if (CheckSpace(enemy, { -1, 0 }))
					{
						return { -1, 0 };
					}
					spectreChoice++;
				}
				else
				{
					if (CheckSpace(enemy, { 1, 0 }))
					{
						return { 1, 0 };
					}
					spectreChoice++;
				}
			}

			else if (spectreChoice == 1)					//move x
			{
				if (grid.hero.m_pos[1] > enemy.m_pos[1])
				{
					if (CheckSpace(enemy, { 0, -1 }))
					{
						return { 0, -1 };
					}
					spectreChoice++;
				}
				else
				{
					if (CheckSpace(enemy, { 0, 1 }))
					{
						return { 0, 1 };
					}
					spectreChoice++;
				}
			}
			else
			{
				//TODO put attackplayer function
				return { 0, 0 };
			}
			break;

		case 'F':			//Faucheur
		{

			if (faucheurChoice == 0)		//move y
			{
				if (grid.hero.m_pos[0] > enemy.m_pos[0])
				{
					if (CheckSpace(enemy, { 1, 0 }))
					{
						return std::vector<int>(1, 0);
					}
					faucheurChoice++;
				}
				else
				{
					if (CheckSpace(enemy, { -1, 0 }))
					{
						return std::vector<int>(-1, 0);
					}
					faucheurChoice++;
				}
			}
			else							//move x
			{
				if (grid.hero.m_pos[1] > enemy.m_pos[1])
				{
					if (CheckSpace(enemy, { 0, 1 }))
					{
						return std::vector<int>(1, 0);
					}
					faucheurChoice++;
				}
				else
				{
					if (CheckSpace(enemy, { 0, -1 }))
					{
						return std::vector<int>(-1, 0);
					}
					faucheurChoice++;
				}
			}
			break;
		}

		default:
			return { 0,0 };	//default not moving
			break;
		}
		}



		return { 0, 0 };
	}
}

void Game::PrintEntityStats(Entity entity)
{
	std::cout << "=============================================================" << std::endl << std::endl << entity.m_character << std::endl << "	       Health : ";
	for (int i = 0; i < 20; i++) {
		std::cout << "\033[31m" << static_cast<char>(254) << "\033[0m";
	}
	std::cout << std::endl << "	       Damage : " << std::endl << "=============================================================";
}

void Game::PrintHeroStats()
{
	std::cout << "=============================================================" << std::endl << std::endl << "	Hero" << std::endl << "	       Health : ";
	for (int i = 0; i < 20; i++) {
		std::cout << "\033[31m" << static_cast<char>(254) << "\033[0m";
	}
	std::cout << std::endl << "	       Damage : " << std::endl << "=============================================================";
}

void Game::EnemyDeathCapacity(Grid grid, Entity enemie)
{
	switch (enemie.m_character)
	{
		case 'G':
		{
			grid.hero.UpAttack(1);
		}
		case 'S':
		{
			grid.hero.UpHealth(10);
		}
		case 'F':
		{
			for (Entity enemie : m_enemyList)
			{
				int randomDamage = 1 + std::rand() % 3;
				enemie.LoseHealth(randomDamage);
			}
		}

	default:
		break;
	}
}

void Game::HeroAttack()
{
	int heroX = grid.hero.m_pos[1];
	int heroY = grid.hero.m_pos[0];

	for (Entity enemy : m_enemyList)
	{
		if (enemy.m_pos[0] == heroY + 1 || enemy.m_pos[0] == heroY - 1 || enemy.m_pos[1] == heroX + 1 || enemy.m_pos[1] == heroX - 1)
		{
			grid.hero.LoseHealth(enemy.m_damage);
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
		m_enemyList.push_back(golem);
		break;
	}

	case 'F':
	{
		Faucheur faucheur(position);
		faucheur.m_character = symbol;
		m_enemyList.push_back(faucheur);
		break;
	}

	case 'S':
	{
		Spectre spectre(position);
		spectre.m_character = symbol;
		m_enemyList.push_back(spectre);
		break;
	}

	case 'H':
	{
		Hero hero;
		hero.m_character = symbol;
		hero.m_pos = position;
		m_enemyList.push_back(hero);
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



void Game::GameLoop()
{
	SetEnemyList();
	grid.PrintGrid();
	PrintHeroStats();
	SetGameState(true);
	while (GameState)
	{

		bool playerPlay = true;
		while (playerPlay)
		{
			//TODO teste -32
			char ch = _getch(); // Lire la touche pressée
			ch = _getch(); // Lire le code de la touche spéciale

			switch (ch) {
				case 72: // Haut
					std::cout << "Flèche Haut" << std::endl;

					grid.Move({ -1, 0 }, grid.hero);
					playerPlay = false;
					break;

				case 80: // Bas
					std::cout << "Flèche Bas" << std::endl;

					grid.Move({ 1, 0 }, grid.hero);
					playerPlay = false;
					break;

				case 75: // Gauche
					std::cout << "Flèche Gauche" << std::endl;

					grid.Move({ 0, -1 }, grid.hero);
					playerPlay = false;
					break;

				case 77: // Droite
					std::cout << "Flèche Droite" << std::endl;

					grid.Move({ 0, 1 }, grid.hero);
					playerPlay = false;
					break;

				case 13: // Entrer - Attack
					std::cout << "Entrer" << std::endl;

					playerPlay = false;
					break;
			}		
		}

		bool IAPlay = true;
		while(IAPlay)
		{
			for (Entity& enemie : m_enemyList)
			{

				if (enemie.DeathCheck())			//check if entity is dead
				{
					EnemyDeathCapacity(grid, enemie);
					IAPlay = false;
				}


				else if (grid.CheckDistanceToEntity(grid.hero.m_pos, 1, enemie))		//Check if Hero is close to be attacked
				{
					grid.hero.LoseHealth(enemie.m_damage);
				}


				else								//move to new location
				{
					grid.Move(EnemyMoveCheck(grid, enemie), enemie);
					IAPlay = false;
				}
			}
		}

		if(grid.hero.DeathCheck())			//if player dead end the game
			GameState = false;

		else if (m_enemyList.size() == 0)	//if no enemies alive start new level
		{
			grid.ChangeLevel();
		}

		std::system("cls");
		grid.PrintGrid();
		PrintHeroStats();
	}
}



