#include <iostream>
#include "seznam.h"

using namespace std;

int main()
{
    Seznam s;
    vytvorSeznam(&s);
    ///s.hlava = nullptr; -> unik pameti
    vlozNaKonec(&s, 5);
    vlozNaZacatek(&s, 7);
    vlozNaKonec(&s, 42);
    vycistiSeznam(&s);
    vlozNaKonec(&s, 123);
    tisk(&s);
    zrusSeznam(&s);
    return 0;
}
