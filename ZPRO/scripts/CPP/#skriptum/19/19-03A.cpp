// Soubor 19-04A.cpp
// Vyhledávání operátorù 
// Operator je deklarovan v kontextu operandu
// (Tj. ve stejném prostoru jmen jako jeho operand)
// a proto ho prekladac najde 


#include <iostream>
	
namespace Alfa {
	class X{										// Operand i operátor ve stejném
		int a;										// kontextu
	public:
		X():a(0){}
	friend X& operator++(X& x);
	};

	X& operator++(X& x){x.a++; return x;}
}
	
namespace Beta {
	void f(Alfa::X &aa){
		++aa; 	// Použijeme operátor definovaný v prostoru Alfa
	}			// tj. v kontextu operandu
}

void main()
{
	Alfa::X x;
	Beta::f(x);
}