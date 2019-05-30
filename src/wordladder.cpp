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
#include <simpio.h>

using namespace std;

/*
 * Function prototypes
 */
bool wordChecker(string w1, string w2, Lexicon lex);

int main() {
    cout << "Please give me two English words, and I will convert the" << endl;
    cout << "first into the second by modifying one letter at a time." << endl;

    ifstream stream;
    promptUserForFile(stream, "Dictionary file name:", "Dictionary not found, "
                                                       "Please enter a valid dictionary.\n");
    Lexicon lex = Lexicon(stream);

    while (true) {
        string w1 = getLine("Word 1 (or Enter to quit): ");
        string w2 = getLine("Word 2 (or Enter to quit): ");
       if (w1.empty() || w2.empty()) {
            cout << "Have a nice day." << endl;
            break;
        }
       else if (wordChecker(w1, w2, lex)) {
           // make word ladder
       }
    }

    return 0;
}
/*
 * If words are not the same length, are not found in the
 * dictionary, are not different, or a word is not entered
 * at all, the function returns false, otherwise it
 * returns true.
 */
bool wordChecker(string word1, string word2, Lexicon lex) {
    if (word1.length() != word2.length()) {
        cout << "The two words must be the same length." << endl;
        cout << endl;
        return false;
        }
    else if (lex.contains(word1) || lex.contains(word2)) {
        cout << "The two words must be found in the dictionary" << endl;
        cout << endl;
        return false;
    }
    else if (word1 == word2) {
        cout << "The two words must be different" << endl;
        cout << endl;
        return false;
    }
    return true;
}
