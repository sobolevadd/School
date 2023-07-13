#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


int indexZnaku(char * txt, char co)
{
	int index = -1;
	for(int k = 0; txt[k]; k++)
	{
		if(txt[k] == co)
		{
			index = k;
			break;
		}
	}
	return index;
}

int indexZnaku1(char * txt, char co)
{
	int index = -1;
	for(int k = 0; txt[k]; k++)
	{
		if(txt[k] == co)
		{
			index = k;
			goto Navrat;
		}
	}
	Navrat:
	return index;
}


int main()
{
	system("CHCP 1250 > NUL");
	char txt[10];
	strcpy(txt, "Ahoj");
	cout << "Index znaku \'o\' v øetìzci \"" << txt << " je " << indexZnaku1(txt, 'o') << endl;
	cout << "Index znaku \'x\' v øetìzci \"" << txt << " je " << indexZnaku1(txt, 'x') << endl;
}