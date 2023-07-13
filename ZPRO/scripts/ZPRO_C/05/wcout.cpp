// Nastavení lokálního prostøedí pro výstup širokých znakù
// ve Visual C++
#include <iostream>
#include <locale>

using namespace std;


int main()
{
	wchar_t info[] = L"Stojí to 5 \u20AC;";
	wcout << info << endl;
	wcout.clear();
	wcout << endl;
    locale loc("Czech_Czech Republic");
	wcout.imbue(loc);
	wcout << info << endl;
}	