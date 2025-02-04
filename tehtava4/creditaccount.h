#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "bankaccount.h"

class Creditaccount : public Bankaccount
{
public:
    Creditaccount(string o, double cl);

    virtual bool withdraw(double sum) override;
    virtual bool deposit(double sum) override;

    double getCreditBalance() const;

private:
    double creditLimit;
};

#endif // CREDITACCOUNT_H
