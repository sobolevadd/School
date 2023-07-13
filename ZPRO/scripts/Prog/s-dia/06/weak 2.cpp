#include <iostream>
#include <memory>
#include <stdlib.h>

using namespace std;

weak_ptr<int> slab�;

void f()
{
	if (auto sd�len� = slab�.lock()) { // Pro p��stup k dat�m je t�eba z�skat sd�len� ukazatel
		cout << *sd�len� << "\n";
	}
	else {
		cout << "Slab� na nic neukazuje\n";
	}
}

int main()
{
	system("CHCP 1250 > NUL");
	{
		auto sp = make_shared<int>(42);
		slab� = sp;
		f();
	}

	f();
}