#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    cout << "Guess the random number between 1 and 20" << endl;

    Game gameolio(20);
    gameolio.play();

    return 0;
}
