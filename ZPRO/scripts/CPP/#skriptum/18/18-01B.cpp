// Soubor 18-01B.cpp
// Priklad pouziti operatoru dynamic_cast

#include <iostream>
using namespace std;

class Alfa {
	int i;
public:
	Alfa(int i): i(i+1) {}
	virtual void hlaseni() { cout << "Alfa" << endl; }
};
class Beta {
	int j;
public:
	Beta(int j): j(j+1) {}
	virtual void hlaseni() { cout << "Beta" << endl; }
	void SpecialniMetoda(){}
};

class Gama: public Alfa, public Beta {
public:											// Spoleèný potomek Alfa a Beta
	Gama(int i): Alfa(10*i), Beta(i) {}
	virtual void hlaseni() { cout << "Gama" << endl; }
	void NejakaMetoda(){}
};

Alfa A(5), *uA = &A; 	// Instance a ukazatele na nì
Beta B(6), *uB = &B;
Gama G(8), *uG = &G;

void F(Alfa& a)
{
	try
	{
		dynamic_cast<Beta&>(a).SpecialniMetoda();
	}
	catch(bad_cast)
	{
		cout << "Sorry, nejde to" << endl;
	}
}

int main()
{
	Gama *g = dynamic_cast<Gama*>(uB);	// Pøetypování
	if(g) g->NejakaMetoda();		// Test, zda se podaøilo
	F(G);
	F(A);

	uB = &G;
	cout << static_cast<void*>(uB) << endl;	// Vypise ruzne vysledky
	cout << dynamic_cast<void*>(uB) << endl;
	return 0;
}