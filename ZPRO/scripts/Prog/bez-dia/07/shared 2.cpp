#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <stdlib.h>


using namespace std;

struct Nastroj 
{
	Nastroj() { cout << "  Nastroj::Nastroj()\n"; }
	~Nastroj() { cout << "  Nastroj::~Nastroj()\n"; }
};

void podproces(shared_ptr<Nastroj> p)
{
	this_thread::sleep_for(/*chrono::seconds(1)*/1s);
	shared_ptr<Nastroj> lp = p; // Bezpecne ve vicevlaknovem prostredi, i kdyz 
							   // se meni use_count 
	{
		static mutex io_mutex;
		lock_guard<mutex> zamek(io_mutex);
		cout << "Lokalni ukazatel v podprocesu:\n"
			 << "  lp.get() = " << lp.get()
			 << ", lp.use_count() = " << lp.use_count() << '\n';
	}
}

int main()
{
	system("CHCP 1250 > NULL");
	shared_ptr<Nastroj> p = make_shared<Nastroj>();

	cout << "Vytvoren sdileny Nastroj\n"
		 << "  p.get() = " << p.get()
		 << ", p.use_count() = " << p.use_count() << '\n';
	thread t1(podproces, p), t2(podproces, p), t3(podproces, p);
	p.reset(); // Uvolni vlastnictvi z main()
	cout << "Sdilene vlastnictvi mezi 3 podprocesy a uvolnene\n"
		 << "vlastnictvi z main():\n"
		 << "  p.get() = " << p.get()
		 << ", p.use_count() = " << p.use_count() << '\n';
	t1.join(); t2.join(); t3.join();
	cout << "Podprocesy skoncily, posledni uvolnil Nastroj.\n";
}
