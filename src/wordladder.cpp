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
Vector<string> findLadderWords(Vector<string> vec, Lexicon lex, string w1);
Vector<string> findAllCombinations(string w1);
Queue<Stack<string>> makeLadderQueue(Vector<string> vec, string w1);

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
            Vector<string> vec = findLadderWords(findAllCombinations(w1), lex, w1);
            makeLadderQueue(vec,w1);
        }

    }

    return 0;
}
/*
 * Creates a stack with the original word and
 * a possible ladder word and then pushes the
 * stacks onto a queue
 */
Queue<Stack<string>> makeLadderQueue(Vector<string> vec, string origWord) {
    Queue<Stack<string>> ladderQ;
    for (int i = 0; i < vec.size(); i++) {
        Stack<string> stack;
        stack.push(origWord);
        stack.push(vec[i]);
        ladderQ.enqueue(stack);
    }
//    cout << ladderQ << endl;
    return ladderQ;
}
/*
 * Returns a vector of all words one letter apart
 * from original given word
 */
Vector<string> findLadderWords(Vector<string> vec, Lexicon lex, string w1) {
    Vector<string> ladderWordVec;
    for (int i = 0; i < vec.size(); i++) {
        string possibleWord = vec[i];
        if (isInDictionary(possibleWord, lex) && possibleWord != w1) {
            string ladderWord = possibleWord;
//            cout << ladderWord << endl;
            ladderWordVec.add(ladderWord);
        }
    }
    return ladderWordVec;
}
/*
 * Returns vector of all possible letter combinations
 * of given word.
 */
Vector<string> findAllCombinations(string w1) {
    Vector<string> allCombinations;
    string temp = w1;
    for (size_t i = 0; i < w1.length(); i++) {
        for (char ltr = 'a'; ltr <= 'z'; ltr++) {
            temp.at(i) = ltr;
            string tempWord = temp.substr(0, i) + temp.at(i) + temp.substr(i + 1);
            allCombinations.add(tempWord);
//            cout << tempWord << endl;
            if (ltr == 'z') {
                temp.at(i) = w1.at(i);  //reset index to original word letter

            }
        }
    }
//    cout << allCombinations << endl;
    return allCombinations;
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



