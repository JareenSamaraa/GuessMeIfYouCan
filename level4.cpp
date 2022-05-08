
#include <bits/stdc++.h>
#include "Levels.h"

using namespace std;
int MinRange4;
int MaxRange4;
int chagneTurnsL4;

int turns4(int MinRange4, int MaxRange4)
{
    return chagneTurnsL4 = log2(MaxRange4 - MinRange4); // low difficulty level
}


void handleWinOrLoose(int pcGuess, int tryLeft)
{
    if(tryLeft > 0)
    {
        cout <<"\n\tHoorrayyyy!!! You Did it " << GetPlayerName() << "!!!" << endl;
        cout <<"\tThe correct guess was: " << pcGuess << endl;
        cout << "\t\t\t\t\ Congratulations!!!" << endl;
        cout << "\n\t You passed all the levels and You Are The WINNER!!!" <<endl;
                        exit(0);

    }

    else
    {
        cout << "\n\n\t Sorry! you FAILED this level!." << endl;
        cout << "\n\t Do You want to try the level again? Y/N? ";
        string tryAgain;
        while(1)
        {
            cin >> tryAgain;
            if(tryAgain == "Y" or tryAgain == "y")
            {
                LevelFour();
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


int LevelFour()
{
    while(1)
    {

        cout << "\n\n\n\n \t\t\t\tLevel : 4" <<endl;
        cout<<"\n\nChoose a Minimum range you would like to guess:" <<endl;
        cout << "\tYour MIN: ";
        cin>> MinRange4;
        cout<<"Choose a Maximum range you would like to guess :"<< endl;
        cout << "\tYour MAX: ";
        cin>> MaxRange4;

        if(MaxRange4-MinRange4 < 499)
        {
            cout<<"\n\t Invalid Input!" <<endl;
            cout<< "\t \nTry again! \nPlease make sure the difference between your Minimum and Maximum range is at least 500 or greater."<< endl;
        }
        else
        {
            break;
        }
    }

    cout <<"\n\tI Have guessed a number between " << MinRange4 <<" and " << MaxRange4 << " ."<<endl;
    turns4(MinRange4,MaxRange4);
    cout<< "\tRemember! Your turns left will be changed dynamically based on your every guess. But I can assure to give you the minimum turns you need to pass the level if you play optimally!"<<endl;
    cout <<"\tNow Can you tell which number is it? Currently your allocated turns left are: " << chagneTurnsL4 << endl;
    cout<<"\t\t So, Guess me if you can!"<<endl;

    int pcGuess = GuessRandom(MinRange4, MaxRange4);

    int playerGuess;
    int tryLeft = chagneTurnsL4;
    int maxLeft = MaxRange4, minLeft = MinRange4;
    while(1)
    {
        cout << "\nYour guess: ";
        cin >> playerGuess;


        if(playerGuess == pcGuess)
        {
            handleWinOrLoose(pcGuess, tryLeft);
            break;
        }

        else if(playerGuess > pcGuess)
        {
            cout << "\tGuess Something Lower" << endl;
            maxLeft = min(maxLeft, playerGuess);
        }
        else
        {
            cout << "\tGuess Something Higher" << endl;
            minLeft = max(minLeft, playerGuess);
        }

        tryLeft = min(tryLeft-1, turns4(minLeft, maxLeft));

        cout << "Level 4: \t\t\t\t\t Turns Left: " << tryLeft << endl;
        if(tryLeft <= 0){
            handleWinOrLoose(pcGuess, 0);
        }
    }
}

