// Soubor 21-00A.cpp
// Pouziti iteratoru
// Operator << pro vypis seznamu celych cisel
// pouziva k prochazeni seznamu iteratoru
// Program vytvori seznam 10 celych cisel a vypise ho

#include <list>
#include <iostream>
using namespace std;

ostream& operator<<(ostream& Str, list<int>& Seznam)
{
	if(!Seznam.empty())
	{
		for(	list<int>::iterator i = Seznam.begin();
				i != Seznam.end();
				i++)
			Str << *i << ' ';
	}
	return Str;
}

int main()
{
	list<int> CC;
	for(int i = 0; i < 10; i++) CC.push_back(i);
	cout << CC << endl;
}