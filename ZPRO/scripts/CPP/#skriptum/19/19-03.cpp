// Soubor 19-03.cpp
// Tranzitivita direktivy using
// V prostoru jemn Prvni spristupnime std
// Ve funkci main() zpristjupnime Prvni, a tim i std

#include <iostream>
#include<string>
	
#include <iostream>
#include <string>
	
namespace Prvni {
	using namespace std;	// Zde zpøístupníme std
	string Text = "Prvni";
	void Tiskni(){ cout << Text << endl;}
}
	
namespace Druhy {
	std::string Text = "Druhy";
	void Tiskni(){std::cout << Text << std::endl;}
	namespace Vnoreny {
		std::string Text = "Druhy::Vnoreny";
		void Tiskni(){std::cout << Text << std::endl;}
	}
}
	
int main(){
	using namespace Prvni;	// Zpøístupníme První a tím i std
	Tiskni();
	cout << "To je ono" << endl;	// takže zde je kvalifikace 
	return 0;
}
