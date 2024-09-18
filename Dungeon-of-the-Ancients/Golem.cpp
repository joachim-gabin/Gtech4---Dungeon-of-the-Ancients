#include "Golem.h"

Golem::Golem(std::vector<int> pos)
{
	m_pos = pos;
	m_character = 'G';
	m_damage = 2;
	m_health = 5;
}

void Golem::LooseHealth(int damage)
{
	int NoDamageChance = std::rand() % 11;
	if (NoDamageChance < 5)
		m_health -= damage;
}