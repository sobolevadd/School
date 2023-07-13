// Soubor 13-0C.CPP
// Priklad podmineneho prekladu

#include <iostream>
using namespace std;

#define FF 1
void main()
{
	#if FF==0
		#define PQ 29
	#elif FF==1
		#define PQ 54
	#else
		#define PQ -23
	#endif
	cout << "PQ=" << PQ << endl; 
}
