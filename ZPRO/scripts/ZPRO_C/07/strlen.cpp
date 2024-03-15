#include <iostream>
#include <stdlib.h>

using namespace std;

/*
size_t Strlen(char * text)
{
	int i = 0;
	while(text[i++])
	{}
	return i-1;
}*/

size_t Strlen(char * text)
{
	int i = 0;
	while(text[i++])
	;
	return i-1;
}

int main()
{
	system("CHCP 1250 > NUL");
	int i = Strlen("Ahoj");
	cout << "Délka øetìzce je " << i << endl;
}