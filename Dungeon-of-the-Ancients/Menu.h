#pragma once
#include <cstdlib>
#include "OptionnalValue.h"

class Menu
{
public:
	Menu(OptionnalValue*);
	void MainMenu();
	void MenuOption();
	void MenuLoop();

	bool StartGame = false;
	int Answer = 0;
	OptionnalValue* option;
	void PrintTitle();

};