#include <iostream>
#include <memory>
#include <stdlib.h>

using namespace std;

weak_ptr<int> slaby;

void f()
{
	if (auto sdileny = slaby.lock()) { // Pro pristup k datum je treba ziskat sdileny ukazatel
		cout << *sdileny << "\n";
	}
	else {
		cout << "Slaby na nic neukazuje\n";
	}
}

int main()
{
	system("CHCP 1250 > NUL");
	{
		auto sp = make_shared<int>(42);
		slaby = sp;
		f();
	}

	f();
}