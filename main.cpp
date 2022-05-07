#include <bits/stdc++.h>
#include "Levels.h";

using namespace std;
// \\ # "
string playerName;

string GetPlayerName(){
    return playerName;
}

void welcome(){
    cout << "Please enter your name: " ;
    cin >> playerName;
    cout << "Hello " << playerName <<"," << endl;
    cout << "\t" << "Welcome to play Guess me If you can!" << endl;
    cout << "\t" << "The rules are simple, I will guess a number between 1 to 10," << endl;
    cout << "\t" << "then, you will try guessing that number!" << endl;
    cout << "\t" << "Don't get scared, Whenever you guess something wrong, my hints will be with you!\n" << endl;
    cout << "\t" << "So, Lets begin!" << endl;
    cout << "\t" << "Good Luck! " << playerName << endl;
}

int main()
{
   welcome();
   LevelOne();
   LevelTwo();
}
