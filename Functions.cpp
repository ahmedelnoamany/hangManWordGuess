/* 
 * File:   Functions.cpp
 * Author: Ahmed Elnoamany
 * Created on September 19, 2016, 2:54 PM
 */
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <ctype.h>
#include "Functions.h"
using namespace std;

void Functions::displayWord(string word,int size, bool identified[20]){
    //center the word
    for (int i = 0; i < (40 - size); i++)
        cout << " ";

    for (int i = 0; i < size; i++) {
        //If character was previously found, or character is space, display the character
        if (identified[i] || word[i] == '	' || word[i] == ' ')
            cout << word[i] << " ";
        else
        //Otherwise display "_"
            cout << "_" << " ";
    }
    cout << endl << endl;
    
}
    
bool Functions::search(string word, int size, char search_letter, bool identified[]){
    //found flag
    bool found = false;

    //search array for letter
    for (int i = 0; i < size; i++) {
        if (word[i] == search_letter) {
            //if found, set flag, set bool array at that position
            found = true;
            identified[i] = true;
        }
    }
    return found;
}
    
string Functions::chooseWord(){
    fstream word_list("wordlist.txt");
    string word;
    int counter = 0;
    while (!word_list.eof()) {
        getline(word_list, word, '\n');
        counter++;
    }
    srand(time(0));
    int random_selection = rand() % counter;
    word_list.clear();
    word_list.seekg(word_list.beg);
    for (int i = 0; i < counter || !word_list.eof(); i++) {
        getline(word_list, word, '\n');
        if (i == random_selection)
            break;
    }


    //cout << "selection: " << random_selection << endl;
    return (word);
}
    
bool Functions::save(int score){
    ofstream savefile("save.txt");
    if (savefile) {
        savefile << score << endl;
        savefile.close();
        return true;
    } else
        return false;
}
    
bool Functions::load(int &score){
    ifstream savefile("save.txt");
    if (savefile) {
        savefile >> score;
        savefile.close();
        return true;
    } else
        return false;
}
    
char Functions::guessLetter(char guessed[], int numCharGuessed){
    char letter;
    int flag;
    flag = 1;
    cout << " Please enter letter: " << endl;
    cin>> letter;
    
    while(!isalpha(letter)){
        cout<<"Invalid entry!!"<<endl;
        cout << " Please enter letter: " << endl;
        cin>> letter;
    }
            
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;
        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    for (int i = 0; i <= numCharGuessed; i++)
        if (guessed[i] == letter) {
            cout << "This letter has already been guessed, Please enter a different letter: ";
            cin>>letter;

        }
    

    return letter;
}
    
bool Functions::guessWord(string word){
    cout << endl << word;
    string guess;
    cout << " Please enter your guess: ";
    cin>>guess;
    for (int i = 0; i < 100; i++) {
        if (guess[i] == word[i])
            return true;
        else
            return false;
    }
}
    
bool Functions::gameOver(int score) {
    cout << " GAME OVER!" << endl;
    cout << " Your Final Score Is: " << score;
    return true;
}


