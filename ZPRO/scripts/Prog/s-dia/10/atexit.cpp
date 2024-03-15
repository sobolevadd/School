// Pøíklad použití funkce atexit
#include <cstdlib>
#include <iostream>
#include <locale>

using namespace std;

void F1()
{
	wcout << L"Hlásí se ukonèovací funkce F1" << endl;
}

void F2() {
	wcout << L"Hlásí se ukonèovací funkce F2" << endl;
}

int main()
{
	wcout.imbue(locale("Czech_Czech Republic.852"));
	wcout << L"Hlásí se hlavní program" << endl;
	atexit(F1);                         // Registrace funkcí F1() a F2()
	atexit(F2);
	return 0;
}