#include <iostream>
#include "stack.cpp"

using namespace std;

int main(){
    Stack *st;
    int N; //neni konstanta v dobe prekladu, compile time
    cout << "Prosim, zadejte kapacitu zasobniku: ";
    cin >> N; //hodnotu se dozvimeaz za behu programu, run time
    st = createStack(N);
    //
    
    //push(st, 5); //pad programu, st je v tuto chvili nulovy ukazatel
    if(!st){
        cerr<<"Vytvoreni zasobniku selhalo\n";
        return -1;
    }

    //st->capacity = 2;
    //st->data[2] = 10;
    //st->sp - 51;
    //st->data = nullptr;

    int i = 0;
    while (!isFull(st)){
        push(st, i);
        i++;
    }

    //vyprazdneni zasobniku
    while(!isEmpty(st)){
        cout << top(st) << " ";
        pop(st);
    }
    cout << "\n";
    destroyStack(st); //uvolneni pameti
    return 0;
}