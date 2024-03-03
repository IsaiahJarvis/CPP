//AsciiGenerator.cpp
//Submission 03: Displaying Printable ASCII Characters and Their Codes, Part 3

#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "utilities.h"
#include "AsciiGenerator.h"
using Scobey::Pause;

AsciiGenerator::AsciiGenerator
(
    char firstChar, //in
    char lastChar   //in
)
{
    // set input characters to previously private variables
    this->firstChar = firstChar;
    this->lastChar = lastChar;
}

void AsciiGenerator::displayHorizontally()
{
    // variables
    int counter = 1;
    int lineCounter = 2;

    // new line
    cout << endl;

    // for loop for printing labels
    for (char ch = firstChar; ch <= lastChar; ch++)
    {
        if (counter <= 4)
        {
            cout << "     Dec Oct Hex";
        }
        counter++;
    }

    // new line
    cout << endl;

    // reset counter
    counter = 1;
    // for loop for printing ascii characters
    for (char ch = firstChar; ch <= lastChar; ch++)
    {
        cout << setw(4) << ch << setw(4) << dec << (int)ch;
        cout << setw(4) << oct << (int)ch;
        cout << setw(4) << uppercase << hex << (int)ch;
        counter++;

        // detect if new line is needed then make new line
        if (counter > 4)
        {
            counter = 1;
            lineCounter++;
            cout << endl;
        }

        // detect if new page is needed then make new page
        if (lineCounter == 24)
        {
            // pause
            Pause();

            // reset line counter
            lineCounter = 0;

            // for loop for reprinting labels
            for (char ch2 = ch; ch2 < lastChar; ch2++)
            {
                if (counter <= 4)
                {
                    cout << "     Dec Oct Hex";
                }
                counter++;
            }
            cout << endl;
            counter = 1;
        }
    }
    cout << endl;
    Pause();
}

void AsciiGenerator::displayVertically()
{
    // variables
    int counter = 1;
    int lineCounter = 0;
    int incrementCounter = 0;
    int numOfRows = 1;
    int x = 0;
    int finalCounter = 1;
    char initialChar = firstChar;
    char ch;

    // new line
    cout << endl;

    // loop to print labels
    for (char ch = firstChar; ch <= lastChar; ch++)
    {
        if (counter <= 4)
        {
            cout << "     Dec Oct Hex";
        }
        counter++;
    }

    // new line
    cout << endl;

    // prints horizontally if less than 1 line
    if ((lastChar - firstChar) < 4)
    {
        for (char ch = firstChar; ch <= lastChar; ch++)
        {
            cout << setw(4) << ch << setw(4) << dec << (int)ch;
            cout << setw(4) << oct << (int)ch;
            cout << setw(4) << uppercase << hex << (int)ch;
            counter++;
        }
        // new line and pause
        cout << endl;
        Pause();
    }
    // if more than 1 line
    else
    {
        // calculate number of rows for the horizontal increment
        numOfRows = ((lastChar - firstChar) + 1) / 4;
        // calculater x for the number of finished columns
        x = ((lastChar - firstChar) + 1) % 4;

        // if there is an unfinished row add it to numOfRows
        if (x > 0)
        {
            numOfRows += 1;
        }
        else
        {
            (x = 4);
        }

        // reset counter and set ch for the loop
        counter = 1;
        ch = initialChar;

        // while loop that prints characters until predetermined number is reached
        while (finalCounter <= lastChar - firstChar + 1)
        {
            // print characters
            cout << setw(4) << ch << setw(4) << dec << (int)ch;
            cout << setw(4) << oct << (int)ch;
            cout << setw(4) << uppercase << hex << (int)ch;
            counter++;
            finalCounter++;
            // check if new line is needed then makes new line if needed
            if (counter > 4)
            {
                counter = 1;
                lineCounter++;
                incrementCounter++;
                cout << endl;
                ch = initialChar + incrementCounter;
            }
            // if preceding column is full increment next column
            else if (counter - 2 < x)
            {
                ch += numOfRows;
            }
            // if preceding column is not full next column will be incremented 1 less
            else
            {
                ch += numOfRows - 1;
            }

            // check if new screen is needed
            if (lineCounter == 22)
            {
                // pause
                Pause();

                // reset line counter
                lineCounter = 0;

                // print new labels
                for (char ch = firstChar; ch <= lastChar; ch++)
                {
                    if (counter <= 4)
                    {
                        cout << "     Dec Oct Hex";
                    }
                    counter++;
                }
                // reset counter and make new line
                counter = 1;
                cout << endl;
            }
        }
        // final new line and pause
        cout << endl;
        Pause();
    }
}

