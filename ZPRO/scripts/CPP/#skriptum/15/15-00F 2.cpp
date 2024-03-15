// Soubor 15-00F.cpp
// Predefinovani new a delete
// Tyto funkce nahradi globalni new a delete po
// celou dobu behu programu
// NENI PRILIS VHODNE, PROTOZE SE V CHOVANI
// ODLISUJE OD STANDARDNIHO NEW (nespolupracuje 
// se set_new_handler(), nevyvola vyjimku pri neuspesne alokaci)

#include <cstdlib>
#include <cstring>
using namespace std;

void* operator new(size_t s)
{
	void *p;
	p = malloc(s);
	if(p) memset(p,0,s);					// Vyplò s bytù hodnotou 0
	return p;
}
void operator delete(void *p)
{ 
	free(p);
}

int main()
{
	int *u = new int;
	delete u;
	return 0;
}