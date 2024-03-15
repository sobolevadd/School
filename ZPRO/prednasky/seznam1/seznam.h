#ifndef SEZNAM_H
#define SEZNAM_H

#include "typ.h"

#include "prvek.h"

struct Seznam
{
    Prvek *hlava;
    Prvek *zarazka;
};

void vytvorSeznam(Seznam *us);
void zrusSeznam(Seznam *us);
void vlozNaZacatek(Seznam *us, Data co);
void vlozNaKonec(Seznam *us, Data co);
void tisk(Seznam *us);
void smazPrvni(Seznam *us);
bool jePrazdny(Seznam *us);
void vycistiSeznam(Seznam *us);
Prvek* najdiVSeznamu(Seznam *us,
                     Data co);
bool smaz(Seznam *us, Data co);


#endif // SEZNAM_H
