#pragma once
#include "Entity.h"
#include "Golem.h"
#include "Faucheur.h"
#include "Spectre.h"
#include "Grid.h"

#include <list>
//#include <cstdlib>

class Game
{
	public:

		Game();
		void SetGameState(bool);
		bool GetGameState();

		void GameLoop();

	private:

		bool GameState;
		std::list<Entity> m_enemyList;
};