//display_ascii2.cpp
//Jarvis:Isaiah:A00439675:u11
//Submission 02
//Displaying Printable ASCII Characters and Their Codes, Part 2

/*
Your self-assessment goes here.
//--Replace the above line and this one with your actual self-assessment.
*/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "utilities.h"
using Scobey::DisplayTextfile;
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;
void DisplayProgramInfo();
/**<
Display program description, with a pause at the end of each screen.
*/

void DisplayAsciiHorizontally
(
    char firstChar, //in
    char lastChar   //in
);
/**<
Display ASCII characters and their decimal, octal and hexadecimal
codes in row-wise fashion, i.e. with codes increasing from left to right.
@param firstChar The low endpoint of the ASCII value range to be displayed.
@param lastChar The high endpoint of the ASCII value range to be displayed.
@pre ' ' <= firstChar <= lastChar <= '~'.
@post A table of ASCII character/code values has been displayed, with
codes increasing from left to right across the rows, from firstChar to
lastChar (inclusive). Each ASCII character and each of its three
numerical codes appears right-justified in a fieldwidth of 4 spaces.
The range of values displayed depends on input from the user.
*/

void DisplayAsciiVertically
(
    char firstChar, //in
    char lastChar   //in
);
/**<
Display #include <iomanip> ASCII characters and their decimal, octal and hexadecimal
codes in column-wise fashion, i.e. with codes increasing from top
to bottom down each column.
@param firstChar The low endpoint of the ASCII value range to be displayed.
@param lastChar The high endpoint of the ASCII value range to be displayed.
@pre ' ' <= firstChar <= lastChar <= '~'.
@post A table of ASCII character/code values has been displayed, with
codes increasing  from top to bottom, down the columns, from firstChar
to lastChar (inclusive). Each ASCII character and each of its three
numerical codes appears right-justified in a fieldwidth of 4 spaces.
The range of values displayed depends on input from the user.
*/


int main(int argc, char* argv[])
{
    // check if args is empty and display program info if it is
    if (argc == 1) 
    {
        DisplayProgramInfo();
    } 
    // check for errors then call the correct function
    else 
    {
        // check if theres exactly 3 command-line parameters 
        if (argc != 4) 
        {
            cout << "Error: Program must have exactly 3 command-line "
            "parameters.\n";
            cout << "Program is now terminating...\n";
            Pause();
            return 3;
        } 
        // check if each parameter is a single char
        else if 
        (
        strlen(argv[1]) != 1 ||
        strlen(argv[2]) != 1 ||
        strlen(argv[3]) != 1
        )
        {
            cout << "Error: Each input parameter must be a single character.";
            cout << "\nProgram is now terminating...\n";
            Pause();
            return 3;
        } 
        // check if the first 2 parameters are in the correct order
        else if (argv[1][0] >= argv[2][0]) 
        {
            cout << "Error: First input parameter must not follow second in"
            "the ASCII sequence.\n";
            cout << "Program is now terminating...\n";
            Pause();
            return 3;
        } 
        // check if the 3rd parameter is h or v
        else if (argv[3][0] != 'h' && argv[3][0] != 'v') 
        {
            cout << "Error: Third parameter must be h or v.\n";
            cout << "Program is now terminating...\n";
            Pause();
            return 3;
        } 
        // if 3rd parameter is h call DisplayAsciiHorizontally
        else if (argv[3][0] == 'h') {
            system("clear");
            DisplayAsciiHorizontally(argv[1][0], argv[2][0]);
        } 
        // if 3rd parameter is v call DisplayAsciiVertically
        else if (argv[3][0] == 'v') {
            system("clear");
            DisplayAsciiVertically(argv[1][0], argv[2][0]);
        }

    }
}

//--Function definitions go here (after your main() function), and in
//--the same order as the function prototypes that preceded your main()
//--function. Note that doxygen-style comments appear only with the
//--prototypes, not with the definitions, but of course other explanatory
//--comments will be necessary in the bodies of your functions, and also
//--the comments indicating the direction of data flow for each parameter
//--must be retained in each function definition.

