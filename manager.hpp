#ifndef MANAG_HPP
#define MANAG_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "choices.hpp"

void game();
void gameEnd();
unsigned inputValidation();
void primaryText();
void choices();
void education();
void finPrint();

void game(){
    cout << "Loading Game. Do not edit any files..." << endl;
    string narration [57] = {};
    string facts [20] = {};
    string tempArray [8] = {};
    string choiceCorrect [16] = {""};
    choice arChoices [16] = {};
    unsigned queue [93] = {""};
    string tempString;

    ifstream read("reading.txt");
    if(!read.is_open()){
        cout << "Error opening reading.txt" << endl;
        exit(1);
    }
    for(unsigned i = 0; i < 57; i++){
        getline(read, tempString);
        narration[i] = tempString;
    }
    read.close();

    ifstream read2("facts.txt");
    if(!read2.is_open()){
        cout << "Error opening facts.txt" << endl;
        exit(1);
    }
    for(unsigned i = 0; i < 20; i++){
        getline(read2, tempString);
        facts[i] = tempString;
    }
    read2.close();

    ifstream read3("options.txt");
    if(!read3.is_open()){
        cout << "Error opening options.txt" << endl;
        exit(1);
    }
    for(unsigned i = 0; i < 16; i++){
        for(unsigned j = 0; j < 8; j++){
            getline(read3, tempString);
            tempArray[j] = tempString;
        }
        tempArray[9] = choiceCorrect[i];
        arChoices[i] = new choice(tempArray);
    }
    read3.close();

    return;
}

void gameEnd(){
    cout << "Goodbye !" << endl;
    exit(0);
}

#endif