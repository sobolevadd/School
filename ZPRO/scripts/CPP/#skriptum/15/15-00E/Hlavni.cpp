// Soubor 15-00E\hlavni.cpp
// Priklad na pretezovani operatoru ->
// trida automatickeho ukazatele na matice
// zapouzdruje ukazatel na dynamicky alokovanou 
// matici a pri svem zaniku tuti instanci znici

#include "matice.h"

class auto_ptr_mat
{ 
	matice* pm;
	bool vlastni;
public:
	auto_ptr_mat(matice*);
	auto_ptr_mat(auto_ptr_mat&);
	~auto_ptr_mat() { if(vlastni) delete pm; }
	matice *operator->() { return pm; }
	auto_ptr_mat& operator=(auto_ptr_mat&);
};
auto_ptr_mat::auto_ptr_mat(matice* um)
: vlastni(true), pm(um) {}
	auto_ptr_mat& auto_ptr_mat::operator=(auto_ptr_mat& par)
{ 
	if(vlastni) delete pm;
	vlastni = par.vlastni;
	par.vlastni = false;
	pm = par.pm;
	return *this;
}

int main()
{
	auto_ptr_mat a1(new matice(5));
	a1 -> Vypis();

	return 0;
}