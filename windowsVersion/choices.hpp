#ifndef CHOICES_HPP
#define CHOICES_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "manager.hpp"

unsigned inputVal(unsigned choice){
        return ((choice > 5) || (choice < 1)) ? 0 : choice;
}

class choice{
 public:
    string storage [8] = {};
    unsigned right;
    choice(string arr[], unsigned n): right(n){
        for(unsigned i = 0; i < 9; i++){
            storage[i] = arr[i];
        }
    }
    choice():right(0){};
    void outputOptions(){
        for(unsigned i = 0; i < 4; i++){
            cout << i+1 << ". " << storage[i] << endl;
        }
        return;
    }
    unsigned getInput(){
        unsigned temp = 0;
        cout << "Your choice: ";
        cin >> temp;
        cin.ignore(256,'\n');
        cout << endl;
        while(inputVal(temp) == 0){
            cout << "Invalid input. Try again or press 5 to quit. ";
            cin >> temp;
            cin.ignore(256,'\n');
            cout << endl;
        }

        if(temp == 5){
            cout << "Goodbye!" << endl;
            exit(0);
        }
        return temp;
    }
    void outputCons(unsigned n){
        cout << n << ". " << storage[n+3] << endl;
        return;
    }
    void runOptions(){
        unsigned temp = 0;
        while(temp != right){
            cout << endl;
            this->outputOptions();
            cout << endl;
            temp = this->getInput();
            this->outputCons(temp);
        }
        return;
    }
};

#endif 