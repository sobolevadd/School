// Soubor 14-05.cpp
// Ukazuje pouziti konstruktoru  a destruktoru
// Na volani funkce Ha ukazuje take, ze prekladac 
// muze vyuzit konstruktor s jednim parametrem ke konverzi

#include <iostream>
using namespace std;

class pole {
	int *p, delka;
public:
	pole();							// Konstruktor c. 1
	pole(int, int=10); 				// Konstruktor c. 2
	pole(pole&); 					// Kopirovaci konstruktor
	~pole();						// Destruktor
	// ...a dalši metody
};

pole::pole(int n, int d)
: p(0), delka(n)
{
	p = new int [delka];
	for(int i = 0; i < n; i++) p[i] = d;
}

pole::pole()
: p(0), delka(0){}

pole::~pole()
{ 
	delete[] p;
}

pole::pole(pole& t)					// Kopirovaci konstruktor
: p(0), delka(t.delka)
{
	p = new int [delka];			// Alokuje nové pole p
									// a prekopiruje do nìj obsah t.p
	for(int i = 0; i < delka; i++) p[i] = t.p[i];
}

void Ha(pole p)
{}					// Na tom, co dìlá, nezálezi

int main()
{
	try{
		pole p(10, 999);// Pouzije se konstruktor c. 2
		pole q(45);		// Pouzije se konstruktor c. 2
		pole r; 		// Pouzije se konstruktor c. 1
		pole s(); 		// Prototyp funkce, nikoli deklarace instance!!
		pole t(p);		// Pouzije se kopiroavci konstruktor

		Ha(1);			// To je zjevný preklep, ale prelozi se to
	}					// zavola se Ha(pole(1))
	catch(std::bad_alloc b)
	{
		cerr << "nepodarilo se vytvorit instanci pole" << endl;
	}
}