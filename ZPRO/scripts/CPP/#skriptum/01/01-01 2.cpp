// Soubor 01-01.cpp
// Prvni program v C++
// vytiskne "Ahoj" a skonci

#include <iostream>

int main()
{
	std::cout << "Ahoj" << std::endl;
 return 0;
}

// std::cout je vystupni datovy proud, orientovany na standardni vystup
// (obrazovka, ale lze jej presmerovat do souboru prikazem operacniho
// systemu. Potrebne informace o nem najde prekladac v hlavickovem souboru
// iostream.h)
// std::endl je manipulator, ktery zpusobi prechod na novy radek