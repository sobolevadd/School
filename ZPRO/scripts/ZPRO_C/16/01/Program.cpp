#include <iostream>
#include "Seznam.h"

using namespace std;

int main()
{
	Seznam s;
	s.setrid();
	s.vlozNakonec(6);
	s.vlozNakonec(4);
	s.vlozNakonec(1);
	s.vlozNakonec(9);
	s.vypis(cout);
	s.setrid();
	s.vypis(cout);
}