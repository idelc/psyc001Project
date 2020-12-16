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
void primaryText();
void choices();
void education();
void finPrint();

void game(){
    cout << "Loading Game. Do not edit any files..." << endl;
    string narration [57] = {};
    string facts [20] = {};
    string tempArray [8] = {};
    int choiceCorrect [16] = {3, 1, 4, 2, 3, 4, 4, 4, 4, 1, 3, 2, 4, 4, 4, 1};
    choice *arChoices = new choice[16];
    unsigned queueG [93] = {1, 1, 3, 1, 1, 1, 2,
                        1, 3, 1, 1, 2, 1, 3,
                        1, 2, 1, 3, 
                        1, 1, 2, 1, 3, 1, 2,
                        1, 1, 3, 1, 2, 1, 1, 2,
                        1, 1, 1, 3, 1, 1, 1, 2,
                        1, 1, 3, 1, 2, 1, 1,
                        3, 1, 2, 1, 1, 2, 1,
                        3, 1, 2, 1, 1,
                        3, 1, 2, 1, 1, 1, 3,
                        1, 2, 1, 1, 2, 1, 3,
                        2, 1, 1, 3, 1, 2, 1,
                        1, 3, 2, 1, 1, 2, 1, 3,
                        1, 2, 1, 1};
    string tempString;

    cout << "Loading text..." << endl;
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

    cout << "Loading facts..." << endl;
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

    cout << "Loading choices...\n" << endl;
    ifstream read3("options.txt");
    if(!read3.is_open()){
        cout << "Error opening options.txt" << endl;
        exit(1);
    }
    for(unsigned i = 0; i < 16; i++){
        for(unsigned j = 0; j < 8; j++){
            getline(read3, tempString);
            arChoices[i].storage[j] = tempString;
        }
        arChoices[i].right = choiceCorrect[i];
    }
    read3.close();

    cout << "Welcome! This game is made to teach you the basics of neurons and neuroanatomy as covered in Psyc 1. Press 5 at any time to quit. Enjoy! \n" << endl;

    unsigned tempQ = 0, narCnt = 0, opCnt = 0, fCnt = 0; 
    for(unsigned i = 0; i < 93; i++){
        tempQ = queueG[i];
        switch (tempQ){
        case 1:
            cout << narration[narCnt++] << endl;
            break;
        case 2:
            cout << facts[fCnt++] << endl;
            break;
        case 3: 
            arChoices[opCnt++].runOptions();
            cout << endl;
            break;
        default:
            cout << "\n Error in game\n";
            exit(1);
            break;
        }
    }

    int tempEnd = 1;
    cout << "\n\n If you'd like to see the all the facts, press 0. Press anything else to quit." << endl;
    cin >> tempEnd;
    cin.ignore(256,'\n');
    cout << endl;
    for(unsigned i = 0; i < 20; i++){
        cout << facts[i];
    }
    cout << "\n\nPress any key to quit" << endl;
    cin >> tempEnd;
    return;
}

void gameEnd(){
    cout << "Goodbye!" << endl;
    exit(0);
}

#endif