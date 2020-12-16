#ifndef MANAG_HPP
#define MANAG_HPP
#include <iostream>
#include <string>
#include <vector>

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
    
    return;
}

void gameEnd(){
    cout << "Goodbye !" << endl;
    exit(0);
}

#endif