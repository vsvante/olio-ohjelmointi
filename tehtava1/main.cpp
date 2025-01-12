#include <iostream>
#include <cstdlib>
#include <ctime>

int game(int maxnum);

int main() {
    int maxnum = 20;
    int numberOfGuesses = game(maxnum);
    std::cout << "Arvasit oikein " << numberOfGuesses << " yrityksella." << std::endl;
    return 0;
}

int game(int maxnum) {
    std::srand(std::time(0));
    int randomNumber = std::rand() % maxnum + 1;
    int guess = 0;
    int guessCount = 0;

    std::cout << "Arvaa ohjelman arpoma luku 1-" << maxnum << "." << std::endl;

    while (guess != randomNumber) {
        std::cout << "Anna arvauksesi: ";
        std::cin >> guess;
        guessCount++;

        if (guess < randomNumber) {
            std::cout << "Luku on suurempi." << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Luku on pienempi." << std::endl;
        } else {
            std::cout << "Oikea vastaus! Luku oli " << randomNumber << "." << std::endl;
        }
    }

    return guessCount;
}
