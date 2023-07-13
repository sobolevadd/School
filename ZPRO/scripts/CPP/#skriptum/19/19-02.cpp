// Soubor 19-02.cpp
// Vnoreme prostory jmen

#include <iostream>
#include<string>
	
namespace Prvni {
	std::string Text = "Prvni";
	void Tiskni(){std::cout << Text << std::endl;}
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
	Prvni::Tiskni();
	Druhy::Tiskni();
	Druhy::Vnoreny::Tiskni();
	return 0;
}
