#include <iostream>

using namespace std;

int main(){
    double x[5] = {1.1,2.5,1.8,3.1,5.1};
    int N = sizeof(x)/sizeof(x[0]);
    for (int i = 0; i < N-1; i++){
        for (int j = 0; j < N-1; j++){
            if(x[j] > x[j+1]){
                double temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++)
    cout << x[i] << " ";
    cout << endl;
    return 0;
}




// void sum (double x[], double y[], double z[], int size) ;
// const int N = 5;
// int main(){
//     double x[N] = {1.1,2.5,2.8,3.1,5.2};
//     double y[N] = {2.1,1.5,3.8,2.5,4.2};
//     double z[N];
//     sum (x,y,z, N);
//     for(int i = 0; i < N; i++){
//         cout << z[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }
// void sum (double x[], double y[], double z[], int size ){
//     for(int i = 0; i < size; i++){
//         z[i] = x[i] + y[i];
//     }
// }


// int main(){
//     int A[3][4] = {{1,2,1,1,},{2,1,2,1},{1,1,2,1}};
//     int B[4][3] = {{3,2,1},{1,1,1,},{1,2,1}};
//     int C[2][2] = {0};
//     for (int i = 0; i < 3; i++){
//         for (int j = 0;j < 3; j++){
//             for (int k = 0;k < 4; k++){
//                 C[i][j] = C[i][j] + A[j][k]*B[j][k]
//             }
//         }
//     } 
// }