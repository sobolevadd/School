#include <iostream>

using namespace std;

enum druhVozidla {osobniVuz, nakladniVuz, autobus};

struct Vozidlo1 // Nešikovná definice
{
	druhVozidla druh;
	unsigned short mist, obsazeno;
	bool linkovy;
	double nosnost, nalozeno;
};

struct Osobni
{
	unsigned short mist, obsazeno;
};

struct Autobus
{
	unsigned short mist, obsazeno;
	bool linkovy;
};

struct Nakladni
{
	double nosnost, nalozeno;
};

union Popis
{
	Osobni osobni;
	Autobus bus;
	Nakladni nakladni;
};

struct Vozidlo2
{
	druhVozidla druh;
	Popis popis;
};

struct Vozidlo3
{
	druhVozidla druh;
	union {
		Osobni osobni;
		Autobus bus;
		Nakladni nakladni;
	};
};

int main()
{
	Vozidlo2 v = {osobniVuz, {{5, 4}}};
	v.druh = autobus;
	v.popis.bus.linkovy = true;
	v.popis.bus.mist = 40;
	v.popis.bus.obsazeno = 22;

	Vozidlo3 w = {osobniVuz, {5, 5} };
	w.druh = nakladniVuz;
	w.nakladni.nalozeno = 6.7;
	w.nakladni.nosnost = 8;
}