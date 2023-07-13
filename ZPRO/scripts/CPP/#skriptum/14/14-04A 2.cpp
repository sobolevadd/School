// Soubor 14-04A.cpp
// Schematicky priklad
// Ukazuje deklaraci soukromeho vnoreneho typu
// s definic� mimo telo obklopujici tridy
// Pozor, nektere prekladace to neakceptuji, 
// i kdyz to je spravne


typedef int data;
class seznam {
	class prvek;
	prvek * hlava;
public:
	seznam();
	~seznam();
	void vloz(data d);
	// ...a dal�� metody
};

class seznam::prvek {			// Definice soukrom�ho vno�en�ho typu
	data hodnota;
	prvek * dalsi;
	static int pocet;
public:
	prvek(data h);
	data& Hodnota();
	prvek* &Dalsi() {return dalsi;}
};

int seznam::prvek::pocet = 0; 				// Statick� prvek 

seznam::prvek::prvek(data d) 				// Metody vno�en�ho typu
:hodnota(d){}

data& seznam::prvek::Hodnota()
{ return hodnota;
}

int main()
{
	// seznam::prvek P(0); // Chyba: typ nen� p��stupn�, je soukrom� ve t��d� seznam
}