// Soubor PARMAIN.CPP
#include <iostream>
#include <locale>

using namespace std;

int main(int argc, char *argv[], char *env[])
{
	wcout.imbue(locale("Czech_Czech Republic.852"));
	wcout << L"Program byl spu�t�n s " << argc
		<< L" parametry:" << endl;
	for (int i = 0; i < argc; i++)
	{
		wcout << argv[i] << endl;
	}
	wcout << endl << L"Prost�ed� opera�n�ho syst�mu:" << endl;
	int i = 0;

	while (env[i])
	{
		wcout << env[i++] << endl;
	}
}
