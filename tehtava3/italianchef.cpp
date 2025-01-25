#include "italianchef.h"

ItalianChef::ItalianChef() {}

ItalianChef::ItalianChef(string name) : Chef(name) {
    cout << "ItalianChef " << chefName << " konstruktori" << endl;
}

ItalianChef::~ItalianChef() {
    cout << "ItalianChef " << chefName << " destruktori" << endl;
}

bool ItalianChef::askSecret(string pw, int f, int w) {
    if (pw == password) {
        cout << "password ok!" << endl;
        return makePizza(f, w);
    } else {
        cout << "Incorrect password!" << endl;
        return false;
    }
}

int ItalianChef::makePizza(int f, int w) {
    int possiblePizzas = min(f / 5, w / 5);
    if (possiblePizzas > 0) {
        cout << "Chef Mario with "  << f << " flour and " << w << " water can make " <<  possiblePizzas << " pizzas." << endl;
        return true;
    } else {
        cout << "Not enough ingredients." << endl;
        return false;
    }
}
