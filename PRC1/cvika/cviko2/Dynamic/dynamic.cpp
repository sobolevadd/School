#include <iostream>
#include <algorithm>


using namespace std;

//1. nechte uzivatele zadat pozadovany pocet nahodnych cisel mezi 1 a 100
//2. dynamicky alokujte pole pozadovane velikosti
//3. pole naplnte nahodnymi cisly mezi 1 a 100 (pouzijte funkci rand)
//4. pole vytisknete
//5. najdete v poli nejmensi prvek
//6. uvolnete pamet

//T *ptr = new T[N];
//ptr[0] = t0;
//delete [] ptr;

void fillArray(int *arr, unsigned int N)
{
    for (unsigned int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100 + 1; // module between 1 and 100 (rand() % 100 is between 1 and 99)
    }
}

void printArray(int *arr, unsigned int N)
{
    for (unsigned int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findMinimumInArray(int *arr, unsigned int N)
{
    int min = arr[0];
    for (unsigned int i = 1; i < N; i++)
    {
        if ( arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}


int main()
{
    //cout << RAND_MAX << endl;
    unsigned int size;
    int *ptr;
    srand(time(nullptr));
    cout << " Hello, how many random numbers between 1 and 100 do you need?" << endl;
    cin >> size;
    ptr = new int[size];
    fillArray(ptr, size);
    printArray(ptr, size);
    cout << "Minimal element has value of " << findMinimumInArray(ptr, size) << endl;
    delete [] ptr;
    ptr = nullptr;
    return 0;
}





/*
// C++ program to find the min and max element
// of Array using sort() in STL

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Get the array
	int arr[] = { 1, 45, 54, 71, 76, 12 };

	// Compute the sizes
	int n = sizeof(arr) / sizeof(arr[0]);

	// Print the array
	cout << "Array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	// Find the minimum element
	cout << "\nMin Element = "
		<< *min_element(arr, arr + n);

	// Find the maximum element
	cout << "\nMax Element = "
		<< *max_element(arr, arr + n);
	// Storing the pointer in an address
	int &min = *min_element(arr,arr+n );
	int &max = *max_element(arr,arr+n );
	cout<<"\nFinding the Element using address variable";
	cout<<"\nMin Element = "<<min;
	cout<<"\nMax Element = "<<max;
	return 0;
}
*/