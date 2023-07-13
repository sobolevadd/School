// Soubor 06-02.CPP
// deklarace jako prikaz
// Obe vetve prikazu if se chovaji jako blok

#include <iostream>
using namespace std;

class Test
{ 											// Konstruktor a destruktor vypisuj�
	int I;								    // koment��e
public:
	Test(int i);
	~Test();
};

Test::Test(int i)
{
	I = i;
	cout << "Konstruktor " << I << endl;
}

Test::~Test()
{
	cout << "Destruktor " << I << endl;
}

int main()
{
	int j;
	cin >> j; 							// Ob� v�tve p��kazu if
	if(j > 0) Test t(j); 		// se chovaj� jako blok
	else Test t(-j);
	cout << "Konec" << endl;
	return 0;
}
