#include <stdlib.h>
#include <iostream>
#include <locale>
#include <string>

#include <locale.h>

using namespace std;

locale loc("Czech_Czech Republic.1250");

void NaVelka(string & text)
{
	for(int i = 0; i < text.length(); i++)
	{
		if(islower(text[i], loc))
		{
			text[i] = toupper(text[i], loc);
		}
	}
}

int main()
{
	string vstup; 
	while(getline(cin, vstup))
	{
		NaVelka(vstup);
		cout << vstup << endl;
	}
}