// Náš druhý program 
// OD PØEDCHOZÍ VERZE SE LIŠÍ JEN POUŽITÍM
// DIREKTIVY USING A VYPUŠTÌNÍM "KVALIFIKACE"
// JMEN PROUDÙ A MANIPULÁTORU

#include <iostream>

using namespace std;

int zadano;

int main()
{
   cout << "Zadej celé èíslo: " << endl;
   cin >> zadano;
   cout << "Dvojnásobek je " <<  2 * zadano;
}