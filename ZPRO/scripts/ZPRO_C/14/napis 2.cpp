#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;


class napis
{
    char text[100];
public:
    napis(char *zadani)
	{
		nastav(zadani);
	}
    void nastav(char *zadani)
	{
		strcpy(text, zadani);
	}
    void vypis()
	{
		cout << text << endl;
	}
};


int main()
{
	napis text("nazdar");
	text.vypis();
}