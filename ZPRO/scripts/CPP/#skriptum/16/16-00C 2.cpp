// Soubor 16-00C.cpp
// Sablony vnorenych funkci

#include <iostream>
using namespace std;

template<class T> T Max(T a, T b)
{ 
	return a > b ? a : b;
}

// Volna funkce -- ma prednost pred sablonou
char *Max(char *a, char *b)
{ 
	// ...nejake porovnaní obsahu retezcu
	return "volna funkce";
}


template<class T> T atou(char *c)
{
	T x = 0;
	while(*c)
		x = x*10 + *c++ - '0';
	return x;
}

void f(){
	cout << Max(1, 2); 				// Vytvori se Max<int>
	cout << Max('a', 'b'); 				// Vytvori se Max<char>
	cout << Max(3.4, 2.1); 				// Vytvori se Max<double>
	//cout << Max(1, 'b'); 				// Chyba - nelze urèit typ parametrù
	//	cout << Max(2.2, 1); 			// Chyba - nelze urèit typ parametrù
	cout << Max<int>(1, 'b'); 			// Zavola se Max<int>
	cout << Max<double>(2.2, 1);			// Zavola se Max<double>
	int i = atou<short>("12345");
}

int main()
{
	f();
	char c[] = "Ahoj", d[] = "Èau";
	cout << Max(c, d); 				// zavolá se char* Max(char*, char*)
	cout << Max((void*)c, (void*)d); 			// zavola se Max<void*>
	
	return 0;
}