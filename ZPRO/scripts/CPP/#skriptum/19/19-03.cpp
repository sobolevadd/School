// Soubor 19-03.cpp
// Tranzitivita direktivy using
// V prostoru jemn Prvni spristupnime std
// Ve funkci main() zpristjupnime Prvni, a tim i std

#include <iostream>
#include<string>
	
#include <iostream>
#include <string>
	
namespace Prvni {
	using namespace std;	// Zde zp��stupn�me std
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
	using namespace Prvni;	// Zp��stupn�me Prvn� a t�m i std
	Tiskni();
	cout << "To je ono" << endl;	// tak�e zde je kvalifikace 
	return 0;
}
