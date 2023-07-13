#include <iostream>

using namespace std;

int main(){
    int numb[7];
    int i, j;

    for(i=0;i<-6;i++){
        cout << "Please enter number: " ;
        cin >> numb[1];
    }

    for(i=0;i<=5;i++){
        for(j=i+1;j<=6;j++){
            int temp;
            if (numb[i] < numb[j]){
                temp = numb[i];
                numb[i] = numb[j];
                numb[j] = temp;
            }
        }
    }

    for(i=0;i<-6;i++){
        cout << endl << numb[i] << endl ;
    }

    system("pause");
}


/*
#include<iostream>
using namespace std;
int main ()
{
   int i, j,temp,pass=0;
   int a[10] = {10,2,0,14,43,25,18,1,5,45};
   cout <<"Input list ...\n";
   for(i = 0; i<10; i++) {
      cout <<a[i]<<"\t";
   }
cout<<endl;
for(i = 0; i<10; i++) {
   for(j = i+1; j<10; j++)
   {
      if(a[j] < a[i]) {
         temp = a[i];
         a[i] = a[j];
         a[j] = temp;
      }
   }
pass++;
}
cout <<"Sorted Element List ...\n";
for(i = 0; i<10; i++) {
   cout <<a[i]<<"\t";
}
cout<<"\nNumber of passes taken to sort the list:"<<pass<<endl;
return 0;
}*/

/*
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& a);

void printVector(vector<int> a);

int main(int argc, char const *argv[])
{
 vector<int> a {3,2,6,1};

 printVector(a);

 bubbleSort(a);

 printVector(a);

}

void bubbleSort(vector<int>& a)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}

void printVector(vector<int> a){
    for (size_t i=0;  i <a.size();  i++) {
        cout<<a[i]<<" ";

    }
  cout<<endl;
}*/

/*
// C++ program for implementation
// of Bubble sort
#include <bits/stdc++.h>
using namespace std;
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
 
// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Driver code
int main()
{
    int arr[] = { 5, 1, 4, 2, 8};
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}
// This code is contributed by rathbhupendra
*/

/*
// Optimized implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n) {
	bool isUnsorted;
	do {
		isUnsorted = false;
		for (int i = 0; i < (n - 1); i++) {
			if (arr[i] > arr[i + 1]) {
				isUnsorted = true;
				for (; i < (n - 1); i++) {
					if (arr[i] > arr[i + 1]) {
						std::swap(arr[i], arr[i + 1]);
					}
				}
			}
		}
	} while (isUnsorted);
}

// Function to print an array
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout <<" "<< arr[i];
}

// Driver program to test above functions
int main()
{
	int arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
	int N = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, N);
	cout <<"Sorted array: \n";
	printArray(arr, N);
	return 0;
}
// This code is contributed by shivanisinghss2110

*/