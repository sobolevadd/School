// Soubor 12-0A.CPP
// Rozlisovani pretizenych funkci

void f(){}		// c. 1
void f(int){}		// c. 2
void f(double){}	// c. 3
void f(int, double){} 	// c. 4

int main()
{
	f();			// Volá se funkce c. 1
	f(3, 3.14159);		// Volá se funkce c. 4
	f('a'); 		// Volá se f(int)  (c. 2)
	f(0L, 3);		// Volá se funkce c. 4
	//f(0L); 		// Chyba, ale nektere prekladace to prelozi a zavolaji 2
}