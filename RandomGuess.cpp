#include <bits/stdc++.h>
#include "Levels.h";

using namespace std;

int GuessRandom(int startNum, int endNum){
    srand(time(0)); // Changing seed

    int difference = endNum - startNum + 1;
    int guessedNum = rand() % (difference) + startNum;
    return guessedNum;
}
