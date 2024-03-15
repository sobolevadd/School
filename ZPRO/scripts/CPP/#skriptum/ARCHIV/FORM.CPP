// Priklad na formatovani vstupu a vystupu
// pomoci datovych proudu

#include <fstream.h>
#include <iomanip.h>
#include <math.h>

const double pi = 3.1415926535897;

ofstream F("con");

int main(){
 double x;
 F << "tabulka funkce sinus" << endl << endl;
 F << "x" << "           " << "sin x" << endl
   << "_________________" << endl;
 F << setiosflags(ios::showpoint);
 for(int i =0; i < 100; i+=10){
  x = i/180.0*pi;
  F << setw(5) << setprecision(1) << (double)i;
  F << "        " << setw(8) << setprecision(6) << sin(x) << endl;
 }

 return 0;
}