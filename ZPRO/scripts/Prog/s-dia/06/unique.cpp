#include <iostream>
#include <memory>
#include <stdlib.h>

using namespace std;

struct JenTak
{
	int data;
	JenTak(int data): data(data) { cout << "JenTak::JenTak\n"; }
	~JenTak() { cout << "JenTak::~JenTak\n"; }
	void metoda() { cout << "JenTak::metoda\n"; }
};

void f(const JenTak & x)
{
	cout << "f(const JenTak&): " << x.data << "\n";
}

int main()
{
	system("CHCP 1250 >NUL");
	//unique_ptr<JenTak[]> upjt(new JenTak[5]{ 2,3,4,5,6 });
	unique_ptr<JenTak> p1(new JenTak(7));  // p1 vlastní JenTak
	if ((bool)p1)
	{
		p1->metoda();
	}

	{
		unique_ptr<JenTak> p2(move(p1));  // teï je JenTak vlastnìno p2
		f(*p2);
		p1 = move(p2);  // Vlastnictví se vrací p1
		cout << "Ruším p2...\n";
	}

	if (p1) p1->metoda();

	//  Instance JenTak bude zrušena, když p1 zanikne
}
