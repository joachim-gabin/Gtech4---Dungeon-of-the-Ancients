#include "Menu.h"
#include <iostream>
#include <windows.h>
#include <vector>



Menu::Menu(OptionnalValue* opt)
{
    option = opt;
}

void Menu::MainMenu()
{
    std::system("cls");
    PrintTitle();
    std::cout << "1 : Start\n";
    std::cout << "2 : Option\n";
    std::cout << "3 : Quit\n";
    std::cin >> Answer;

    while (Answer != 1 && Answer != 2 && Answer != 3)
    {
        std::cout << "Wrong input, choose 1,2 or 3 \n";
        std::cin >> Answer;
    }

}

void Menu::MenuOption()
{
    std::system("cls");
    PrintTitle();

    std::cout << "1 : Hero\n";
    std::cout << "2 : Golem\n";
    std::cout << "3 : Spectre\n";
    std::cout << "4 : Faucheur\n";
    std::cout << "5 : Back to menu\n\n";

    std::cout << "What Entity you want to change : ";
    std::cin >> Answer;

    switch (Answer)
    {
    case 1:
        PrintTitle();
        std::cout << "Insert Hero's life : ";
        std::cin >> Answer;
        option->HeroHealth = Answer;
        std::cout << "Insert Hero's damage : ";
        std::cin >> Answer;
        option->HeroDamage = Answer;
        MenuOption();
        break;

    case 2:
        PrintTitle();
        std::cout << "Insert Golem life : ";
        std::cin >> Answer;
        option->GolemHealth = Answer;
        std::cout << "Insert Golem damage : ";
        std::cin >> Answer;
        option->GolemDamage = Answer;
        MenuOption();
        break;

    case 3:
        PrintTitle();
        std::cout << "Insert Spectre life : ";
        std::cin >> Answer;
        option->SpectreHealth = Answer;
        std::cout << "Insert Spectre damage : ";
        std::cin >> Answer;
        option->SpectreDamage = Answer;
        MenuOption();
        break;

    case 4:
        PrintTitle();
        std::cout << "Insert Faucheur life : ";
        std::cin >> Answer;
        option->FaucheurHealth = Answer;
        std::cout << "Insert Faucheur damage : ";
        std::cin >> Answer;
        option->FaucherDamage = Answer;
        MenuOption();
        break;

    default:
        break;
    }

}

void Menu::MenuLoop()
{

    StartGame = false;

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
    std::system("cls");

}

void Menu::PrintTitle()
{
    std::system("cls");
    std::string asciiArt =
        " _____                                              __   _   _                                _            _       \n"
        "|  __ \\                                            / _| | | | |              /\\              (_)          | |      \n"
        "| |  | |_   _ _ __   __ _  ___  ___  _ __     ___ | |_  | |_| |__   ___     /  \\   _ __   ___ _  ___ _ __ | |_ ___  \n"
        "| |  | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\   / _ \\|  _| | __| '_ \\ / _ \\   / /\\ \\ | '_ \\ / __| |/ _ \\ '_ \\| __/ __| \n"
        "| |__| | |_| | | | | (_| |  __/ (_) | | | | | (_) | |   | |_| | | |  __/  / ____ \\| | | | (__| |  __/ | | | |_\\__ \\ \n"
        "|_____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|  \\___/|_|    \\__|_| |_|\\___| /_/    \\_\\_| |_|\\___|_|\\___|_| |_|\\__|___/ \n"
        "                     __/ |                                                                                          \n"
        "                     |___/        \n\n";

    std::cout << asciiArt;

}
