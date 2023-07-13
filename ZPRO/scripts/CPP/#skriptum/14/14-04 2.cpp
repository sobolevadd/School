// Soubor 14-04.cpp
// SDchematicky priklad
// Ukazuje definici soukromeho vnoreneho typu

typedef int data;
class seznam {
	class prvek {			// Definice soukromého vnoøeného typu
		data hodnota;
		prvek * dalsi;
		static int pocet;
	public:
		prvek(data h);
		data& Hodnota();
		prvek* &Dalsi() {return dalsi;}
	};
	prvek * hlava;
public:
	seznam();
	~seznam();
	void vloz(data d);
	// ...a další metody
};
int seznam::prvek::pocet = 0; 				// Statický prvek 

seznam::prvek::prvek(data d) 				// Metody vnoøeného typu
:hodnota(d){}

data& seznam::prvek::Hodnota()
{ return hodnota;
}

int main()
{
	// seznam::prvek P(0); // Chyba: typ není pøístupný, je soukromý ve tøídì seznam
}