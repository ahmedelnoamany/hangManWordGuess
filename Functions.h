/* 
 * File:   Functions.h
 * Author: Ahmed Elnoamany
 * Created on September 19, 2016, 2:54 PM
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
using namespace std;

class Functions {
    
public:
    
    void displayWord(string word,int size, bool identified[]);
    bool search(string word, int size, char search_letter, bool indentified[]);
    string chooseWord();
    bool save(int score);
    bool load(int &score);
    char guessLetter(char guessed[], int numCharGuessed);
    bool guessWord(string word);
    bool gameOver(int score);
    
private:

};

#endif /* FUNCTIONS_H */

