#include <sstream>
#include "Typ.h"

using namespace std;

bool mensi(void * p1, void * p2)
{
	return *(T*)p1 < *(T*)p2;
}

bool mensiDleCisel(void* p1, void* p2)
{
	istringstream P1(*(string *)p1);
	istringstream P2(*(string *)p2);
	int n1, n2;
	P1 >> n1;
	P2 >> n2;
	return n1 < n2;
}