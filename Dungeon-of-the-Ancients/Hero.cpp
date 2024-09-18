#include "Hero.h"
Hero::Hero()
{
	m_character = 'H';
	m_damage = 2;
	m_MaxHealth = 10;
	m_health = m_MaxHealth;
}

void Hero::UpHealth(int health)
{
	if(m_health + health > m_MaxHealth)
		m_health = m_MaxHealth;

	else
		m_health = health;
}

void Hero::UpAttack(int damage)
{
	m_damage += damage;
}

