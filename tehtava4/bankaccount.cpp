#include "bankaccount.h"

Bankaccount::Bankaccount(string o) : owner(o) {}

bool Bankaccount::withdraw(double sum)
{
    if (sum <= 0 || sum > balance) {
        cout << "Nosto epaonnistui." << endl;
        return false;
    }
    balance -= sum;
    cout << "Pankkitili: " << owner << " nosti " << sum << " tehty" << endl;
    return true;
}

bool Bankaccount::deposit(double sum)
{
    if (sum <= 0) {
        cout << "Talletus epaonnistui." << endl;
        return false;
    }
    balance += sum;
    cout << "Pankkitili: talletus " << sum << " tehty" << endl;
    return true;
}

double Bankaccount::getBalance() const
{
    return balance;
}
