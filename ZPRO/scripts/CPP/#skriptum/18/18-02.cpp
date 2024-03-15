// Soubor 18-02.cpp
Priklad pouziti operatoru reinterpret_cast

#include <iostream>
using namespace std;

struct Delta
{	
	int a;
	double b;
};

struct Epsilon					// Má stejnou strukturu jako Delta
{	
	int c;
double d;
};

void Vypis(Delta sd)
{	
	cout << sd.a << endl << sd.b << endl;
}

Epsilon eps = {5, 6.9};

int main()
{	
	Vypis(reinterpret_cast<Delta&>(eps));
	return 0;
}
