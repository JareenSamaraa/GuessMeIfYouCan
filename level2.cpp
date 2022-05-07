#include <bits/stdc++.h>
#include "Levels.h";

using namespace std;
int MinRange;
int MaxRange;
int fixedTurns;

int turns(int MinRange, int MaxRange)
{
    return fixedTurns = ((log2(MaxRange - MinRange))+1); // low difficulty level
}


void handleWin2(int pcGuess, int tryCount)
{
    cout <<"\n\tYou Did it " << GetPlayerName() << "!!!" << endl;
    cout <<"\tThe correct guess was: " << pcGuess << endl;

    if(tryCount <= fixedTurns)
    {
        cout << "\tCongratulations for making it to Level 3!" << endl;
        cout << "\Level 3 is now under construction, you can play the level 2 again!" << endl;

        /// level 3 ekhane start hobe.
    }
    else
    {
        cout << "But sorry that you couldn't make it to the Level 3." << endl;
        cout << "If you can pass the Level with maximum " << fixedTurns << " tries, you will be moved to Level 3!" << endl;
        cout << "Do You want to try the level again? Y/N? ";
        string tryAgain;
        while(1)
        {
            cin >> tryAgain;
            if(tryAgain == "Y" or tryAgain == "y")
            {
                LevelTwo();
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


int LevelTwo()
{
    while(1){

            cout << "\n\n\n\n \t\t\t\tLevel : 2" <<endl;
    cout<<"\n\nChoose a Minimum range you would like to guess:" <<endl;
    cout << "\tYour MIN: ";
    cin>> MinRange;
    cout<<"Choose a Maximum range you would like to guess :"<< endl;
    cout << "\tYour MAX: ";
    cin>> MaxRange;

     if(MaxRange-MinRange<80){
       cout<<"\n\t Invalid Input!" <<endl;
       cout<< "\t \nTry again! \nPlease make sure the difference between your Minimum and Maximum range is at least 80 or greater."<< endl;
    }
    else{
    cout <<"\n\tI Have guessed a number between " << MinRange <<" and " << MaxRange << " ."<<endl;
    turns(MinRange,MaxRange);
    cout <<"\tCan you tell which number is it? If you can guess the number within first  " << fixedTurns << "  attempts, you will pass this level!"<< endl;
    cout<<"\t\t So, Guess me if you can!"<<endl;



    int pcGuess = GuessRandom(MinRange, MaxRange);

    int playerGuess;
    int tryCount = 0;
    while(1)
    {
        cout << "\nYour guess: ";
        cin >> playerGuess;
        tryCount ++;

        cout << "Level 2: \t\t\t\t\t Count: " << tryCount << endl;

        if(playerGuess == pcGuess)
        {
            handleWin2(pcGuess, tryCount);
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

}
}
