#ifndef CHEF_H
#define CHEF_H

#include <iostream>

using namespace std;

class Chef {
public:
    Chef();
    Chef(string name);
    ~Chef();

    string getChefName() const;
    int makeSalad(int ingredient);
    int makeSoup(int ingredient);

protected:
    string chefName;
};

#endif // CHEF_H
