#include <iostream>
#include <math.h>
using namespace std;

//typedef double (*fun)(double);
using func = double(*)(double);

double mocnina(double x){
    return x * x;
}

void table( func f, double from, double until, int how_much, const char* name){
    double step = (from - until) / (how_much - 1);
    cout << "Table of function " << name << endl;
    cout << "x           f(x)" << endl;
    cout << "---------------" << endl;
    for( int i = 0; i < how_much; i++){
        double x = from + i*step;
        cout << x << "        " << f(x) << endl;
    }

}

int main(){
    //func f = mocnina; //fun f = &mocnina;
    //cout << f(2.0) << endl;
    //table(mocnina, 0,1,11,"mocnina");
    table(sin, 0 ,3.14159265358, 20, "sin");
}