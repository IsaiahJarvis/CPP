//display_ascii1.cpp
//Jarvis:Isaiah:A00439675:u11
//Submission 01
//Displaying Printable ASCII Characters and Their Codes, Part 1

/*
 * Program properly displays a selected range of characters in their
 * decimal, octal and hexadecimal codes 
 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    // opening screen
    if (argc == 1)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\nJarvis:Isaiah:A00439675:u11\n";
        cout << "Submission 01\nDisplaying Printable ASCII Characters and";
        cout << " Their Codes, Part 1\n\n\n\n\n\n\n\n\n\n\n";

        cout << "Press Enter to countinue ... "; cin.ignore(80, '\n');

        cout << R"TEXT(
This program takes two printable ASCII characters as input, with the first
character preceding the second in the ASCII character sequence. The program
then displays all characters in the range determined by those two characters,
along with their corresponding decimal, octal and hexadecimal codes, four per
line, with a suitable header and a pause if the display consumes more than a
single screen of output. The two input character values must be entered as
two separate command-line parameters, and there is no error checking.

The printable ASCII characters extend from the blank space character ' '
(which has code 32 decimal) to the tilde character '~' (which has code 126
decimal). The characters with codes in the range 0 to 31 and also code 127
are non-printable "control characters".

When entering characters at the command line to determine the character range
we want in the output, we need to be very careful how we enter some characters.
These include the blank space character and some others that are treated as
"meta characters" by the operating system, and are thus not passed to the
program for processing. To avoid this problem we will place each character
entered at the command line within double quotes. The " and \ characters must
(as usual) be escaped within their enclosing double quotes, and so must the
backtick character (the `).

                                                                  Screen 1 of 1
)TEXT";
    cout << "Press Enter to countinue ... "; cin.ignore(80, '\n');
    } else {
        // variables
        char start = argv[1][0];
        char end = argv[2][0]; 
        int startNum = int(start);
        int endNum = int(end);
        int counter = 1;
        int lineCounter = 2;

        // for loop for making top row of Dec Oct Hex
        cout << endl;
        for (int i = startNum; i <= endNum; i++) {
            if (counter <= 4) {
            cout << "     Dec Oct Hex"; 
            }
        counter++;
        }
        
        // new line
        cout << endl;

        // for loop to display characters normally and in 3 other forms
        counter = 1;
        for (int i = startNum; i <= endNum; i++) {
        cout << setw(4) << char(i) << setw(4) << dec << i;
        cout << setw(4) << oct << i << setw(4) << uppercase << hex << i;
        counter++;
            if (counter > 4) {
                counter = 1;
                lineCounter++;
                cout << endl;
        }
            if (lineCounter == 24) {
                // pause and clear
                cout << "Press Enter to continue ... "; cin.ignore(80, '\n');
                system("clear");

                // variables
                lineCounter = 0;
                int counterTwo = 1;
                
                // new line
                cout << endl;
                // for loop to print the next set of labels
                for (int o = i; o < endNum; o++) {
                    if (counterTwo <= 4) {
                        cout << "     Dec Oct Hex"; 
                    }
                counterTwo++;    
                }
                cout << endl;
            } 
        }
        // create a new line and pause
        cout << endl;
        cout << "Press Enter to continue ... "; cin.ignore(80, '\n');
    }
}
