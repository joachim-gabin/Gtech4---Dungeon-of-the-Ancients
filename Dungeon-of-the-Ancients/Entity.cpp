#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(int pos)
{
	m_pos = pos;
}

void Entity::LooseHealth(int damage)
{

}

bool Entity::DeathCheck()
{
	if(m_health <= 0)
		return true;

	return false;
}
