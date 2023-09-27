/*
Prikazy:
- prazdny prikaz (;)

        for (int i = 0; i < 10; i++);
            cout << i << endl;              CHYBA  i nebude znamy 

        int i;
        for ( i = 0; i < 10; i++);
            cout << i << endl;              vypise 10 

- spozeny prikaz ({});
    telo funkce, telo cyklu

    c = c + 1; //c++  operator prerazeni
    == operator rovnosti

-Zakladni koncepty:
        - posloupnosti
        - vetveni
        - cyklus
        - podprogramy

-Prikazy pro vetveni :
        - if
        - else
        - switch

            switch (selector) {
                case h1:
                    p11
                    p12
                case h2:
                    p21
                    p22
                .
                .
                .
                default:
                    p1
                    p2
            }

- Cyklus (while, dowhile)

        dowhile  - podminka za telem, vykona jenom jednou
        while    - podminka v tele

        for (inicializace; podminka; krok) {
            telo
        }                                       1. se provede inicializace, zkontroluje podminku, dela se krok, kdyz podminka neplati, skonci

        for ---> while 

        {   inicializace;
            while(podminka) {
            telo
            krok
            }
        }


        Ukonceni while uprostred == break, return, continue ukonci jenom jeden pruchod.


Promenna - musime zadat typ a jmeno (identificator) je mozny do toho ulozit hodnotu. 
        je to pojmenovany blok pameti.

int - se znamenkem
unsigned int - bez znamenka

datove struktury nemaji nekonecnou pamet :) (factorial)
Priklady:

1/2 == 0
0.5
1.0/2 (pouzit aspon jednu jako realnou konstantu)

float x = 0.0;           =<
while (x! = 1.0)
{
    cout << x << endl;
    x = x + 0.1;
}                        pouzit +- nejaky epsilon

Znaky se ukladaji do typu char
Logicke hodnoty typ bool (true, false) logiske operace dva ampersanty, dva pipy, vykricnik
Typ void - funkce ktera nic nevraci . Priklad s ukazateli

4. koncept - podprogramy

predavani hodnotou - vytvori se kopie
pole jako parametr funkce - bude process manipulovat primo s tou funkci

vystup a vstup funkce main

dynamicka alokace pameti - nemusim ynat kolik pameti potrebuju alokovat
 - ukazatel
 - operator new
 - operator delete


*/