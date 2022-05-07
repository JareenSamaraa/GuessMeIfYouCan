#include <bits/stdc++.h>
#include "Levels.h";

using namespace std;

void handleWin(int pcGuess, int tryCount)
{
    cout <<"\n\tYou Did it " << GetPlayerName() << "!!!" << endl;
    cout <<"\tThe correct guess was: " << pcGuess << endl;

    if(tryCount <= 3)
    {
        cout << "\tCongratulations for make it to Level 2!" << endl;
        LevelTwo();
    }
    else
    {
        cout << "But sorry that you couldn't make it to the Level 2" << endl;
        cout << "If you can pass the Level with Max 3 tries, you will be moved to Level 2" << endl;
        cout << "Do You want to try the level again? Y/N? ";
        string tryAgain;
        while(1)
        {
            cin >> tryAgain;
            if(tryAgain == "Y" or tryAgain == "y")
            {
                LevelOne();
            }
            else if(tryAgain =="N" or tryAgain == "n")
            {
                cout << "Okay! See you sometime soon again!" << endl;
                exit(0);
            }

            else
            {
                cout << "Please Choose Y or N !" << endl;
            }
        }
    }
}


int LevelOne()
{
    cout <<"Level : 1" <<endl;
    cout <<"\tI have guessed a number between 1 and 10"<<endl;
    cout <<"\tLet's Guess me if you can!"<<endl;


    int pcGuess = GuessRandom(1, 10);

    int playerGuess;
    int tryCount = 0;
    while(1)
    {
        cout << "Your guess: ";
        cin >> playerGuess;
        tryCount ++;

        cout << "Level 1: \t\t\t\t\t Count: " << tryCount << endl;

        if(playerGuess == pcGuess)
        {
            handleWin(pcGuess, tryCount);
            break;
        }

        else if(playerGuess > pcGuess)
        {
            cout << "\tGuess Something Lower" << endl;
        }
        else
        {
            cout << "\tGuess Something Higher" << endl;
        }
    }

}
