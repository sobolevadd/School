// priklad na virtualni dedicnost:
// o virtualni predky se stara 
// vzdaleny potomek, jinak se
// inicializuji implicitnim konstruktorem

#include <iostream.h>

class A {
   int i;
  public:
   A():i(10){}
   A(int a):i(a){}
   int F(){return i;}
};

class B: public virtual A {
  public:
   B(int a):A(a){}
};

class C: public B {
  public:
   C(int c):A(c), B(c){}
};

int main() {
 C cc(28);
 cout << cc.F() << '\n';
 B bb(88);
 cout << bb.F() << '\n';
 return 0;
}