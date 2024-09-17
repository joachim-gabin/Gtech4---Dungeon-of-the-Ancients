#pragma once

class Entity
{
public:
	Entity();
	Entity(int);

	virtual void LooseHealth(int);
	bool DeathCheck();

protected:
	int m_health;
	int m_damage;
	int m_pos;
	char m_character;
};