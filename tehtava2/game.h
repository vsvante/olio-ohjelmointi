#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game
{
public:
    Game(int maxNum);
    ~Game();

    void play();

private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

    void printGameResult();
    void generateRandomNumber();
    void askForGuess();

};

#endif // GAME_H
