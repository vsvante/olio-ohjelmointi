#include "game.h"

Game::Game(int maxNum)
{
    maxNumber = maxNum;
    cout << "Game constructor " << "maxNumber is " << maxNumber << endl;
    srand(static_cast<unsigned int>(time(0)));
    generateRandomNumber();
}

Game::~Game()
{
    cout << "Game destructor" << endl;
}

void Game::generateRandomNumber()
{
    randomNumber = rand() % maxNumber + 1;
}

void Game::askForGuess()
{
    cout << "Enter your guess (1-" << maxNumber << "): ";
    cin >> playerGuess;
    cout << "Player guessed: " << playerGuess << endl;
}

void Game::play()
{
    cout << "Game start" << endl;
    numOfGuesses = 0;

    do {
        askForGuess();
        numOfGuesses++;

        if (playerGuess < randomNumber) {
            cout << "Too low!" << endl;
        } else if (playerGuess > randomNumber) {
            cout << "Too high!" << endl;
        } else {
            cout << "Correct!" << endl;
            break;
        }
    } while (playerGuess != randomNumber);

    printGameResult();
}

void Game::printGameResult()
{
    cout << "Game over. You guessed correctly." << endl;
    cout << "You guessed the number " << randomNumber << " correctly in " << numOfGuesses << " guesses" << endl;
}
