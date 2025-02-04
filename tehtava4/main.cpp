#include <iostream>
#include "bankaccount.h"
#include "customer.h"

using namespace std;

int main()
{
    Customer A("Aapeli", 1000);
    Customer B("Bertta", 1000);

    double amount;

    cout << "\nSyota talletussumma Aapelille: ";
    cin >> amount;
    A.deposit(amount);

    cout << "\nSyota nostosumma Aapelille (luottotili): ";
    cin >> amount;
    A.useCredit(amount);

    A.showSaldo();

    cout << "\nSyota talletussumma Bertalle: ";
    cin >> amount;
    B.deposit(amount);

    B.showSaldo();

    cout << "\nSyota siirrettava summa Aapelilta Bertalle: ";
    cin >> amount;
    A.transfer(amount, B);

    A.showSaldo();
    B.showSaldo();

    return 0;
}
