// Soubor 01-08.cpp
// Prvni objektovy program v C++
// Opet pouze napis, jako na pocatku, tentokrat ale definujeme napis jako
// objektovy typ a jeho tisk jako metodu

#include <iostream>
#include <cstring>
using namespace std;

// deklarace tridy Napis
class Napis
{
  public:   	// verejne pristrupne slozky, smi je pouzivat
		// kterakoli soucast programu

  Napis();  	// Konstruktor bez parametru (konstruktor se vzdy jmenuje
		// stejne jako trida
  Napis(char x[]); // konstruktor s parametrem typu pole znaku
  ~Napis(); 	// Destruktor - jmenuje se vzdy jako trida, navic zacina
		// vzdy znakem "~" a nesmi mit zadne parametry
  void Vypis(); // Vytiskne napis

  private:  	// soukrome slozky, smeji je pouzivat pouze metody
	    	// teto tridy
  char text[100];   // pole 100 znaku
};


// definice metod

// Konstruktor bez parametru
Napis::Napis()
{
 text[0] = '\0'; // ulozi do prvniho prvku znak '\0'
		 // jt. prazdny retezec
}

// Konstruktor s jednim parametrem typu pole znaku
// (ve skutecnosti se predava ukazatel, mohli bychom psat Napis(char* t)
Napis::Napis(char t[])
{
  if(t)               // neni-li to ukazatel nikam (0)
    {
     strcpy(text, t); // prekopiruj retezec do pole text
    }                // pomoci standardni funkce strcpy (hlav. soubor string.h)
}

void Napis::Vypis()
{
  cout << text << endl;
}

Napis::~Napis()
{
  cout << "zanikla instance tridy napis" << endl;
}


Napis N1("Jak se vam to zamlouva?");  // Deklarace instance znamena volani konstruktoru

int main()
{
 N1.Vypis();	// Volani metody globalni instance
 Napis N2("Takhle to jde taky");
 N2.Vypis();
 return 0;
}

// Destruktor se zavola automaticky pri zaniku instance,
// tj. pro N1 pri skonceni programu, pro N2 pri opusteni funkce main()