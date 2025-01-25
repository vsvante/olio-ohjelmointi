#include "chef.h"

Chef::Chef() {}

Chef::Chef(string name) {
    chefName = name;
    cout << "Chef " << chefName << " konstruktori" << endl;
}

Chef::~Chef() {
    cout << "Chef " << chefName << " destruktori" << endl;
}

string Chef::getChefName() const {
    return chefName;
}

int Chef::makeSalad(int ingredient) {
    int servings = ingredient / 5;
    cout << "Chef Gordon with " << ingredient << " items can make " << servings << " salad servings." << endl;
    return servings;
}

int Chef::makeSoup(int ingredient) {
    int servings = ingredient / 3;
    cout << "Chef Gordon with " << ingredient << " items can make " << servings << " soup servings." << endl;
    return servings;
}
