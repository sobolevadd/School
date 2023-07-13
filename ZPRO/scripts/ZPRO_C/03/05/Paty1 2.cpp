// Pátý program: nápis objektovì
// vše v jednom souboru

#include <cstring>
#include <iostream>
using namespace std;

class napis 
{
    char text[100];
public:
    napis(char zadani[]);
    void nastav(char zadani[]);
    void vypis();
};

napis::napis(char zadani[])
{
   nastav(zadani);
}

void napis::nastav(char zadani[])
{
  strcpy(text, zadani);
}


void napis::vypis()
{
  cout << text << endl;
}

int main()
{
  napis pozdrav("Ahoj, lidi");
  pozdrav.vypis();
  pozdrav.nastav("Nazdar, vy tam");
  pozdrav.vypis();
}