// Dungeon-of-the-Ancients.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <chrono>
#include <thread>
#include "Grid.h"

int main()
{
    std::string dun = " _____                                              __   _   _                                _            _       \n";
    std::string ge = "|  __ \\                                            / _| | | | |              /\\              (_)          | |      \n";
    std::string on = "| |  | |_   _ _ __   __ _  ___  ___  _ __     ___ | |_  | |_| |__   ___     /  \\   _ __   ___ _  ___ _ __ | |_ ___  \n";
    std::string of = "| |  | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\   / _ \\|  _| | __| '_ \\ / _ \\   / /\\ \\ | '_ \\ / __| |/ _ \\ '_ \\| __/ __| \n";
    std::string the = "| |__| | |_| | | | | (_| |  __/ (_) | | | | | (_) | |   | |_| | | |  __/  / ____ \\| | | | (__| |  __/ | | | |_\\__ \\ \n";
    std::string an = "|_____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|  \\___/|_|    \\__|_| |_|\\___| /_/    \\_\\_| |_|\\___|_|\\___|_| |_|\\__|___/ \n";
    std::string ci = "                     __/ |                                                                                          \n";
    std::string ents = "                     |___/        ";
    std::cout << dun << ge << on << of << the << an << ci << ents;
    /*Grid grid;
    grid.PrintGrid();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::system("cls");
    grid.Move({ 4, 3 });
    grid.PrintGrid();*/


    return 0;
}