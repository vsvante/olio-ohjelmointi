#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>

using namespace std;

class Bankaccount
{
public:
    Bankaccount(string o);

    virtual bool withdraw(double sum);
    virtual bool deposit(double sum);

    double getBalance() const;

protected:
    string owner;
    double balance = 0;
};

#endif // BANKACCOUNT_H
