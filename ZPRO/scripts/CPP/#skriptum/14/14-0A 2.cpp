// Soubor 14-0A.cpp
// Priklad na ukazatele do tridy

struct X {			// Objektovy typ
 	int a;
 	double b;
 	int c;
 	double Sou();
};

double X::Sou(){ return a*b*c;}
X x, y;
X* uX = &x;

int main()
{
	int X::*Xi = &X::a;			// deklarace a inicializace ukazatele na slozku
	double (X::*XF)();			// deklarace ukazatele na metodu
	XF = &X::Sou;				// Ziskani adresy metody

	x.*Xi = 11;				// Pouziti ukazatelu na slozky
	y.*Xi = 12;
	double d = (uX ->*XF)();	// Volani metody prostrednictvim ukazatele
	return 0;
}