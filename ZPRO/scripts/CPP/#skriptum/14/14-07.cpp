// Soubor 14-07.cpp
// Automaticke ukazatele
// Ukazuje deklaraci a nektere operace
// pozor, po prirazeni bude ukazatel na
// leve strane obsahovat 0!
// (V nekterych starsich implementacich se 
// automaticke mukazatele chovaji jinak.) 

#include <memory>
#include <iostream>
using namespace std;

class canc
{
	int i;
public:
	canc(int i): i(i) { cout << "konstruktor " << i << endl; }
	~canc(){cout << "destruktor " << i << endl;}
	int hodnota() { 
		return i; 
	}
};

int main()
{
	auto_ptr<canc> p1(new canc(1)); 							// 1
	{															// 2
		auto_ptr<canc> p2(new canc(2));						// 3
		p2 = p1;												// 4
		cout << p2->hodnota() << endl;							// 5
	}															// 6
	cout << p1->hodnota() << endl;								// 7
	return 0;
}
