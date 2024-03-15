#include <iostream.h>
#include <stdlib.h>

void start(){
 cout << "jedeme " << endl;
}

void start1(){
 cout << "a porad jedeme " << endl;
}


void konec(){
 cout << "uz je tu smytec" << endl;
}


void konec1(){
 cout << "doopravdy" << endl;
}

void skoncime(){
 cout << "blizi se konec" << endl;
}


#pragma startup start 100

#pragma startup start1 101

#pragma exit konec 100

#pragma exit konec1 101

int main(){
 atexit(skoncime);
 cout << "to je vono" << endl;
 return 1;
}