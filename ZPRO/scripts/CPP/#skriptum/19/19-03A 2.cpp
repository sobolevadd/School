// Soubor 19-04A.cpp
// Vyhled�v�n� oper�tor� 
// Operator je deklarovan v kontextu operandu
// (Tj. ve stejn�m prostoru jmen jako jeho operand)
// a proto ho prekladac najde 


#include <iostream>
	
namespace Alfa {
	class X{										// Operand i oper�tor ve stejn�m
		int a;										// kontextu
	public:
		X():a(0){}
	friend X& operator++(X& x);
	};

	X& operator++(X& x){x.a++; return x;}
}
	
namespace Beta {
	void f(Alfa::X &aa){
		++aa; 	// Pou�ijeme oper�tor definovan� v prostoru Alfa
	}			// tj. v kontextu operandu
}

void main()
{
	Alfa::X x;
	Beta::f(x);
}