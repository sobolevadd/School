// Kruhová reference

#include <iostream>
#include <memory>
#include <stdlib.h>

using namespace std;

struct prvek
{
	int data;
	shared_ptr<prvek> další;
	shared_ptr<prvek> pøedchozí;
	prvek(int data, shared_ptr<prvek> další, shared_ptr<prvek> pøedchozí)
		:data(data), další(další), pøedchozí(pøedchozí)
	{}
	~prvek() { cout << data << " uvolnìn\n"; }
};


int main()
{
	system("CHCP 1250 > NULL");
	{
		shared_ptr<prvek> hlava = make_shared<prvek>(1, nullptr, nullptr);
		hlava->další = make_shared<prvek>(2, nullptr, nullptr);
		hlava->další->pøedchozí = hlava;
	}
}