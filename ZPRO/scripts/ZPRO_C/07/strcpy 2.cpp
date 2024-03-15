#include <iostream>
#include <stdlib.h>

using namespace std;


char * Strcpy(char* dest, char* src)
{
	int i;
	for(i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return dest;
}



int main()
{
	system("CHCP 1250 > NUL");
	char txt[10];
	
	cout << Strcpy(txt, "Ahoj") << endl;
}