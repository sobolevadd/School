#include <iostream>
#include <stdlib.h>

using namespace std;


size_t Strlen(const char* text)
{
   size_t vysledek = 0;
   while(text[vysledek]) 
   {                         
      vysledek++;
   }
   return vysledek;   
}

int main()
{
	system("CHCP 1250 > NUL");
	const char text[] = "Nazdar";
	char* txt = "Ahoj";
	cout << Strlen(text) << endl;
	cout << Strlen(txt) << endl;
}