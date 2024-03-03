//compute.cpp
//Jarvis:Isaiah:A00439675:u11
//Submission 09
//Building and Evaluating Expression Trees

/*
Don't forget to put your self-assessment here ...
*/

#include whatever header files you need here
using namespace std;
#include <iostream>
#include <string>
#include <sstream>

#include "utilities.h"
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;

/**
A type used for labeling the data content of a binary expression tree node.
*/
enum TagType
{
    INT_ONLY,
    SUB_NODE
};

/**
The type used for the nodes of a binary expression tree.
*/
struct TreeNode
{
    TagType tag;
    union //Note that this union type is "anonymous".
    {
        int intValue;
        struct //And this struct type is also anonymous.
        {
            TreeNode* left;
            char op;
            TreeNode* right;
        };
    };
};

//--Put your function definitions here, then remove this line.

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        //--Put your information into the following line, then remove this one.
        DisplayOpeningScreen("Lastname:Firstname:A00??????:u??",
            "\nSubmission 09"
            "\nImplementing a Simple Four-Function Calculator");
        cout << R"(

This program is a simple four-function calculator, with command-line input.
Only integer arithmetic using four operators (+, -, *, or /) is permitted.

Each line of input is limited to either a single positive integer, or a
fully-parenthesized arithmetic expression containing only binary operators
and positive integer operands.

To avoid the problem of meta character interpretation by the shell, we
enclose each full expression within double quotes.

Extra spaces in valid input are ignored, but any characters other than blank
spaces that appear after a valid expression and on the same line will cause
that entire input line to be rejected as bad input.)"
            << "\n\n\n\n\n\n\n\n\n\n                                   "
            "                           Screen 1 of 1\n";
        Pause();
        return 0;
    }

    istringstream iss(argv[1]);


}

