// Soubor 17-01\SEZNAM.H
// Sablona seznamu, jehoz metody mohou vyvolavat vyjimky typu 
// chyba_seznamu

#include <exception>
#include <string>
using namespace std;

class chyba_seznamu: public exception
{
	string co;
public:
	chyba_seznamu(string s): co(s){}
	string co_je() { return co; }
};

template<class T> class seznam 
{
public:
	class prvek {
		T data;
		prvek* nasl;
		friend class seznam<T>;
	public:
		prvek(T t): data(t), nasl(0) {}
		T& hodnota() { return data; }
		prvek*& dalsi() { return nasl; }
	};
	
	prvek *hlava, *zarazka;

public:
	seznam();
	~seznam();
	void vyprazdni();
	void vlozNaKonec(T co);
	T vyjmiPrvni();
};

template<class T> seznam<T>::seznam()
: hlava(0), zarazka(0) 
{														// Konstruktor m��e vyvolat v�jimku
	hlava = new(nothrow) prvek(0);
	if(hlava) zarazka = hlava;
	else
	{
		hlava = 0;
		throw chyba_seznamu("Nepoda�ila se alokace v konstruktoru");
	}
};

template<class T> seznam<T>::~seznam()			
{														// Destruktor
	vyprazdni();
	delete zarazka;
};

template<class T> void seznam<T>::vyprazdni()
{														// Vypr�zdn� cel� seznam
	prvek* p = hlava; 
	while(hlava != zarazka)
	{
		hlava = hlava->dalsi();
		delete p;
	}
};

template<class T> void seznam<T>::vlozNaKonec(T co)
{ 														// Vlo�� prvek na konec seznamu
	zarazka -> hodnota() = co; 
	zarazka -> dalsi() = new(nothrow) prvek(0); 
	if(!(zarazka -> dalsi()))		// M��e vyvolat v�jimku
 	throw chyba_seznamu("Nepoda�ila se alokace ve vlozNaKonec()");
	zarazka = zarazka -> dalsi();
};

template<class T>	// Vyjme prvn� prvek seznamu
T seznam<T>::vyjmiPrvni()			// M��e vyvolat v�jimku
{
	if(hlava == zarazka) 
		throw chyba_seznamu("V�b�r z pr�zdn�ho seznamu");
	prvek* p = hlava;
	hlava = hlava -> dalsi();
	T t = p -> hodnota();
	delete p;
	return t;
};
