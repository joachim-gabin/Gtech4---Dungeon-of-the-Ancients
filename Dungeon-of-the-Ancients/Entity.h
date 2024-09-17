#pragma once

#include <vector>

class Entity
{
public:
	Entity();
	Entity(std::vector<int>);

	virtual void LooseHealth(int);
	bool DeathCheck();

	std::vector<int> m_pos;
	char m_character;

protected:
	int m_health;
	int m_damage;
};