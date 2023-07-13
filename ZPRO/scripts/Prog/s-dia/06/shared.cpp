#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <stdlib.h>


using namespace std;

struct N�stroj 
{
	N�stroj() { cout << "  N�stroj::N�stroj()\n"; }
	~N�stroj() { cout << "  N�stroj::~N�stroj()\n"; }
};

void podproces(shared_ptr<N�stroj> p)
{
	this_thread::sleep_for(/*chrono::seconds(1)*/1s);
	shared_ptr<N�stroj> lp = p; // Bezpe�n� ve v�cevl�knov�m prost�ed�, i kdy� 
							   // se m�n� use_count 
	{
		static mutex io_mutex;
		lock_guard<mutex> z�mek(io_mutex);
		cout << "Lok�ln� ukazatel v podprocesu:\n"
			 << "  lp.get() = " << lp.get()
			 << ", lp.use_count() = " << lp.use_count() << '\n';
	}
}

int main()
{
	system("CHCP 1250 > NULL");
	shared_ptr<N�stroj> p = make_shared<N�stroj>();

	cout << "Vytvo�en sd�len� N�stroj\n"
		 << "  p.get() = " << p.get()
		 << ", p.use_count() = " << p.use_count() << '\n';
	thread t1(podproces, p), t2(podproces, p), t3(podproces, p);
	p.reset(); // Uvoln� vlastnictv� z main()
	cout << "Sd�len� vlastnictv� mezi 3 podprocesy a uvoln�n�\n"
		 << "vlastnictv� z main():\n"
		 << "  p.get() = " << p.get()
		 << ", p.use_count() = " << p.use_count() << '\n';
	t1.join(); t2.join(); t3.join();
	cout << "Podprocesy skon�ily, posledn� uvolnil N�stroj.\n";
}
