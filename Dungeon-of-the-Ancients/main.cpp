// Dungeon-of-the-Ancients.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <windows.h>


#include "Game.h"
#include "Menu.h"
#include "OptionnalValue.h"

int main()
{
    OptionnalValue option;

    bool quite = false;
    while (!quite)
    {
        Menu menu(&option);
        menu.MenuLoop();
        Game game;
        game.GameLoop();
        std::system("cls");
    }


    return 0;
}