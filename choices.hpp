#ifndef CHOICES_HPP
#define CHOICES_HPP
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "manager.hpp"

unsigned inputVal(unsigned choice){
        return (choice > 5) ? 0 : choice;
}

class choice{
 public:
    string storage [9] = {};
    unsigned right;
    choice(string arr[], unsigned n): right(n){
        for(unsigned i = 0; i < 9; i++){
            storage[i] = arr[i];
        }
    }
    choice():right(0){};
    void runOptions(){
        unsigned temp = 0;
        for(unsigned i = 0; i < 4; i++){
            cout << i << ". " << storage[i];
        }
        cout << endl;
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
            gameEnd();
        }

        do{
            cout << storage[temp + 3];
        }
        while(temp != right);
        return;
    }
};

#endif 