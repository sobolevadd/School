#include <iostream>

using namespace std;

enum{OK};

class watcher
{
    public: 
    watcher()
    {
        cout << "Attention!!!" << endl;
    }
};

int i = 42;

void function1(int n)
{
    int i = 9;
    {
        cout << ::i << endl; // :: vyvolaji globalni promennou/jmeno, funkce v tomhle pripade 42, jinak bude se pouzivat lokalni promenna
        cout << i << endl;
        int i = 2;
        cout << i << endl;
    }
    cout << i << endl;
    //if(int x; n = 42) watcher x;  // (neco; a jen pak podminka)// jakmile opustime prikaz if x prestane existovat
}

int main()
{
    // int i;
    // i = 9.1; //vypise jenom 9, yaokruhluje dolu, protoze int, ma byt float aby vypsalo normalne
    //5; //vyrazovy prikaz, zakazan v c# a java
    ; //prazdny prikaz
    {} //prazdny blok
    (void)0; //prazdny prikaz, ktery nic nedela
    // int i = 9;
    // if(i)
    // {
    //     int j = 10;
    // }
    function1(0);
    int pole[5] = {}; // je to vynulovany
    for(int i = 0, j = 4; i < j; i++, j--) //swap
    {

    }
    return OK;
}
 
//PRIKAZY 

// while(podm) prikaz
// while(podm); doporucuje se psat strednik na dalsi radku , popripade pridat prazdny blok
// do prikaz while(podm);

// for(inicializace, podminka, krok) prikaz // provede se inicializace, zkontroluje se pominka, kdyz neni splnena skonci
// v inicializaci muzu deklarovat jak promennou tak i promenne

// if (podm) prikaz
// if (podm) prikaz else prikaz

//break, continue, goto, return, asm
