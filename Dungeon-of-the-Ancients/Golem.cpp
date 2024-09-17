#include "Golem.h"

Golem::Golem(int pos)
{
	m_pos = pos;
}

void Golem::LooseHealth(int damage)
{
	int NoDamageChance = std::rand() % 11;
	if (NoDamageChance < 5)
		m_health -= damage;
}