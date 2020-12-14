#include <iostream>
#include <string>
#include <list>

using namespace std;
string userName;

void narrator();
void gameEnd();
void game();
unsigned gameStart();

void game(){
    bool cont = 0;
    cont = gameStart();
    if(!cont){
        gameEnd();
    }
    narrator();
    return;
}

void gameEnd(){
    cout << "Goodbye, " << userName << "!" << endl;
    exit(0);
}

unsigned gameStart(){
char prog;
    cout << "Welcome!\n" << endl; 
    cout << "What is your name?\n";
    cin >> userName;
    cout << "Nice to meet you " << userName << ", are tou ready to begin? (y/n)\n";
    cin >> prog;
    if((prog == 'Y')||(prog == 'y')){
        return 1;
    }
    return 0;
}

void narrator(){
    cout << "Let's go! (press q at any time to quit)";
}