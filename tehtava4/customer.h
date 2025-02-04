#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "bankaccount.h"
#include "creditaccount.h"

using namespace std;

class Customer
{
public:
    Customer(string n, double lr);

    bool deposit(double sum);
    bool withdraw(double sum);
    bool payCredit(double sum);
    bool useCredit(double sum);
    bool transfer(double sum, Customer &recipient);

    void showSaldo() const;

    string getName() const;

private:
    Bankaccount checkingaccount;
    Creditaccount creditaccount;
    string name;
};

#endif // CUSTOMER_H
