#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <iostream>

using namespace std;

class Seuraaja
{
public:
    Seuraaja(string n);
    string getName() const;
    void update(string message);

    Seuraaja *next = nullptr;

private:
    string name;
};

#endif // SEURAAJA_H
