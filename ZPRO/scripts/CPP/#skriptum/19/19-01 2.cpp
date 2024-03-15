// Soubor 19-01.cpp
// Prostory jmen
// Priklad deklarace prostoru jmen
// Deklarace f() v prostoru jemn, definice mimo

#include <iostream>
	
// Globální promìnné mimo prostory jmen
int n = 11, N = 33;
	
namespace Pokusny_Prostor_Jmen {
	int n = 22;
	void f();
}
	
void Pokusny_Prostor_Jmen::f(){
	std::cout << "ve funkci f: n*N = " << n*N << std::endl;
}
	
int main()
{
	int n = 555;
	std::cout 	<< "lokalni n = " << n << std::endl;
	std::cout 	<< "Pokusny_Prostor_Jmen::n = "
					<< Pokusny_Prostor_Jmen::n << std::endl;
	std::cout 	<< "globalni n = " << ::n << std::endl;
	Pokusny_Prostor_Jmen::f();
	return 0;
}
