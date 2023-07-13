#include <iostream>

using namespace std;

using T = int;
const T NULA = T{};

struct prvek {
    T data;
    prvek *dalsi;
};

struct seznam {
    prvek *hlava;
    prvek *zarazka;
};

void vytvor (seznam& s){
    s.hlava = s.zarazka = new prvek {NULA, nullptr};
}

void vloz_na_zacatek (seznam& s, T co){
    s.hlava = new prvek {co, s.hlava};
}

void vypis (seznam& s){
    for (prvek *pom = s.hlava; pom != s.zarazka; pom = pom->dalsi){
        cout << pom->data << endl;
    }
}

void zmen_hodnotu (seznam& s, T puvodni, T novy){
    for (prvek *pom = s.hlava; pom != s.zarazka; pom = pom->dalsi){
        if(pom->data == puvodni) pom->data = novy;
    }
    //break;
    return;
}

int najdi_velikost (seznam& s){
    int n = 0;
    for (prvek *pom = s.hlava; pom != s.zarazka; pom = pom->dalsi){
        n++;
    }
    return n;
}

int odstran_prvni (seznam& s){
    int n = 0;
    for (!prazdny(s)){

    }
}

bool prazdny(seznam& s){
    return s.hlava == s.zarazka;
}

int odstran_posledni(seznam& s){

}

int main(){
    seznam s;
    vytvor (s);
    vloz_na_zacatek(s, 1);
    vloz_na_zacatek(s, 2);
    vloz_na_zacatek(s, 6);
    vypis(s);
    cout << "Zmen hodnotu" << endl; 
    zmen_hodnotu(s, 2, 9);
    vypis(s);
    cout << "Velikost:" <<  najdi_velikost(s) << endl;
    odstran_prvni(s);
    return 0;
}