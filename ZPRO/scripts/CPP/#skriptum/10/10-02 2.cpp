// Soubor 10-02.CPP
// Pouziti unareniho operátoru ::
#include <iostream>
using namespace std;
int i = 11; 							// Globální promìnná
class X 
{
private:
	int i;
public:
 	X(int y):i(y){};
 	int hodnota();
};
int X::hodnota()
{
	return i; 							// Odkaz na složku instance
}
int main()
{ 
	X x(45);
 	int i = 0;
	// Vypíše nejprve lokální a pak globální i
 	cout << i << " " << ::i;
 	cout << x.hodnota(); 		// Vypíše data instance
 	return 0;
}
