#include <iostream>

using namespace std;

union Pokus {
	char znak;
	short cele;
	double realne;
};


int main()
{
	system("CHCP 1250 > NUL");
	cout << "Velikost unie Pokus: " << sizeof(Pokus) << " B" << endl;
	Pokus pokus = {'A'};
	cout << pokus.znak << " " << pokus.cele << " " << pokus.realne << endl;
	pokus.cele = 0x4142;
	cout << pokus.znak << " " << pokus.cele << " " << pokus.realne << endl;
	pokus.realne = 1.11111e1;
	cout << pokus.znak << " " << pokus.cele << " " << pokus.realne << endl;
}