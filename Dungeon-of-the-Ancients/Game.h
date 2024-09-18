#pragma once
#include "Entity.h"
#include "Golem.h"
#include "Faucheur.h"
#include "Spectre.h"
#include "Grid.h"
#include "Hero.h"

#include <list>
//#include <cstdlib>

class Game
{
	public:

		Game();
		void SetGameState(bool);
		void CreateEntity(char, std::vector<int>);
		void SetEnemyList();
		bool GetGameState();

		void GameLoop();

	private:
		Grid grid;
		bool GameState;
		std::list<Entity> m_enemyList;
};