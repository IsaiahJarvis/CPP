//Menu.cpp
//Submission 04 menu class:


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "menu.h"
extern const string MY_ID_INFO = "Jarvis:Isaiah:A00439675:u11";

namespace Student
{

    Student::Menu::Menu()
    {
        numberOfOptions = 0;
        string s = "Empty Menu";
        titlePtr = new char[s.length() + 1];
        strcpy(titlePtr, s.c_str());
    }

    Student::Menu::~Menu()
    {
        // delete and display title
        cout << "Deleting menu title: ";
        cout << titlePtr << "\n";
        delete titlePtr;

        // if there are options delete their nodes and text
        if (numberOfOptions > 0)
        {
            int nodeNum = 2;
            OptionNode* current;
            OptionNode* next = firstNodePtr->link;
            cout << "Deleting text in node 1: ";
            delete [] firstNodePtr->optionTextPtr;
            cout << "\nDeleting node 1 itself.";
            delete [] firstNodePtr;
            firstNodePtr = NULL;
            while (next != nullptr)
            {
                current = next;
                next = next->link;
                cout << "\nDeleting text in node " << nodeNum << ": ";
                cout << current->optionTextPtr;
                delete [] current->optionTextPtr;
                cout << "\nDeleting node " << nodeNum << " itself.";
                delete [] current;
            }
            cout << endl;
        }

    }

    void Student::Menu::setTitle(const string& menuTitle)
    {
        // make string int cstring
        titlePtr = new char[menuTitle.length() + 1];
        strcpy(titlePtr, menuTitle.c_str());
    }

    void Student::Menu::addOption(const string& option)
    {
        // increment for each time this function is called
        numberOfOptions++;

        // if number of options is 1 create first node
        if (numberOfOptions == 1)
        {
            firstNodePtr = new OptionNode;
            firstNodePtr->optionTextPtr = new char[option.length() + 1];
            strcpy(firstNodePtr->optionTextPtr, option.c_str());
            lastNodePtr = firstNodePtr;
        }
        // if number of options is 2 create second node and link to first node
        else if (numberOfOptions == 2)
        {
            lastNodePtr = new OptionNode;
            firstNodePtr->link = lastNodePtr;
            lastNodePtr->optionTextPtr = new char[option.length() + 1];
            strcpy(lastNodePtr->optionTextPtr, option.c_str());
            lastNodePtr->link = nullptr;
        }
        // if not first or second node create and link to previous nodes
        else
        {
            lastNodePtr->link = new OptionNode;
            lastNodePtr = lastNodePtr->link;
            lastNodePtr->optionTextPtr = new char[option.length() + 1];
            strcpy(lastNodePtr->optionTextPtr, option.c_str());
            lastNodePtr->link = nullptr;
        }
    }

    void Student::Menu::display() const
    {
        // variables
        int topLines = 10;
        int bottomLines = 12 - ((numberOfOptions + 3) / 2);
        int lineNum = 1;

        // for loop for printing top lines
        for (int i = 0; i < topLines; i++)
        {
            cout << endl;
        }
        
        // print title
        cout << titlePtr;
        cout << "\n\n";

        // if there are no options tell the user
        if (numberOfOptions == 0)
        {
            cout << "This menu has no options ... \n";
        }
        // if there are options display them with a loop
        else
        {
            OptionNode* current = firstNodePtr;
            // print options
            while (current != nullptr)
            {
                cout << lineNum << ". " << current->optionTextPtr;
                cout << endl;
                current = current->link;
                lineNum++;
            }
        }

        // loop for printing bottom lines
        for (int i = 0; i < bottomLines; i++)
        {
            cout << endl;
        }
    }

    int Student::Menu::getChoice() const
    {
        // if there are no options print out error and return -1
        if (numberOfOptions == 0)
        {
            cout << "===== Error: The menu has no options from which to "
                "choose.\n";
            cout << "Press Enter to continue ... "; cin.ignore(80, '\n');
            return -1;
        }
        // if there are options ask for input and return if its not a new line
        else 
        {
            char choice;
            int choiceNum;
            cout << "Enter the number of your menu choice here and press"
            " Enter:";

            choice = cin.get();

            if (choice != '\n') {
            cin.ignore(80, '\n');
            choiceNum = (int) choice - 48;
            return choiceNum;
            } else {
            return -1;
            }
        }
    }
}
