#pragma once
#include <iostream>
#include "Entity.h"

class Golem : public Entity
{
public:
	Golem(std::vector<int>);
	void LooseHealth(int) override;
};