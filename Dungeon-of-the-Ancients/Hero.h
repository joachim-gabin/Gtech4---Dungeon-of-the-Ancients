#pragma once
#include "Entity.h"

class Hero : public Entity
{
public:
	Hero();
	void UpHealth(int);
	void UpAttack(int);
};

