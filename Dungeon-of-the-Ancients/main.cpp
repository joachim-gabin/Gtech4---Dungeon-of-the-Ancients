// Dungeon-of-the-Ancients.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <cstdlib>
#include "Game.h"

int main()
{

    std::string asciiArt =
        " _____                                              __   _   _                                _            _       \n"
        "|  __ \\                                            / _| | | | |              /\\              (_)          | |      \n"
        "| |  | |_   _ _ __   __ _  ___  ___  _ __     ___ | |_  | |_| |__   ___     /  \\   _ __   ___ _  ___ _ __ | |_ ___  \n"
        "| |  | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\   / _ \\|  _| | __| '_ \\ / _ \\   / /\\ \\ | '_ \\ / __| |/ _ \\ '_ \\| __/ __| \n"
        "| |__| | |_| | | | | (_| |  __/ (_) | | | | | (_) | |   | |_| | | |  __/  / ____ \\| | | | (__| |  __/ | | | |_\\__ \\ \n"
        "|_____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|  \\___/|_|    \\__|_| |_|\\___| /_/    \\_\\_| |_|\\___|_|\\___|_| |_|\\__|___/ \n"
        "                     __/ |                                                                                          \n"
        "                     |___/        \n";

    std::cout << asciiArt;
    bool quite = false;
    while (!quite)
    {
        Game game;
        game.GameLoop();
        std::system("cls");
    }

    /*Grid grid;
    grid.PrintGrid();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::system("cls");
    grid.Move({ 4, 3 }, );
    grid.PrintGrid();*/


    return 0;
}