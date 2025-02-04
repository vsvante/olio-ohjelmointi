#include "customer.h"

Customer::Customer(string n, double cl) : checkingaccount(n), creditaccount(n, cl)
{
    name = n;
    cout << "Asiakkuus luotu " << name << endl;
}

bool Customer::deposit(double sum)
{
    return checkingaccount.deposit(sum);
}

bool Customer::withdraw(double sum)
{
    return checkingaccount.withdraw(sum);
}

bool Customer::payCredit(double sum)
{
    return creditaccount.deposit(sum);
}

bool Customer::useCredit(double sum)
{
    return creditaccount.withdraw(sum);
}

bool Customer::transfer(double sum, Customer &recipient)
{
    if (checkingaccount.withdraw(sum)) {
        recipient.deposit(sum);
        cout << "Pankkitili: " << name << " siirtaa " << sum << " " << recipient.getName() << ":lle" << endl;
        return true;
    }
    return false;
}

void Customer::showSaldo() const
{
    cout << name << endl;
    cout << "Kayttotilin saldo " << checkingaccount.getBalance() << endl;
    cout << "Luottotilin saldo " << creditaccount.getCreditBalance() << endl;
}

string Customer::getName() const
{
    return name;
}

