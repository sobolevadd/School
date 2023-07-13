#include <iostream>
#include<string>
#include "seznamVirius.h"

using namespace std;

int main(){
    Seznam vstup;
    vytvor_seznam(vstup);
    string radek;
    while(getline(cin, radek)){
        vloz_na_konec(vstup, radek);
    }
    serad(vstup);
    vypis(vstup);
    zrus(vstup);
}