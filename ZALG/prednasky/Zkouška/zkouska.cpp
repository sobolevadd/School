#include <iostream>
using namespace std;

struct Uzel { 
    int data; 
    Uzel* dalsi; 
};

Uzel* Vlozeni(Uzel* hlava, int hodnota) {                               //definujeme funkci, ktera vklada novy prvek do seznamu
    Uzel* newUzel = new Uzel; 
    newUzel->data = hodnota;                                            //vytvarime novy prvek
    newUzel->dalsi = nullptr;                                           // nastavujeme hodnotu na ukazatel nullptr

    if (hlava == nullptr || hodnota > hlava->data) {                    //pokud je hlava seznamu prazdna a hodnota mensi nez hodnota 1. prvku
        newUzel->dalsi = hlava;                                         // pak novy prvek stane novou hlavou, nastavime ukazatel noveho prvku na hlavu
        return newUzel;                                                 //pak pridavame 1. prvek do seznamu a vratime ukazatel na tento prvek
    }
    
    Uzel* pom = hlava;                                                  //vytvarim pomocnou promennou, ktera prochazi seznma od zacatku
    while (pom->dalsi != nullptr && pom->dalsi->data > hodnota) {       // prochazime seznam dokud nedojdeme na konec anebo dokud nenajdeme prvek s vetsi hodnotou
        pom = pom->dalsi;                                               // pokud narazime na takovz prvek, bude ukazovat na predchozi
    }

    newUzel->dalsi = pom->dalsi;                                        //ukazatel na prvek ktery sleduje po pomccnem
    pom->dalsi = newUzel;                                               // vlozime prvek na spravne misto

    return hlava;
}

void VytiskniSeznam(Uzel* hlava) {
    if(hlava == nullptr) {
        cout << "Seznam je prazdny" << endl;
        return;
    }

    cout << "Prvky seznamu: ";
    
    Uzel* pom = hlava;
    while (pom != nullptr) {
        cout << pom->data << " ";
        pom = pom->dalsi;
    }
    cout << endl;
}

int main() {
    Uzel* hlava = nullptr;

    int cisla[] = {5, 19, 3, 78, 23, 0};

    for (int i = 0; i < sizeof(cisla) / sizeof(cisla[0]); i++) {
        hlava = Vlozeni(hlava, cisla[i]);
    }

    VytiskniSeznam(hlava);
    Vlozeni(hlava, 20);
    VytiskniSeznam(hlava);
    return 0;
}

