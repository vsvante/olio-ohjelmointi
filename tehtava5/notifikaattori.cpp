#include "notifikaattori.h"

Notifikaattori::Notifikaattori()
{
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::add(Seuraaja *newFollower)
{
    cout << "Notifikaattori lisaa seuraajan " << newFollower->getName() << endl;

    newFollower->next = seuraajat;
    seuraajat = newFollower;
}

void Notifikaattori::del(Seuraaja *delFollower)
{
    cout << "Notifikaattori poistaa seuraajan " << delFollower->getName() << endl;

    Seuraaja *current = seuraajat;
    Seuraaja *prev = nullptr;

    while (current != nullptr)
    {
        if (current == delFollower)
        {
            if (prev == nullptr)
            {
                seuraajat = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
}

void Notifikaattori::print()
{
    cout << "Notifikaattorin seuraajat: " << endl;

    Seuraaja *alku = seuraajat;
    while (alku != nullptr) {
        cout << "Seuraaja " << alku->getName () << endl;
        alku = alku->next;
    }
}

void Notifikaattori::post(string message)
{
    cout << "Notifikaattori postaa viestin " << message << endl;

    Seuraaja *current = seuraajat;
    while (current != nullptr)
    {
        current->update(message);
        current = current->next;
    }
}
