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

void Game::PrintHeroStats()
{
	std::cout << "=============================================================" << std::endl << std::endl << "	Hero" << std::endl << "	            Health : ";
	for (int i = 0; i < 20; i++) {
		std::cout << "\033[31m" << static_cast<char>(254) << "\033[0m";
	}
	std::cout << std::endl << std::endl << "=============================================================";
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

		bool IAPlay = false;
		while(IAPlay)
		{
			//for each(Entity enemie in Grid.EnemyList)
				
				//if(enemie.DeathCheck())
					//TODo fonction de bonus pour mort des enemies

				//elif(enemie.detectPlayer())
					//Grid.Hero.LoseHealth(enemie.m_damage)

				//else Grid.Movement(enemie.StateMachine()))
		}

		//if(Grid.Hero.CheckDeath())
			//GameState = false;

		std::system("cls");
		grid.PrintGrid();
		PrintHeroStats();
	}
}



