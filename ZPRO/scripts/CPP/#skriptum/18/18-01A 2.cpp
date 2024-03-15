// Soubor 18-01A.cpp
// Priklad pouziti operatoru static_cast pro 
// praci s objektovymi typy

// Odstranime-li deklaraci friend ve tride
// Gama, nepujde funkci g() prelozit, nebot
// predek nebude pristupny

class Alfa {
	int i;
public:
	Alfa(int i): i(i+1) {}
	operator int() { return i; }
};

class Beta {
	int j;
public:
	Beta(int j): j(j+1) {}
};

class Gama: public Alfa, private Beta {
public:
	Gama(int i): Alfa(10*i), Beta(i) {}
	friend void g(Gama*);
};

void f(Alfa){};
void f(Beta){};
void f(Gama){};
void f(Gama*){};

void g(Gama* x) 		// Funkce sp��telen� s Gama
{
	f(static_cast<Beta&>(*x));	// OK, p�edek je zde dostupn�
}

Alfa A(5), *uA = &A;			// Instance a ukazatele
Gama G(4);
Alfa * uAA = &G;
Alfa &rA = G;				// Reference na zd�d�n� podobjekt


int main()
{
	int y = static_cast<int>(A); 	// Vol� A::operator int()
	Gama G = static_cast<Gama>(11);	// Vol� konstruktor Gama::Gama(int)
	f(static_cast<Gama*>(uAA));	// 1
	f(static_cast<Gama*>(uA)); 	// 2
	f(static_cast<Gama&>(rA)); 	// 3
	f(static_cast<Gama&>(A)); 	// 4
	//f(static_cast<Beta&>(G));	// 5 � Nelze, nedostupn� p�edek
	g(&G); 				// 6

	g(&G);
	return 0;
}
