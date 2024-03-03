//anagrams.cpp
//Jarvis:Isaiah:A00439675:u11
//Submission 05
//Finding Anagrams

/*
    program properly searches a given file for anagrams of an input word
    and prints them out in order
*/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "utilities.h"
using Scobey::Pause;
using Scobey::DisplayOpeningScreen;

int main(int argc, char* argv[])
{
    // variables
    string fileName, word, isWord;
    vector<string> dictionary, anagrams;
    bool done = false;

    // display program opening screen
    DisplayOpeningScreen("Jarvis:Isaiah:A00439675:u11\n",
        "Submission 05\n"
        "Finding Anagrams",
        9, 11);

    // print program info
    cout << "This program finds all the words in a dictionary that can be "
        "formed with the\nletters of a given word (or string), and "
        "displays them in alphabetical order.";

    // prompt user input
    cout << "\n\nEnter the name of the file containing the dictionary: ";

    // get user input and make ifstream object
    cin >> fileName; cin.ignore(80, '\n');
    ifstream inFile(fileName);

    // test if file can be opened
    if (!inFile.is_open())
    {
        cout << "Could not open file named " << fileName;
        cout << ".\nProgram is now terminating.\n";
        Pause();
        exit(0);
    }

    // read the dictionary into a vector
    cout << "\nReading the dictionary ...\n";
    while (inFile >> isWord) dictionary.push_back(isWord);
    cout << "The dictionary contains " << dictionary.size() << " words.\n";
    Pause();

    // prompt for input
    cout << "Now enter a word (or any string of letters) and I'll give you\n"
        "a list of all of its anagrams (if any) found in the dictionary: ";

    // do while loop for getting the word and displaying its anagrams
    do
    {
        // input
        cin >> word; cin.ignore(80, '\n');
        // if end of line character used terminate program
        if (!cin)
        {
            cin.clear();
            done = true;
            cout << "\nProgram is now terminating.\n";
            Pause();
        }
        // if proper input given sort input word and search dictionary
        else
        {
            sort(word.begin(), word.end());
            while (next_permutation(word.begin(), word.end()))
            {
                if (binary_search(dictionary.begin(), dictionary.end(), word))
                {
                    anagrams.push_back(word);
                }
            }

            // sort anagrams and print its contents
            if (anagrams.empty())
            {
                cout << "Sorry, no anagrams found for that input.\n";
            }
            else
            {
                sort(anagrams.begin(), anagrams.end());
                for (string i : anagrams) cout << i << "\n";
            }
            // clear anagrams and prompt for next word
            anagrams.clear();
            cout << "\nEnter another one (or the end-of-file character to stop): ";
        }
    }
    while (!done);

    // close file
    inFile.close();
}

