#include "seuraaja.h"

Seuraaja::Seuraaja(string n)
{
    name = n;
    cout << "Luodaan seuraaja " << name << endl;
}

void Seuraaja::update(string message)
{
    cout << "Seuraaja " << name << " sai viestin " << message << endl;
}

string Seuraaja::getName() const
{
    return name;
}
