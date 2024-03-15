#include <fstream.h>

class dva{int i,j;
 friend ostream& operator<<(ostream &s, dva& d){
  s << d.i << ' ' << d.j;
  return s;
 }
 public:
 dva(int ii, int jj):i(ii), j(jj){}
};

fstream f("data.dta", ios::out);

ostream& sedm(ostream &s){
 s<<"chachachacha chachacha";
 return s;
}

void main(){
 for(int i=0; i < 10; i++) f<<i<<endl;
 f.close();
 f.open("data.dta", ios::in);
 while(f){
  f>>i;
  cout << i;
 }
 dva d(1,2);
 cout << endl;
 cout << d;
 f.close();
 f.open("data.dt", ios::out);
 f << d;
 f.close();
 cout<<sedm;
}