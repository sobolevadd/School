#include <iostream>
#include <cmath>

using namespace std;

double f1(double x){
    return tan(x)-x;
}

double f2(double x){
    return cos(x);
}

void decide (double (*f) (double), double a, double b, double& x, double eps){
    //x je hledany koren
    // c je stred (a,b)
    double c = (a + b)/2;
    if (abs (b-a) > eps){
        if (f(a)* f(c) <= 0) decide (f, a,c,x,eps);
        else decide (f, c, b, x, eps);
    } // rekruzivni volani, neni-li splenena podminka konce
    // jinak definuj vysledek a skonci
    else{
        x = c;
    }
}

int main(){
    double a = 7;
    double b = 8;
    double x = 0;
    double eps = 0.00001;
    decide (f, a,b,x,eps); 
    cout << x << endl;
    return 0;
}