//insertion sort
#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) // If arr[j]> arr[i], the value must be swapped, so the value is replaced.
        {
            arr[j + 1] = arr[j];  // swap
            j = j - 1;
        }
        arr[j + 1] = key;  // swap
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 5, 13, 11, 15, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    cout<< "After sorting elements are : "<<endl;
    printArray(arr, n);

    return 0;
}
