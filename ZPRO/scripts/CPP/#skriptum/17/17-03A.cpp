// Soubor 17-03.cpp
// Pouziti virtualnich metod ve tride pro vyjimky
// Stejne jako 17-03.cpp, pouze pro kazdy typ vyjimky
// jiny handler
// POZOOR -- PORADI HANDLERU MUSI BYT TAKOVE, JAKO JE
// ZDE UVEDENO. pRI OPACNEM BY PRVNI ZACHYTIL
// VSECHNY VYJIMKY


#include <iostream>
using namespace std;
// Hierarchie t��d pro p�enos informac� o v�jimce
class vyjimka1 {
public:
	virtual void co_je() { cerr << "V�jimka typu 1" << endl; }
};
class vyjimka2: public vyjimka1 {
public:
	virtual void co_je() { cerr << "V�jimka typu 2" << endl; }
};
	class vyjimka3: public vyjimka2 {
public:
	virtual void co_je() { cerr << "V�jimka typu 3" << endl; }
};
	int main()
{
	for(int i = 1; i < 4; i++)
	try
	{
		switch(i)
		{
		case 1: throw vyjimka1();	// Vol�n� konstruktor�
		case 2: throw vyjimka2();
		case 3: throw vyjimka3();
		}
	}
	catch(vyjimka1 & v)
	{ v.co_je();
	}
	return 0;
}
