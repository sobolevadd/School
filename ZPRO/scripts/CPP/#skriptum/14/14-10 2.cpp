// Soubor 14-10.cpp
// S virtualnimio metodami to funguje
// Totez jako predtim, ale metoda Nakresli()
// je nyni virtualni (a taky destruktor)
// Vsechny maji metodu Nakresli()
//
// Staci deklarovat jako virtualni metodu predka
// v potomkovi se slovo virtual nemusi opakovat

#include <iostream>
using namespace std;

class GO {
	int barva; 									// Barva grafického objektu
public:
	GO(int _barva): barva(_barva){}
	virtual ~GO(){}
								// Nakresli obecný objekt
	virtual void Nakresli(){cout << "kreslim GO, barva " << barva << endl; }
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

	// Nyni to opravdu nakresli bod a usecku
	for (int i = 0; i < 2; i++)objekty[i] -> Nakresli();				
	
	for (int i = 0; i < 2; i++) delete objekty[i];
	return 0;
}