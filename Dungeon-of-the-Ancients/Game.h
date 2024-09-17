#pragma once
#include "Entity.h"
#include "Hero.h"
#include "Golem.h"
#include "Faucheur.h"
#include "Spectre.h"

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
		Hero m_Hero;
		std::list<Entity> m_enemyList;
};