#pragma once
#include <iostream>
#include "Entity.h"

class Golem : public Entity
{
public:
	Golem(int);
	void LooseHealth(int) override;
};