// Soubor 17-03B.cpp
// Priklad standardni vyjimky

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
int main()
{
	string s;
	try{
		s.replace(100,1,1,'X');	// Prazdny retezec -- nema sty prvek
	}				// Proto jeho pouziti vyvola vyjimku
	catch(const exception& e){
		cout << "Výjimka: " << e.what() << endl;
	}
	return 0;
}
