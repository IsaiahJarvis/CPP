//display_ascii3.cpp
//Jarvis:Isaiah:A00439675:u11
//Submission 03
//Displaying Printable ASCII Characters and Their Codes, Part 3

/*
Program displays opening screen and menu properly and all menu options function
*/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "utilities.h"
#include "AsciiGenerator.cpp"
using Scobey::TextItems;
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;
using Scobey::Menu;
using Scobey::ReadChar;
using Scobey::userSaysYes;

void DisplayProgramInfo();
/**<
Display program description, with a pause at the end of each screen.
*/

void GetInformation();
/**<
Displays information using a text item
*/

void BuildMenu(Menu& menu);
/**<
Sets title of, and adds options to, menu.
@pre menu has been initialized and is empty.
@post menu has a title and four options.
*/

void GetAsciiRangeFromUser(char& firstChar, char& lastChar);
/**<
Gets the end points of the required ASCII range from the user.
@param firstChar The low end of the character interval to be displayed.
@param lastChar	The high end of the character interval to be displayed.
@post The user has entered the low endpoint of the range, which is in
firstChar, and the high endpoint of the range, which is in lastChar,
and firstChar <= lastChar.
*/

int main(int argc, char* argv[])
{
    // variables
    bool finished;
    int choice;
    Menu menu;
    char firstChar, lastChar;

    // display program info
    DisplayProgramInfo();
    
    // build menu
    BuildMenu(menu);

    // do-while loop for menu functionality
    do
    {
        // diplay previously build menu 
        menu.display();
        choice = menu.getChoice();
        finished = (choice == 1 || choice == -1);

        // switch statement for menu functionality
        switch (choice)
        {
        // cases for quitting
        case -1:
        case  1:
            cout << "Now quitting from this menu.\n";
            Pause();
            break;
        // case for getting program info
        case 2:
            GetInformation();
            break;
        // case for displaying ascii chars horizontally
        case 3:
        {
            // do-while for looping if user wants to display new range
            do
            {
                // get range from user then make asciigen obj and display it
                GetAsciiRangeFromUser(firstChar, lastChar);
                AsciiGenerator asciiGen(firstChar, lastChar);
                system("clear");
                asciiGen.displayHorizontally();
            }
            while (userSaysYes("Display another range using this format?"));
        }
        break;
        // case for displaying ascii chars horizontally
        case 4:
        {
            // do-while for looping if user wants to display new range
            do
            {
                // get range from user then make asciigen obj and display it
                GetAsciiRangeFromUser(firstChar, lastChar);
                AsciiGenerator asciiGen(firstChar, lastChar);
                system("clear");
                asciiGen.displayVertically();
            }
            while (userSaysYes("Display another range using this format?"));
        }
        break;
        }
    }
    while (!finished);

}


void DisplayProgramInfo()
{
    // display program opening screen
    DisplayOpeningScreen("Jarvis:Isaiah:A00439675:u11\n",
        "Submission 03\n"
        "Displaying Printable ASCII Characters and Their Codes, Part 3",
        9, 11);
}

void GetInformation()
{
    // make and display textitem object
    TextItems t("display_ascii3.txt");
    t.displayItem("ProgramDescription");
}

void BuildMenu(Menu& menu)
{
    // add menu options
    menu.addOption("Quit");
    menu.addOption("Get information");
    menu.addOption("Display ASCII codes horizontally (increasing across rows");
    menu.addOption("Display ASCII codes vertically (increasing down columns)");
}

void GetAsciiRangeFromUser(char& firstChar, char& lastChar)
{
    // variables
    bool complete;

    // print info to user
    cout << R"TEXT(
Choose ASCII character end points for the range of values you wish to display.
Both end point characters must lie in the range of characters from ' ' to '~'.
Also, the start character must precede the end character in the ASCII sequence.
)TEXT";
    
    // do-while for getting ascii range while dectecting errors
    do
    {
        // set complete to true so if nothing goes wrong loop executes fully
        complete = true;

        // new line
        cout << endl;

        // read char and check it is a printable character
        ReadChar("Enter start character for the table display:", firstChar);
        if ((int)firstChar < 32 || (int)firstChar > 127)
        {   
            cout << R"TEXT(
Error: The first character of that entry was not a printable character.
Try again. Be careful to enter valid starting/ending characters for the table.
)TEXT";
            complete = false;
        }

        // if statement if there was no error with the first char
        if (complete == true) {
            // read char and check if it is >= the first char
            ReadChar(
            "Enter end character for the table display (>= previous value):",
            lastChar);
            if (lastChar < firstChar)
            {
                cout << R"TEXT(
Error: The starting character for the table display must not follow
the ending character in the ASCII sequence. Try again.)
)TEXT";
                cout << endl;
                complete = false;
            }
        }
    }
    // exit loop when complete = true
    while (!complete);
}
