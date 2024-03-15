#include <iostream>
#include <memory>
#include <stdlib.h>

using namespace std;

weak_ptr<int> slabý;

void f()
{
	if (auto sdílený = slabý.lock()) { // Pro pøístup k datùm je tøeba získat sdílený ukazatel
		cout << *sdílený << "\n";
	}
	else {
		cout << "Slabý na nic neukazuje\n";
	}
}

int main()
{
	system("CHCP 1250 > NUL");
	{
		auto sp = make_shared<int>(42);
		slabý = sp;
		f();
	}

	f();
}