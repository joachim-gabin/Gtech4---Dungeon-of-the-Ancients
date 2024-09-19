#pragma once
#include "Entity.h"
#include "Golem.h"
#include "Faucheur.h"
#include "Spectre.h"
#include "Grid.h"
#include "Hero.h"

#include <list>
#include <chrono>
#include <thread>
#include <cstdlib>

class Game
{
	public:

		Game();
		void SetGameState(bool);
		void CreateEntity(char, std::vector<int>);
		void SetEnemyList();
		bool CheckSpace(Entity, std::vector<int>);
		bool GetGameState();
		void PrintEntityStats(Entity* entity);
		void PrintHeroStats();
		void EnemyDeathCapacity(Grid&, Entity);
		void HeroAttack();
		std::vector<int> EnemyMoveCheck(Grid, Entity);


		void GameLoop();

	private:
		Grid grid;
		bool GameState;
		std::vector<Entity> m_enemyList;
		Entity* closeEntity = nullptr;

		void PlayerTurn();
		void EnemyTurn();
};