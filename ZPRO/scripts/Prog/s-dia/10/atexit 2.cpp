// P��klad pou�it� funkce atexit
#include <cstdlib>
#include <iostream>
#include <locale>

using namespace std;

void F1()
{
	wcout << L"Hl�s� se ukon�ovac� funkce F1" << endl;
}

void F2() {
	wcout << L"Hl�s� se ukon�ovac� funkce F2" << endl;
}

int main()
{
	wcout.imbue(locale("Czech_Czech Republic.852"));
	wcout << L"Hl�s� se hlavn� program" << endl;
	atexit(F1);                         // Registrace funkc� F1() a F2()
	atexit(F2);
	return 0;
}