//functions.cpp
//Jarvis:Isaiah:A00439675:u11
//Submission 06
//Gathering Odds and Evens

/*
Self-assessment goes here ...
*/

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

#include "utilities.h"
using Scobey::Pause;
using Scobey::RandomGenerator;

extern const string MY_ID_INFO = "Jarvis:Isaiah:A00439675:u11";

//Two auxiliary "helper functions"
int isOdd(int n)
{
    return n % 2 == 1;
}

int isEven(int n)
{
    return n % 2 == 0;
}

void DisplayProgramInfo()
{
    cout << R"(

This program takes a single non-negative integer on the command line as input.
If it is missing, an opening screen is displayed, followed by this information.
If the value supplied is > 0, the generated values will repeat each time that
value is used. If the value is 0, the values will be different on each run.

The program then generates random two-digit integer values from the range
10..99. It puts some of them into a deque and some of them into a list. The
number of values in the deque, as well as the number in the list, is itself
a random number in the range 10..15. Next the program displays the contents
of the deque and the list, with positions numbered so that it is easy for
the viewer to see how many values are in each container.

The program then calls a first function, that arranges for all of the odd
values in both the deque and the list to be placed in the deque, and all
the even numbers from both the deque and the list to be placed in the list.
Furthermore, the deque is sorted ascending and the list descending, and
duplicate values are removed from each. The contents of the deque and the
list are then displayed as before, to confirm that this has been done.

Finally, the program calls a second function, implemented differently, to
perform the same actions on copies of the original deque and list.

                                                                 Screen 1 of 1
)";
    Pause();
}

void SeedRandomGeneratorIfRequired
(
    int seedValue,           //in
    RandomGenerator& randGen //inout
)
{
    if (seedValue != 0) {
        RandomGenerator newGen(seedValue);
        randGen = newGen;
    }
}

void GenerateRandomValues
(
    RandomGenerator& randGen, //inout
    deque<int>& theDeque,     //inout
    list<int>& theList        //inout
)
{
    int dequeLength, listLength;

    dequeLength = randGen.getNext(10, 15);
    for(int i = 0; i < dequeLength; i++) {
        theDeque.push_back(randGen.getNext(10, 99));
    }

    listLength = randGen.getNext(10, 15);
    for(int i = 0; i < listLength; i++) {
        theList.push_back(randGen.getNext(10, 99));
    }
}

void GatherOddsInDequeEvensInList1
(
    deque<int>& theDeque, //inout
    list<int>& theList    //inout
)
{
    vector<int> evens(15), odds(15);

    copy_if(begin(theDeque), end(theDeque), begin(evens),(isEven));
    copy_if(begin(theDeque), end(theDeque), begin(odds),(isOdd));

    copy_if(begin(theList), end(theList), begin(evens), (isEven));
    copy_if(begin(theList), end(theList), begin(odds), (isOdd));

    //theDeque.clear();
    //theList.clear();

    //sort(evens.begin(), evens.end());
    //sort(odds.begin(), odds.end());

    //vector<int>::iterator newEnd = unique(evens.begin(), evens.end());
    //evens.erase(newEnd, evens.end());
    //newEnd = unique(odds.begin(), odds.end()); 
    //odds.erase(newEnd, odds.end());

    theDeque.resize(odds.size());
    theList.resize(evens.size());

    copy(evens.begin(), evens.end(), theList.begin());
    copy(odds.begin(), odds.end(), theDeque.begin());
}

void GatherOddsInDequeEvensInList2
(
    deque<int>& theDeque, //inout
    list<int>& theList    //inout
)
{
    copy_if(begin(theDeque), end(theDeque), begin(theList),(isEven));
    remove_if(begin(theDeque), end(theDeque), (isEven));

    copy_if(begin(theList), end(theList), begin(theDeque), (isOdd));
    theList.remove_if(isOdd);

    sort(theDeque.begin(), theDeque.end());
    unique(theDeque.begin(), theDeque.end());
    theList.sort();
    theList.unique();
}

void DisplayContentsOfDequeAndList
(
    const deque<int>& theDeque, //in
    const list<int>& theList    //in
)
{
    cout << "\n               1  2  3  4  5  6  7  8  9 10 11 12 13 14 15";
    cout << "\nfor the deque ";
    copy(begin(theDeque), end(theDeque), ostream_iterator<int>(cout, " "));
    cout << "\nfor the list  ";
    copy(begin(theList), end(theList), ostream_iterator<int>(cout, " "));
}
