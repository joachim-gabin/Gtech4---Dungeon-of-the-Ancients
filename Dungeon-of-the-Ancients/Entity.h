#pragma once

#include <vector>

class Entity
{
public:
	Entity();
	Entity(std::vector<int>);

	virtual void LoseHealth(int);
	bool DeathCheck();

	std::vector<int> m_pos;
	char m_character;
	int m_damage;

protected:
	int m_health;

};