// Soubor 19-03B.cpp
// Vyhledavani operatoru v kontextu pouziti

#include <iostream>
	
namespace Alfa {
	struct X;											// Operand v Alfa
}
	namespace Beta {
void f(Alfa::X &aa);
Alfa::X& operator++(Alfa::X&);		// Operátor v Beta
}
struct Alfa::X{										// Definice operandu
	int a;
public:
	X():a(0){}
};
	Alfa::X& Beta::operator++(Alfa::X& a){
	a.a++;													// Definice operátoru
	return a;
}

void Beta::f(Alfa::X &aa){
	++aa;														// Použití v Beta
}


void main()
{
	Alfa::X x;
	Beta::f(x);
}