void DisplayProgramInfo()
{
    DisplayOpeningScreen("Jarvis:Isaiah:A00439675",
    "\nSubmission 02\n"
    "Displaying Printable ASCII Characters and Their Codes, Part 2",
    9, 11);
    
    cout << R"TEXT(
This program displays a table of printable ASCII characters, along with their
corresponding decimal, octal and hexadecimal codes, four per line, except
possibly for the last line. The table has a suitable header and a pause at
the end of the display and at the end of the first screen if the display
consumes more than a single screen of output.
    
The program takes three command-line parameters as input. The first two give
the range of characters to be displayed, and the first character must precede
the second in the ASCII character sequence. The third input parameter must be
either an h or a v to indicate whether the display is to be horizontal (codes
increasing across the rows) or vertical (codes increasing down the columns).
    
The program must also recognize the following errors and terminate immediately
after reporting that such an error has occurred:
    
- Wrong number of input parameters (not exactly 3)
      
- One or more input parameters not being a single character
        
- First input value following the second in the ASCII sequence
          
- Third input value something other than h or v
                                                                  Screen 1 of 2
)TEXT";

    Pause();

    cout << R"TEXT(
When entering characters at the command line to determine the character range
we want in the output, we need to be very careful how we enter some characters.
These include the blank space character and some others that are treated as
"meta characters" by the operating system, and are thus not passed to the
program for processing. To avoid this problem we will place each character
entered at the command line within double quotes. The " and \ characters must
(as usual) be escaped within their enclosing double quotes, and so must the
backtick character (the `).














                                                              Screen 2 of 2
)TEXT";
    Pause();    
    }

void DisplayAsciiHorizontally
(
    char firstChar, //in
    char lastChar   //in
)
{
    // variables
    int counter = 1;
    int lineCounter = 2;

    // new line
    cout << endl;

    // print labels for the display
    for (char ch = firstChar; ch <= lastChar; ch++) {
        if (counter <= 4) {
            cout << "     Dec Oct Hex";
        }
        counter++;
    }

    // new line
    cout << endl;
    
    counter = 1;
    for (char ch = firstChar; ch <= lastChar; ch++) {
        cout << setw(4) << ch << setw(4) << dec << (int)ch;
        cout << setw(4) << oct << (int)ch;
        cout << setw(4) << uppercase << hex << (int)ch;
        counter++;
        // check if new line is needed then make new line if it is
        if (counter > 4) 
        {
            counter = 1;
            lineCounter++;
            cout << endl;
        }

        // check if new screen is needed
        if (lineCounter == 24) 
        {
            // pause
            Pause();

            // reset line counter
            lineCounter = 0;

            // print new labels
            for (char ch2 = ch; ch2 < lastChar; ch2++) {
                if (counter <= 4) {
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

void DisplayAsciiVertically
(
    char firstChar, //in
    char lastChar   //in
)
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

    // print labels for display
    for (char ch = firstChar; ch <= lastChar; ch++) 
    {
        if (counter <= 4) {
            cout << "     Dec Oct Hex";
        }
        counter++;
    }

    // new line
    cout << endl;

    // if output is 1 row or less just print horizontally
    if ((lastChar - firstChar) < 4) 
    {   
        for (char ch = firstChar; ch <= lastChar; ch++) {
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
        // calculater number of rows for the horizontal increment
        numOfRows = ((lastChar - firstChar) + 1) / 4;
        // calculater x for the number of finished columns
        x = ((lastChar - firstChar) + 1) % 4;
    
        // if there is an unfinished row add it to numOfRows
        if (x > 0) 
        { 
            numOfRows += 1;
        } 
        // if there isnt an unfinished row set x to 4
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
        // check if new line is needed and make it if it is
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

            //reset line counter
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
    // final newline and pause
    cout << endl;
    Pause();
    }
}
