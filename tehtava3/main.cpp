#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
    Chef c_olio("Gordon");

    int saladServings = c_olio.makeSalad(10);

    int soupServings = c_olio.makeSoup(9);

    ItalianChef i_olio("Mario");

    int pizzas = i_olio.askSecret("pizza", 12, 12);
    if (pizzas > 0) {
    } else {
        cout << "Failed to make pizza." << endl;
    }

    return 0;
}
