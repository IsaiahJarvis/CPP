// build_concordance.cpp
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <ctype.h>
using namespace std;

#include "utilities.h"
using Scobey::TextItems;
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;

bool isLetter(char c);

int main(int argc, char* argv[])
{

    // variables.
    fstream compare;
    fstream outFile, diffFile;
    string fileName, word = "", currentLine, line1, line2;
    int lineCount = 1, numCount = 0;
    map<string, set<int>> words;

    // print opening page if no command line input
    if (argc == 1)
    {
        DisplayOpeningScreen("Jarvis:Isaiah:A00439675:u11",
            "\nSubmission 08\n"
            "Building Concordances",
            9, 11);

        TextItems t("build_concordance.txt");
        t.displayItem("ProgramDescription");

        exit(0);
    }

    // make files and check if they can be opened
    fileName = argv[1];
    fstream inFile1(fileName);
    if (!inFile1.is_open())
    {
        cout << "Could not open file named " << fileName;
        cout << ".\nProgram is now terminating.\n";
        Pause();
        exit(0);
    }

    if (argc >= 3)
    {
        fileName = argv[2];
        outFile.open(fileName);
    }

    if (argc >= 4)
    {
        fileName = argv[3];
        fstream compare(fileName);
        fstream diffFile("differences.txt");
        if (!compare.is_open())
        {
            cout << "Could not open file named " << fileName;
            cout << ".\nProgram is now terminating.\n";
            Pause();
            exit(0);
        }
    }

    // while loop to get lines
    while (getline(inFile1, currentLine))
    {
            // loop through current line and place words into map
            for (auto i : currentLine)
            {
                // if char is not letter add it and line num to words
                if (i == ' ' || isalpha(i) == 0)
                {
                    words[word];
                    words[word].insert(lineCount);
                    word = "";
                }
                // if char is a letter add to word
                else if (isalpha(i) != 1)
                {
                    i = tolower(i);
                    word = word + i;
                }
            }

            // rest words
            words[word];
            words[word].insert(lineCount);
            word = "";
            lineCount++;
    }

    // erase spaces
    words.erase("");

    // checks if only 1 command line input and then prints out formatted map contents
    if (argc == 2)
    {
        // map iterator
        map<string, set<int>>::iterator p;

        // iterate through and print words contents
        for (p = words.begin(); p != words.end(); p++)
        {
            // formatted key output
            cout << right << setw(15) << p->first << " ";

            // set iterator
            set<int>::iterator l;
            // reset numCount
            numCount = 0;
            // iterate through and prnt the sets contents
            for (l = p->second.begin(); l != p->second.end(); l++)
            {
                cout << *l << " ";
                numCount++;
                // if numCount is 15 or the next char is end of the set start
                // new line
                if (numCount == 15 && l++ != p->second.end())
                {
                    cout << setw(16) << endl << "  ";
                    numCount = 0;
                    cout << left;
                }
            }
            // new line
            cout << endl;
        }
    }
    // check if 2 or more command line inputs 
    else if (argc >= 3)
    {
        // map iterator
        map<string, set<int>>::iterator p;

        // iterate through and print words contents to file
        for (p = words.begin(); p != words.end(); p++)
        {
            // formatted key output
            outFile << right << setw(15)<< p->first << " ";

            // set iterator
            set<int>::iterator l;
            // reset numCount
            numCount = 0;
            // iterate through and prnt the sets contents
            for (l = p->second.begin(); l != p->second.end(); l++)
            {
                outFile << *l << " ";
                numCount++;
                // if numCount is 15 or the next char is end of the set start
                // new line
                if (numCount == 15 && l++ != p->second.end())
                {
                    outFile << setw(16) << endl << " ";
                    numCount = 0;
                    cout << left;
                }
            }
            // new line
            outFile << endl;
        }
        // if there is a 3rd command line input read both files and print
        // to differences.txt
        if (argc == 4) 
        {
            while (getline(outFile, line1) && getline(compare, line2)) {
                if (line1 != line2) {
                    
                }
            }
        }
    }
}
