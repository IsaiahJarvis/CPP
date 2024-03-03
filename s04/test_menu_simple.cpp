//test_menu_simple.cpp
//A test driver for the Student::Menu class.

#include <iostream>
#include <string>
using namespace std;

#include "utilities.h"
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;

#include "menu.h"

int main()
{
    extern const string MY_ID_INFO;
    DisplayOpeningScreen(MY_ID_INFO, "\nSubmission 04\nImplementing "
        "a Simple Student::Menu Class");

    {
        Student::Menu menuDefault;
        menuDefault.display();
        Pause();

        menuDefault.setTitle("A New Title for the Default Menu");
        menuDefault.display();
        Pause();
    }

    {
        Student::Menu menu;
        menu.setTitle("Menu");
        menu.display();
        Pause();
        menu.addOption("Quit");
        menu.display();
        Pause();
        menu.addOption("Get information");
        menu.display();
        Pause();
        menu.addOption("Do something");
        menu.display();
        Pause();
        menu.addOption("Do something else");
        menu.display();
        Pause();
    }

    Student::Menu menu1;
    menu1.display();
    menu1.getChoice();

    Student::Menu menu2;
    menu2.setTitle("Another Menu");
    menu2.addOption("Quit");
    menu2.addOption("Get information");
    menu2.addOption("Do something");
    menu2.addOption("Do something else");
    int menuChoice;
    do
    {
        menu2.display();
        menuChoice = menu2.getChoice();
        switch (menuChoice)
        {
        case 1:
            Pause(0, "\nNow quitting from this menu.");
            break;
        case 2:
            Pause(0, "\nGetting information ... ");
            break;
        case 3:
            Pause(0, "\nNow doing something ... ");
            break;
        case 4:
            Pause(0, "\nNow doing something else ... ");
            break;
        default:
            Pause(0, "\nAn invalid menu choice was returned."
                "\nPlease try again.");
            break;
        }
    }
    while (menuChoice != 1);

    Pause(0, "No further tests.\nProgram will now terminate.\nThe "
        "destructors of the last two menus will then execute.");
}

