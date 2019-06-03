/*
 * This program constructs a word ladder from
 * one word to another formed by changing one
 * letter at a time with the constraints that
 * at each step the sequence of letters still
 * forms a valid word.
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
bool isInDictionary(string word, Lexicon dict);
Queue<Stack<string>> makeQueue(string w1, string w2, Queue<Stack<string>> q);


int main() {
    cout << "Please give me two English words, and I will convert the" << endl;
    cout << "first into the second by modifying one letter at a time." << endl;


    string testWord = "cart";
    cout << testWord.substr(0, 2) + testWord.at(2) + testWord.substr(3) << endl;
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
            string temp = w1;
            Queue<Stack<string>> stackQueue;
            for (size_t i = 0; i < w1.length(); i++) {
                for (char ltr = 'a'; ltr <= 'z'; ltr++) {
                    temp.at(i) = ltr;
                    string tempWord = temp.substr(0, i) + temp.at(i) + temp.substr(i + 1);
                    if (ltr == 'z') {
                        temp.at(i) = w1.at(i);  //reset index to original word letter
                    }

                    if (isInDictionary(tempWord, lex) && tempWord != w1) {
                        // cout << tempWord << endl;
                        Queue<Stack<string>> ladderQ = makeQueue(w1, tempWord, stackQueue);
                    }
                }
            }
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
    else if (!lex.contains(word1) || !lex.contains(word2)) {
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

/*
 * If generated word is in the dictionary, return true
 */
bool isInDictionary(string word, Lexicon dict) {
    if (!dict.contains(word)) {
        return false;
    }
    return true;
}
/*
 * Makes a new stack, pushes starting word onto stack,
 * pushes next word in word ladder onto stack,
 * then enqueues the stack
 */
Queue<Stack<string>> makeQueue(string w1, string w2, Queue<Stack<string>> q) {
    Stack<string> ladderStack;
    ladderStack.push(w1);
    ladderStack.push(w2);
    q.enqueue(ladderStack);
    return q;
}

