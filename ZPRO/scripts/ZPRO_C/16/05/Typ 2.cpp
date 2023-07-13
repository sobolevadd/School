#include <sstream>
#include <limits.h>
#include "Typ.h"

using namespace std;

bool mensi(void * p1, void * p2)
{
	return *(T*)p1 < *(T*)p2;
}

bool mensiDleCisel(void* p1, void* p2)
{
	istringstream P1(*(T*)p1);
	istringstream P2(*(T*)p2);
	int n1 = INT_MAX, n2 = INT_MAX;
	P1 >> n1;
	P2 >> n2;
	return n1 < n2;
}