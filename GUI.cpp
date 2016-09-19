/* 
 * File:   GUI.cpp
 * Author: Ahmed Elnoamany
 * Created on September 19, 2016, 2:54 PM
 */
#include <iostream>
#include "GUI.h"
using namespace std;

void GUI::gUI(int chancesLeft, int score, char guessed_letters[], int numCharGuessed){
    cout << endl << endl << endl << endl;
    //Display the hangman + score (number of words guessed right so far)
    if (chancesLeft == 6) {
        clearScreen();
        cout << "   __________" << endl
                << "  |//        \\|" << "\t\t\t\t\t\t\t Your Score: " << score << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "_/|\\____________" << endl;
    } else if (chancesLeft == 5) {
        clearScreen();
        cout << "   __________" << endl
                << "  |//        \\|" << "\t\t\t\t\t\t\t Your Score: " << score << endl
                << "  |          |" << endl
                << "  |        (@_@)" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "_/|\\____________" << endl;
    } else if (chancesLeft == 4) {
        clearScreen();
        cout << "   __________" << endl
                << "  |//        \\|" << "\t\t\t\t\t\t\t Your Score: " << score << endl
                << "  |          |" << endl
                << "  |        (._.)" << endl
                << "  |          |" << endl
                << "  |          |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "_/|\\____________" << endl;
    } else if (chancesLeft == 3) {
        clearScreen();
        cout << "   __________" << endl
                << "  |//        \\|" << "\t\t\t\t\t\t\t Your Score: " << score << endl
                << "  |          |" << endl
                << "  |        (-.-)" << endl
                << "  |         /|" << endl
                << "  |        / |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "_/|\\____________" << endl;
    } else if (chancesLeft == 2) {
        clearScreen();
        cout << "   __________" << endl
                << "  |//        \\|" << "\t\t\t\t\t\t\t Your Score: " << score << endl
                << "  |          |" << endl
                << "  |        (-_-)" << endl
                << "  |         /|\\" << endl
                << "  |        / | \\" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "  |" << endl
                << "_/|\\____________" << endl;
    } else if (chancesLeft == 1) {
        clearScreen();
        cout << "   __________" << endl
                << "  |//        \\|" << "\t\t\t\t\t\t\t Your Score: " << score << endl
                << "  |          |" << endl
                << "  |        (Q_Q)" << endl
                << "  |         /|\\" << endl
                << "  |        / | \\" << endl
                << "  |         /" << endl
                << "  |        /" << endl
                << "  |" << endl
                << "  |" << endl
                << "_/|\\____________" << endl;
    } else if (chancesLeft == 0) {
        clearScreen();
        cout << "   __________" << endl
                << "  |//        \\|" << "\t\t\t\t\t\t\t Your Score: " << score << endl
                << "  |          |" << endl
                << "  |        (X_X)" << endl
                << "  |         /|\\" << endl
                << "  |        / | \\" << endl
                << "  |         / \\" << endl
                << "  |        /   \\" << endl
                << "  |" << endl
                << "  |" << endl
                << "_/|\\____________" << endl;
    }

    //display a line across screen
    for (int i = 0; i < 80; i++)
        cout << "-";
    cout << endl;

    //display the letters that have already been guessed
    cout << "You have guessed the following letters: " << endl;
    if (numCharGuessed == 0)
        cout << "\t\t\t\t     Nothing!! ";
    else
        for (int i = 0; i < numCharGuessed; i++)
            cout << guessed_letters[i] << "\t";
    cout << endl << endl;

    //display the number of chances that are left
    for (int i = 0; i < 27; i++)
        cout << " ";
    cout << "You have " << chancesLeft << " chances left!!!" << endl << endl;
}

void GUI::clearScreen(){
    cout << string( 100, '\n' );
}


