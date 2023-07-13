#include <iostream>
using namespace std;

int main(){
    char c;
    cout << "Enter a letter: ";
    cin >> c;
    if (('a' <= c) && (c <= 'z')){
        cout << "You've inserted a small letter" << endl;
    }else if(('A' <= c) && (c <= 'Z')) {
        cout << "You've inserted a capital letter" << endl;
    }else if(('0' <= c) && (c <= '9')){
        cout << "You've inserted a number" << endl;
    }else{
        cout << "Wrong input" << endl;
    }
    cout << "ASCII code of inserted character" << (int) c << endl;
    return 0;

}

/* switch
int main(){
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    switch(n){
        case 1:
            cout << "Monday " << endl;
            break;
        case 2:
            cout << "Tuesday " << endl;
            break;
        case 3:
            cout << "Wednesday " << endl;
            break;
        case 4:
            cout << "Thursday " << endl;
            break;
        case 5:
            cout << "Friday " << endl;
            break;
        case 6:
            cout << "Saturday " << endl;
            break;
        case 7:
            cout << "Sunday " << endl;
            break;
        default:
            cout << "Mistake" << endl;
    }
    return 0;
}
*/

/*Prime number
bool Prime(int n);

int main(){
    int n = 2;
    cout << " Enter a number: ";
    cin >> n;
    
     if(Prime(n)){
        cout << "Number " << n << " is prime n" << endl;
    }else{
        cout << "Number " << n << " is not prime " << endl;
    }
}

bool Prime(int n){
    if (n < 2){
        return false;
    }
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }return true;
}*/

/*Even Odd number
bool Even(int n);

/*if(Even){
            cout << "Number " << n << " is even" << endl;
        }else{
            cout << "Number " << n << " is odd" << endl;
        }
bool Even(int n)
{
    if (n % 2 == 0){
        return true;
    }return false;
}*/

/* bool

bool JeSude(int n);

int main(){
    int  n;
    cout << "Enter an integer n =";
    cin >> n;
    if (JeSude(n)){
        cout << n << " je sude" << endl;
        
    } else {
        cout << n << " neni sude" << endl;
    }
    return 0;
    
}

bool JeSude(int n){
    if (n % 2 == 0){
        return true;
    } else {
        return false;
    }
}*/

/* bool
bool JeSude(int n);

int main(){
    int  n;
    cout << "Enter an integer n =";
    cin >> n;
    JeSude(n);
    return 0;
    
}

bool JeSude(int n){
    if (n % 2 == 0){
        cout << n << " je sude" << endl;
        return true;
    } else {
        cout << n << " neni sude" << endl;
    }
    return false;
}*/

/*int main()
{
    for (int i = 0; 1 <= 20; i++)
    {   
        if (i == 13)
        {
            break;
        }
        cout << i << endl;
    }
    return 0;

}*/