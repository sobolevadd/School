#include <iostream>


using namespace std;

void InsertionSort (int a[], int length);

int main(){
    int a[] = {34,65,1,5,3456,10};
    InsertionSort (a, 6);
    for (int i = 0; i < 6; i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}

void InsertionSort (int a[], int length){
    for (int i = 1; i < length; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }
}


