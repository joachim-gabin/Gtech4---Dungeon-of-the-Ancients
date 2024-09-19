#include "Hero.h"
Hero::Hero()
{
	m_character = 'H';
	m_damage = option.HeroDamage;
	m_health = option.HeroHealth;
}

void Hero::UpHealth(int health)
{
	if(m_health + health > option.HeroHealth)
		m_health = option.HeroHealth;

	else
		m_health = health;
}

void Hero::UpAttack(int damage)
{
	m_damage += damage;
}

