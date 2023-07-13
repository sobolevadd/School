#include <iostream>

using namespace std;

size_t Strlen(char* text)
{
	size_t vysledek = 0;
	while(text[vysledek])
	{
		vysledek++;
	}
	return vysledek;
}

char* Strcat(char* dest, const char *src)
{
	size_t start = Strlen(dest);
	size_t i = 0;
	while(src[i])
	{
		dest[start+i] = src[i++];
	}
	dest[start+i] = 0;
	return dest;
}

char* vynuluj(char* text)
{
	text[0] = 0;
	return text;
}

const int N = 100;

int main()
{
	char cil[N] = "Ahoj";
	cout << Strcat(cil, "\nlidi") << endl;
    vynuluj(cil);
	Strcat(cil, "\nlidi");
	cout << cil << endl;
}	