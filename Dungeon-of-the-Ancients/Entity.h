#pragma once
#include "OptionnalValue.h"

#include <vector>

class Entity
{
public:
	Entity();
	Entity(std::vector<int>);
	OptionnalValue option;

	virtual void LoseHealth(int);
	bool DeathCheck();

	std::vector<int> m_pos;
	char m_character;
	int m_health;
	int m_damage;
};