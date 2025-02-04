#include "creditaccount.h"
#include <iostream>

Creditaccount::Creditaccount(string o, double cl) : Bankaccount(o), creditLimit(cl)
{
    balance = 0;
    cout << "Luottotili luotu " << owner << ":lle, luottoraja " << creditLimit << endl;
}

bool Creditaccount::withdraw(double sum)
{
    if (sum <= 0 || (balance - sum) < -creditLimit) {
        cout << "Luottotili: Nosto epaonnistui." << endl;
        return false;
    }
    balance -= sum;
    cout << "Luottotili: nosto " << sum << " tehty, luottoa jaljella " << creditLimit + balance << endl;
    return true;
}

bool Creditaccount::deposit(double sum)
{
    if (sum <= 0 || (balance + sum) > 0) {
        cout << "Luottovelan maksu epaonnistui." << endl;
        return false;
    }
    balance += sum;
    cout << "Luottovelan maksu " << sum << " tehty" << endl;
    return true;
}

double Creditaccount::getCreditBalance() const
{
    return balance;
}
