#ifndef __NAPIS_H__
#define __NAPIS_H__

#include <string.h>
#include <iostream>
using namespace std;

class napis
{
    char text[100];
	static int pocitadlo;
public:
    napis(char *zadani);
	
    void nastav(char *zadani)
	{
		strcpy(text, zadani);
	}
    void vypis()
	{
		cout << text << endl;
	}
	~napis();
	int pocetNapisu();
};

#endif