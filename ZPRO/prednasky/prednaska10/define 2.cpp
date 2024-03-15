/*#define napis cout << "Nazdar" << endl;

#include <iostream>
using namespace std;

int main(){
    napis;
}*/

#include <iostream>
using namespace std;

#define mocnina(x) ((x)*(x))

#define PRINT(x) cout << "Funtion:" << __func__ << " "#x " = " << x << endl;

#define DATE(type) struct date_ ## type {type day, month, year;}

DATE(int);

//#undef mocnina;

#define N  10;

#if N > 5
void ladeni(){
    cout << "ladime" << endl;
}
#else
void ladeni(){

}
#endif

//struct date_int{//...};

int moc(int x){
    PRINT(x);
    return x*x;
}

int main(){
    ladeni(4);
    int a = 5;
    PRINT(a);
    cout << mocnina(a+1) << endl;
    PRINT(a+1);
    //cout << !(a+1)(a+1) << endl;
    cout << mocnina(++a) << endl;
    a=5;
    cout << moc(++a)<< endl;
    PRINT(a);
}