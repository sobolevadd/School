// Kruhov� reference

#include <iostream>
#include <memory>
#include <stdlib.h>

using namespace std;

struct prvek
{
	int data;
	shared_ptr<prvek> dal��;
	shared_ptr<prvek> p�edchoz�;
	prvek(int data, shared_ptr<prvek> dal��, shared_ptr<prvek> p�edchoz�)
		:data(data), dal��(dal��), p�edchoz�(p�edchoz�)
	{}
	~prvek() { cout << data << " uvoln�n\n"; }
};


int main()
{
	system("CHCP 1250 > NULL");
	{
		shared_ptr<prvek> hlava = make_shared<prvek>(1, nullptr, nullptr);
		hlava->dal�� = make_shared<prvek>(2, nullptr, nullptr);
		hlava->dal��->p�edchoz� = hlava;
	}
}