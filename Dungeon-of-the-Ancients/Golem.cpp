#include "Golem.h"

Golem::Golem(std::vector<int> pos)
{
	m_pos = pos;
	m_character = 'G';
	m_damage = 2;
	m_health = 5;
}

void Golem::LoseHealth(int damage)
{
	int DamageChance = std::rand() % 11;
	if (DamageChance < 8)
		m_health -= damage;
}