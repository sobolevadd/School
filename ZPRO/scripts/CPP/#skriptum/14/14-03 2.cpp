// Soubor 14-03.cpp
// Ukazuje definici statické datové složky

typedef int data;
class prvek
{
	data hodnota;
	prvek * dalsi;	
	static int pocet; 					// Nyní je soukromý
public:
	prvek(data d): hodnota(d), dalsi(0) { pocet++; }
	~prvek(){ pocet--; }
	static int Pocet() { return pocet; }
	// ...a další metody
};

int prvek::pocet = 0;

int main()
{
	prvek P(0);
}