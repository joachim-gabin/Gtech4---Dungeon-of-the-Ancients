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

/*
void Game::SetEnemyList()
{
	int EnemyAmount = std::rand() % 3;

	for (int i = 0; i < EnemyAmount; i++)
	{
		int randomPosition = std::rand() % 3;
		Golem golem(randomPosition);
		m_enemyList.push_back(golem);
	}	

	int random = std::rand() % 3;

	for (int i = 0; i < random; i++)
	{
		int randomPosition = std::rand() % 3;
		Spectre spectre(randomPosition);
		m_enemyList.push_back(spectre);
	}	

	int random = std::rand() % 3;

	for (int i = 0; i < random; i++)
	{
		int randomPosition = std::rand() % 3;
		Faucheur faucheur(randomPosition);
		m_enemyList.push_back(faucheur);
	}

}
*/

void Game::GameLoop()
{
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

					playerPlay = false;
					break;

				case 80: // Bas
					std::cout << "Flèche Bas" << std::endl;

					playerPlay = false;
					break;

				case 75: // Gauche
					std::cout << "Flèche Gauche" << std::endl;

					playerPlay = false;
					break;

				case 77: // Droite
					std::cout << "Flèche Droite" << std::endl;

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
			//for each(Entity enemie in Grid.EnemyList)
				
				//if(enemie.DeathCheck())
					//TODo fonction de bonus pour mort des enemies

				//elif(enemie.detectPlayer())
					//Grid.Hero.LoseHealth(enemie.m_damage)

				//else Grid.Movement(enemie.StateMachine()))
		}

		//if(Grid.Hero.CheckDeath())
			//GameState = false;




	}
}


