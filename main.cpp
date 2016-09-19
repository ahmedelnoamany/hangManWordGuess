/* 
 * File:   main.cpp
 * Author: Ahmed Elnoamany
 * Created on September 19, 2016, 11:40 AM
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Functions.h"
#include "GUI.h"

using namespace std;

bool Game(bool load_stuff);
void clearScreen();
 
Functions funcCall;
GUI gui;
int main()
{
    int choice;
    bool load = false;
    do {
        cout << "----------------------------------------------------------------" << endl;
        cout << "     ||__||   //\\\\ ||\\  ||  ||_||  ||\\//||   //\\\\  ||\\  ||" << endl;
        cout << "     ||  ||  //  \\\\||  \\||  ||__   ||   ||  //  \\\\ ||  \\||" << endl;
        cout << "----------------------------------------------------------------" << endl;





        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        clearScreen();
        cout << "----------------------------------------------------------------" << endl;
        cout << "     ||__||   //\\\\ ||\\  ||  ||_||  ||\\//||   //\\\\  ||\\  ||" << endl;
        cout << "     ||  ||  //  \\\\||  \\||  ||__   ||   ||  //  \\\\ ||  \\||" << endl;
        cout << "----------------------------------------------------------------" << endl;



        cout << "(0 0)" << "				___" << endl;
        cout << " /|--o	" << "			||||" << endl;
        cout << " / \\ " << "				||" << endl;
        cout << "				||" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        clearScreen();

        cout << "----------------------------------------------------------------" << endl;
        cout << "     ||__||   //\\\\ ||\\  ||  ||_||  ||\\//||   //\\\\  ||\\  ||" << endl;
        cout << "     ||  ||  //  \\\\||  \\||  ||__   ||   ||  //  \\\\ ||  \\||" << endl;
        cout << "----------------------------------------------------------------" << endl;



        cout << "	 (0 0)" << "			___" << endl;
        cout << "	  /|/	" << "		||||" << endl;

        cout << "	  /  " << "			||" << endl;
        cout << "				||" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        clearScreen();

        cout << "----------------------------------------------------------------" << endl;
        cout << "     ||__||   //\\\\ ||\\  ||  ||_||  ||\\//||   //\\\\  ||\\  ||" << endl;
        cout << "     ||  ||  //  \\\\||  \\||  ||__   ||   ||  //  \\\\ ||  \\||" << endl;
        cout << "----------------------------------------------------------------" << endl;





        cout << "	        (0 0)" << "		___" << endl;
        cout << "		 \\|\\	" << "	||||" << endl;
        cout << "		   \\ " << "		||" << endl;
        cout << "				||" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        clearScreen();

        cout << "----------------------------------------------------------------" << endl;
        cout << "     ||__||   //\\\\ ||\\  ||  ||_||  ||\\//||   //\\\\  ||\\  ||" << endl;
        cout << "     ||  ||  //  \\\\||  \\||  ||__   ||   ||  //  \\\\ ||  \\||" << endl;
        cout << "----------------------------------------------------------------" << endl;



        cout << "	           (0 0)" << "	 ___ " << endl;
        cout << "		    /|\\" << "		||||" << endl;
        cout << "		    / \\" << "		||()" << endl;
        cout << "				||" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        clearScreen();

        cout << "----------------------------------------------------------------" << endl;
        cout << "     ||__||   //\\\\ ||\\  ||  ||_||  ||\\//||   //\\\\  ||\\  ||" << endl;
        cout << "     ||  ||  //  \\\\||  \\||  ||__   ||   ||  //  \\\\ ||  \\||" << endl;
        cout << "----------------------------------------------------------------" << endl;



        cout << "	________" << endl;
        cout << "        ||  |  " << endl;
        cout << "	||(x x)" << endl;
        cout << "	|| /|\\" << endl;
        cout << "	|| / \\" << endl;
        cout << "	||" << endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        cout << endl << endl;
        for (int i = 0; i < 35; i++)
            cout << " ";
        cout << "Hangman!!" << endl;
        for (int i = 0; i < 35; i++)
            cout << " ";
        cout << "1. Play game" << endl;
        for (int i = 0; i < 35; i++)
            cout << " ";
        cout << "2. Load game" << endl;
        for (int i = 0; i < 35; i++)
            cout << " ";
        cout << "3. Exit" << endl;
        cin >> choice;
        if (choice == 1)
            Game(load);
        else if (choice == 2) {
            load = true;
            Game(load);
        } else if (choice == 3)
            return 0;
    } while (choice != 3);
    //Exit
    return 0;
}

bool Game(bool load_stuff) {
    int score = 0;                  //Number of words guessed right in a row
    int numCharGuessed = 0;         //Number of characters that have been guessed
    char guessed[26] = {};          //Array holding all characters that have been guessed
    int chancesLeft = 6;            //Number of guesses left. default is 6 guesses
    string word;                    //Word to be guessed
    int wordSize;                   //Size of the word that is being guessed.
    bool * correctGuesses;          //Bool Array that keeps track of which characters are guessed correctly
    char search_letter;             // Letter to be checked
    bool found = false;             // Bool Flag used to find if a character was found in the word or not
    bool succeed = false;
    bool word_win = false;
    if (load_stuff)     
        succeed = funcCall.load(score); 
    if (succeed) {
        cout << "Game loaded successfully";
        clearScreen();
    }
    int selection;
    do {
        //Check if user guessed word correctly.
        if (word_win) {
            gui.gUI(chancesLeft, score, guessed, numCharGuessed);
            funcCall.displayWord(word, wordSize, correctGuesses);
            cout << "You were right! The word was: " << word << endl;
            cout << "What would you like to do?" << endl;
            cout << "1. Get a new word" << endl;
            cout << "2. save your progress and exit" << endl;
            cin >> selection;
            numCharGuessed = 0;
            chancesLeft = 6;
            word_win = false;
            for (int i = 0; i < 26; i++)
                guessed[i] = '\0';
            if (selection == 1)
                continue;
            else if (selection == 2) {
                succeed = funcCall.save(score);
                if (!succeed) {
                    cout << "Could not be saved!!";
                    continue;
                } else
                    return 0;
            }
        } else {
            word = funcCall.chooseWord();
            wordSize = word.length();
            correctGuesses = new bool[wordSize];
            for (int i = 0; i < wordSize; i++)
                correctGuesses[i] = 0;
            gui.gUI(chancesLeft, score, guessed, numCharGuessed);
            funcCall.displayWord(word, wordSize, correctGuesses);
            do {

                gui.gUI(chancesLeft, score, guessed, numCharGuessed);
                funcCall.displayWord(word, wordSize, correctGuesses);
                cout << "What would you like to do?" << endl;
                cout << "1. Guess a letter" << endl;
                cout << "2. Guess the word" << endl;
                cout << "3. Forfeit" << endl;

                cin >> selection;
                if (selection == 1) {
                    search_letter = funcCall.guessLetter(guessed, numCharGuessed);
                    guessed[numCharGuessed] = search_letter;
                    numCharGuessed++;
                    found = funcCall.search(word, wordSize, search_letter, correctGuesses);
                    if (!found)
                        chancesLeft--;

                } else if (selection == 2) {
                    found = funcCall.guessWord(word);
                    if (!found)
                        chancesLeft--;
                    else {
                        score++;
                        for (int i = 0; i < word.length(); i++)
                            correctGuesses[i] = 1;
                        word_win = true;
                        break;
                    }
                } else if (selection == 3)
                    return 0;

            } while (selection != 3);
        }
    } while (selection != 3);

    //Exit
    system("pause");
    return 0;
}

 void clearScreen() //clears screen
    {
    cout << string( 100, '\n' );
    };

