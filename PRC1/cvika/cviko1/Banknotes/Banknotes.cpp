/*
Napiste program, ktery vrati nejmensi pocet bankovek a minci, 
kterymi lze zaplatit ucet v zadane hodnote.
Napr. pro hodnotu 403, kc vrati 2*200+1*2+1*1.

#include <iostream>

using namespace std;
enum {OK};



int main()
{
    int money [12] = {5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int numOfNotes [12] = {};
    int value;
    cout << "Please provide value: " << endl;
    cin >> value;

    for (int i = 0; i < 12; i++){
        int tmp = value / money[i];
        if (tmp != 0){
            numOfNotes[i] = tmp;
            value = value % money[i];
        }
    }

    for (int j = 0; j < 12; j++){
        cout << money[j] << ": " << numOfNotes[j] << endl;
    }
    
    return OK;
}

*/

#include <iostream>

using namespace std;
enum {OK};


unsigned int money[N]= {5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

void calculate(unsigned int value,unsigned int *res, unsigned int *notes, int n ) 
{
    unsigned int cnt;
    for (int i = 0; i < n; i++){
        cnt = value / notes[i];
        res[i] = cnt;
        value = value - cnt*notes[i];
        //value = value % notes[i];
    }
}

void print(unsigned int value,unsigned int *res, unsigned int *notes, int n ) 
{
    cout << value << " = \n";
    for (int i = 0; i < n; i++){
        if(res[i] > 0){
            cout << notes[i] << " x " << res[i] << " \n";
        }
    }
}

int main()
{
    unsigned int amount;
    unsigned int result[N];
    cout << "Please provide value:  " << endl;
    cin >> amount;
    calculate(amount, result, money, N);
    print(amount, result, money, N);
 
    return OK;
}