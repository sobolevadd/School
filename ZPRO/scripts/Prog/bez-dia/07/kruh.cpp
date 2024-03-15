// Kruhova reference

#include <iostream>
#include <memory>
#include <stdlib.h>

using namespace std;

struct prvek
{
	int data;
	shared_ptr<prvek> dalsi;
	shared_ptr<prvek> predchozi;
	prvek(int data, shared_ptr<prvek> dalsi, shared_ptr<prvek> predchozi)
		:data(data), dalsi(dalsi), predchozi(predchozi)
	{}
	~prvek() { cout << data << " uvolnen\n"; }
};


int main()
{
	system("CHCP 1250 > NULL");
	{
		shared_ptr<prvek> hlava = make_shared<prvek>(1, nullptr, nullptr);
		hlava->dalsi = make_shared<prvek>(2, nullptr, nullptr);
		hlava->dalsi->predchozi = hlava;
	}
}