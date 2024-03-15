// Soubor 17-03.cpp
// Pouziti virtualnich metod ve tride pro vyjimky

#include <iostream>
using namespace std;

// Hierarchie trid pro prenos informaci o vyjimce
class vyjimka1 {
public:
	virtual void co_je() { cerr << "Výjimka typu 1" << endl; }
};

class vyjimka2: public vyjimka1 {
public:
	virtual void co_je() { cerr << "Výjimka typu 2" << endl; }
};

class vyjimka3: public vyjimka2 {
public:
	virtual void co_je() { cerr << "Výjimka typu 3" << endl; }
};

	
int main()
{
	for(int i = 1; i < 4; i++)
	try
	{
		switch(i)
		{
		case 1: throw vyjimka1();	// Volání konstruktorù
		case 2: throw vyjimka2();
		case 3: throw vyjimka3();
		}
	}
	catch(vyjimka1 & v)
	{ v.co_je();
	}
	return 0;
}
