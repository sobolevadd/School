// Soubor 14-09.cpp
// Bez virtualnich metod to nefunguje
// Hierarchie grafickych objektu, misto kresleni vypis
// GO (jako Graficky objekt) je spolecny predek
// trid bod a usecka
// Vsechny maji metodu Nakresli()
// Pole ukazatelu na GO onsahuje ukazatel na Bod a Usecku (to je OK
// -- potomek zde zastupuje predka)
// Pri pokusu o kresleni se vola metoda GO::Nakresli(),
// nebot neni virtualni

#include <iostream>
using namespace std;

class GO {
	int barva; 									// Barva grafického objektu
public:
	GO(int _barva): barva(_barva){}
	~GO(){}
								// Nakresli obecný objekt
	void Nakresli(){cout << "kreslim GO, barva " << barva << endl; }
	int Barva(){ return barva;}
};

class bod: public GO {
	double x, y; 								// Souøadnice bodu
public:
	bod(int _barva, double _x, double _y)
	: GO(_barva), x(_x), y(_y){}
	// Nakresli bod
	void Nakresli(){ 
		cout << "kreslim bod (" << x <<", " << y << 
			    "), barva " << Barva() << endl; 
	}							
};

class usecka: public GO {
	bod poc, kon; 								// Poèáteèní a koncový bod
public:
	usecka(int _barva, double _x1, double _y1, double _x2, double _y2)
	 : GO(_barva), poc(_barva, _x1, _y1), kon(_barva, _x2, _y2){}
	// Nakresli úseèku
	 void Nakresli()
	 {
		 cout << "kreslim usecku:" << endl; 
		 poc.Nakresli();
		 kon.Nakresli();
	 }
};

int main()
{
	GO *objekty[10];
	objekty[0] = new bod(1, 2, 30);
	objekty[1] = new usecka(9, 1, 2, 3, 4);
	objekty[0] -> Nakresli();				// Nakresli GO
	objekty[1] -> Nakresli();				// nakresli GO
	
	for (int i = 0; i < 2; i++) delete objekty[i];
	return 0;
}