// Soubor 10-02.CPP
// Pouziti unareniho oper�toru ::
#include <iostream>
using namespace std;
int i = 11; 							// Glob�ln� prom�nn�
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
	return i; 							// Odkaz na slo�ku instance
}
int main()
{ 
	X x(45);
 	int i = 0;
	// Vyp�e nejprve lok�ln� a pak glob�ln� i
 	cout << i << " " << ::i;
 	cout << x.hodnota(); 		// Vyp�e data instance
 	return 0;
}
