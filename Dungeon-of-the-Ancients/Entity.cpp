#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(std::vector<int> pos)
{
	m_pos = pos;
}

void Entity::LoseHealth(int damage)
{

}

bool Entity::DeathCheck()
{
	if(m_health <= 0)
		return true;

	return false;
}
