#include <typeinfo>
#include <iostream>
using namespace std;
// Odstran�me-li tuto direktivu, zm�n�me 
// polymorfn� t��dy na nepolymorfn�
#define VIRTUAL

// Soubor 18-01.cpp
// Ukazuje pouziti operatoru typeid
// Funguje spravne pouze pro polymorfni tridy, tedy
// je-li makro VIRTUAL #definovano

// pozor - v nekterych prekladacich je nutno RTTI povolit
// Napr. v MS VC++ .NET nebo v prekladacich Intel
// Project|Properties ... C/C++ | Language | Enable Run-Time Type Info

class Prvni {
public:

// Toto makro urcuje, zda budou tridy Prvni a Druha polymorfni
#ifdef VIRTUAL
 	virtual
#endif
 	void f() {cout <<"Prvni"<<endl;};
};
class Druha:public Prvni {
public:
 	void f(){ cout << "Druha" << endl;};
};
int main()
{
	Prvni p;
	Druha d;
	Prvni *p1= &p, *p2 = &d;
	try{
		cout 	<< "p2 ukazuje na objekt typu "<< typeid(*p2).name() 
					<< endl
					<< 	(typeid(*p1).before(typeid(*p2)) ?
							"Prvn� v abeced� je to, na� ukazuje p1" :
							"Prvn� v abeced� je to, na� ukazuje p2" ) << endl;
	}
	catch(bad_typeid &e){
		cout << "Dereferencuje� 0" << endl << e.what();
		return 1;
	}
	return 0;
}
