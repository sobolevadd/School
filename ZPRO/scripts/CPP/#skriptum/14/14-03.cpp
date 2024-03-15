// Soubor 14-03.cpp
// Ukazuje definici statick� datov� slo�ky

typedef int data;
class prvek
{
	data hodnota;
	prvek * dalsi;	
	static int pocet; 					// Nyn� je soukrom�
public:
	prvek(data d): hodnota(d), dalsi(0) { pocet++; }
	~prvek(){ pocet--; }
	static int Pocet() { return pocet; }
	// ...a dal�� metody
};

int prvek::pocet = 0;

int main()
{
	prvek P(0);
}