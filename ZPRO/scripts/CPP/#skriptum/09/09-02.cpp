// Soubor 09-02.CPP
// P��klad pou�it� unie
//ke zji�t�n� zp�sobu ukl�d�n� cel�ch ��sel v pam�ti

#include <iostream>
using namespace std;
union 
{
	long int i;
	unsigned char c[4];
} u;
int main()
{
 	u.i = 0x12345678L;
 	cout << hex << endl; 				// V�pis v �estn�ctkov� soustav�
 	for (int i = 0; i < 4; i++)
 		cout << (unsigned)u.c[i] << ' ';
 	return 0;
}
