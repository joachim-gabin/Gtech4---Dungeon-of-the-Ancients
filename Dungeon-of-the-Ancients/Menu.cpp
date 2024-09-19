#include "Menu.h"
#include <iostream>
#include <windows.h>



Menu::Menu(OptionnalValue* opt)
{
    option = opt;
}

void Menu::MainMenu()
{
    std::cout << "1 : Start\n";
    std::cout << "2 : Option\n";
    std::cout << "3 : Quit\n";
    std::cin >> Answer;

    while (Answer != 1 || Answer != 2 || Answer != 3)
    {
        std::cout << "Wrong input, choose 1,2 or 3 \n";
        std::cin >> Answer;
    }

}

void Menu::MenuOption()
{
    std::cout << "1 : Hero\n";
    std::cout << "2 : Golem\n";
    std::cout << "3 : Spectre\n";
    std::cout << "4 : Faucheur\n\n";
    std::cout << "5 : Retour\n";

    std::cout << "What Entity you want to change : ";
    std::cin >> Answer;

    while (Answer != 1 || Answer != 2 || Answer != 3 || Answer != 4 || Answer != 5)
    {
        std::cout << "Wrong input, choose 1 ~ 5 \n";
        std::cin >> Answer;
    }

    switch (Answer)
    {
    case 1:

    default:
        break;
    }
}

void Menu::MenuLoop()
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

    StartGame = false;
    std::cout << "1 : Start\n";
    std::cout << "2 : Option\n";
    std::cout << "3 : Quit\n";


    while (!StartGame)
    {
        MainMenu();

        switch (Answer)
        {

            case 1:
                StartGame = true;
                break;

            case 2:
                MenuOption();
                break;

            case 3:
                exit(0);
                break;

        default:
            break;
        }
    }

}
