// Soubor 14-05A.cpp
// Podobne jako 14-05.cpp, az na to, ze
// konstruktor 2 je nyni d�klarovan jako 
// explicitni,takze prekladac odhali chybu
// pri volani funkce Ha()

#include <iostream>
using namespace std;

class pole {
	int *p, delka;
public:
	pole();							// Konstruktor �. 1
	explicit pole(int, int=10); 				// Konstruktor �. 2
	pole(pole&); 					// Kop�rovac� konstruktor
	~pole();						// Destruktor
	// ...a dal�� metody
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

pole::pole(pole& t)					// Kop�rovac� konstruktor
: p(0), delka(t.delka)
{
	p = new int [delka];			// Alokuje nov� pole p
									// a p�ekop�ruje do n�j obsah t.p
	for(int i = 0; i < delka; i++) p[i] = t.p[i];
}

void Ha(pole p)
{}					// Na tom, co d�l�, nez�le��

int main()
{
	try{
		pole p(10, 999);// Pou�ije se konstruktor �. 2
		pole q(45);		// Pou�ije se konstruktor �. 2
		pole r; 		// Pou�ije se konstruktor �. 1
		pole s(); 		// Prototyp funkce, nikoli deklarace instance!!
		pole t(p);		// Pou�ije se kop�roavc� konstruktor

		Ha(1);			// Nyni prekladac ohlasi chybu,
	}					// nebot konstruktor je explicitni
	catch(std::bad_alloc b)
	{
		cerr << "nepodarilo se vytvorit instanci pole" << endl;
	}
}