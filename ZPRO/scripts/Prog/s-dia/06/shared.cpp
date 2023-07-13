#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <stdlib.h>


using namespace std;

struct Nástroj 
{
	Nástroj() { cout << "  Nástroj::Nástroj()\n"; }
	~Nástroj() { cout << "  Nástroj::~Nástroj()\n"; }
};

void podproces(shared_ptr<Nástroj> p)
{
	this_thread::sleep_for(/*chrono::seconds(1)*/1s);
	shared_ptr<Nástroj> lp = p; // Bezpeèné ve vícevláknovém prostøedí, i když 
							   // se mìní use_count 
	{
		static mutex io_mutex;
		lock_guard<mutex> zámek(io_mutex);
		cout << "Lokální ukazatel v podprocesu:\n"
			 << "  lp.get() = " << lp.get()
			 << ", lp.use_count() = " << lp.use_count() << '\n';
	}
}

int main()
{
	system("CHCP 1250 > NULL");
	shared_ptr<Nástroj> p = make_shared<Nástroj>();

	cout << "Vytvoøen sdílený Nástroj\n"
		 << "  p.get() = " << p.get()
		 << ", p.use_count() = " << p.use_count() << '\n';
	thread t1(podproces, p), t2(podproces, p), t3(podproces, p);
	p.reset(); // Uvolní vlastnictví z main()
	cout << "Sdílené vlastnictví mezi 3 podprocesy a uvolnìné\n"
		 << "vlastnictví z main():\n"
		 << "  p.get() = " << p.get()
		 << ", p.use_count() = " << p.use_count() << '\n';
	t1.join(); t2.join(); t3.join();
	cout << "Podprocesy skonèily, poslední uvolnil Nástroj.\n";
}
