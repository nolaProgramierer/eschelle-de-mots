/*
 * This program constructs a word ladder from
 * one word to another formed by changing one
 * letter at a time with the constraints that
 * at each step the sequence of lettrers still
 * forms a vlid word.
 * Based on Stanford CS 106B assignment
 * Glenn Langdon
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include <filelib.h>
#include <lexicon.h>

using namespace std;

/*
 * Function prototypes
 */


int main() {
    cout << "Please give me two English words, and I will convert the" << endl;
    cout << "first into the second by modifying one letter at a time." << endl;

    ifstream stream;
    promptUserForFile(stream, "Dictionary file name:", "Dictionary not found, "
                                                       "Please enter a valid dictionary.");
    Lexicon lex = Lexicon(stream);



    cout << "Have a nice day." << endl;
    return 0;
}
