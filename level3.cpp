#include <bits/stdc++.h>
#include "Levels.h"

using namespace std;
int MinRange3;
int MaxRange3;
int fixedTurns3;

int turns3(int MinRange3, int MaxRange3)
{
    return fixedTurns3 = log2(MaxRange3 - MinRange3); // low difficulty level
}


void handleWin3(int pcGuess, int tryCount)
{
    cout <<"\n\tYou Did it " << GetPlayerName() << "!!!" << endl;
    cout <<"\tThe correct guess was: " << pcGuess << endl;

    if(tryCount <= fixedTurns3)
    {
        cout << "\tCongratulations for making it to LEVEL 4!" << endl;

        /// level 4 ekhane start hobe.
        LevelFour();
    }
    else
    {
        cout << "But sorry that you couldn't make it to the Level 3." << endl;
        cout << "If you can pass the Level with maximum " << fixedTurns3 << " tries, you will be moved to Level 3!" << endl;
        cout << "Do You want to try the level again? Y/N? ";
        string tryAgain;
        while(1)
        {
            cin >> tryAgain;
            if(tryAgain == "Y" or tryAgain == "y")
            {
                LevelThree();
            }
            else if(tryAgain =="N" or tryAgain == "n")
            {
                cout << "Okay! Hope to see you sometime soon!!" << endl;
                exit(0);
            }

            else
            {
                cout << "Please Choose Y or N !" << endl;
            }
        }
    }
}


int LevelThree()
{
    while(1)
    {

        cout << "\n\n\n\n \t\t\t\tLevel : 3" <<endl;
        cout<<"\n\nChoose a Minimum range you would like to guess:" <<endl;
        cout << "\tYour MIN: ";
        cin>> MinRange3;
        cout<<"Choose a Maximum range you would like to guess :"<< endl;
        cout << "\tYour MAX: ";
        cin>> MaxRange3;

        if(MaxRange3-MinRange3<99)
        {
            cout<<"\n\t Invalid Input!" <<endl;
            cout<< "\t \nTry again! \nPlease make sure the difference between your Minimum and Maximum range is at least 100 or greater."<< endl;
        }
        else
        {
            break;
        }

    }

    cout <<"\n\tI Have guessed a number between " << MinRange3 <<" and " << MaxRange3 << " ."<<endl;
    turns3(MinRange3,MaxRange3);
    cout <<"\tCan you tell which number is it? If you can guess the number within first  " << fixedTurns3 << "  attempts, you will pass this level!"<< endl;
    cout<<"\t\t So, Guess me if you can!"<<endl;



    int pcGuess = GuessRandom(MinRange3, MaxRange3);

    int playerGuess;
    int tryCount = 0;
    while(1)
    {
        cout << "\nYour guess: ";
        cin >> playerGuess;
        tryCount ++;

        cout << "Level 3: \t\t\t\t\t Count: " << tryCount << endl;

        if(playerGuess == pcGuess)
        {
            handleWin3(pcGuess, tryCount);
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



