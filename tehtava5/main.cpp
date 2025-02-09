#include <iostream>
#include "seuraaja.h"
#include "notifikaattori.h"

using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.add(&a);
    n.add(&b);
    n.add(&c);
    n.print();

    n.post("Tama on viesti 1");

    n.del(&b);

    n.post("Tama on viesti 2");

    return 0;
}
