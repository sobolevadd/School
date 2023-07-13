#include "seznam.h"

#include <iostream>

void vytvorSeznam(Seznam *us){
    us->hlava = new Prvek;
    us->hlava->dalsi = nullptr;
    us->zarazka = us->hlava;
}

void zrusSeznam(Seznam *us){
    vycistiSeznam(us);
    delete us->hlava;
    us->hlava = nullptr;
    us->zarazka = nullptr;
}


void vlozNaZacatek(Seznam *us, Data co){
    Prvek *pom = new Prvek;
    pom->data = co;
    pom->dalsi = us->hlava;
    us->hlava = pom;
}

void vlozNaKonec(Seznam *us, Data co){
    Prvek *pom = new Prvek;
    us->zarazka->data = co;
    us->zarazka->dalsi = pom;
    us->zarazka = pom;
}

void tisk(Seznam *us){
    Prvek *ukaz = us->hlava;
    while(ukaz != us->zarazka){
        std::cout << ukaz->data << std::endl;
        ukaz = ukaz->dalsi;
    }
}

void smazPrvni(Seznam *us){
    Prvek *prvni = us->hlava;
    us->hlava = us->hlava->dalsi;
    delete prvni;
}


bool jePrazdny(Seznam *us){
    /*if(us->hlava == us->zarazka){
        return true;
    } else{
        return false;
    }*/
    return (us->hlava == us->zarazka);
}

void vycistiSeznam(Seznam *us){
    while(!jePrazdny(us)){
        smazPrvni(us);
    }
}


Prvek* najdiVSeznamu(Seznam *us, Data co){
    us->zarazka->data = co;
    Prvek *ukaz = us->hlava;
    while(ukaz->data != co){
        ukaz = ukaz->dalsi;
    }
    /*if(ukaz == us->zarazka){
        return nullptr;
    } else{
        return ukaz;
    }*/
    return (ukaz == us->zarazka ? nullptr : ukaz);
}


void smazZa(Seznam *us, Prvek *za){
    Prvek *naslednik = za->dalsi;
    if(naslednik == us->zarazka){
        us->zarazka = za;
    }
    za->dalsi = naslednik->dalsi;
    delete naslednik;
}

bool smaz(Seznam *us, Data co){
    Prvek *p = najdiVSeznamu(us, co);
    if(!p){
        return false;
    }
    p->data = p->dalsi->data;
    smazZa(us, p);
    return true;
}
