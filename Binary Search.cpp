//Binary search
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<< "Enter the number of element in the array: ";
    cin>> n;
    int arr[n];

    cout<< "Enter the sorted elements of the array: \n";
    for(int i = 0; i < n; i++){
        cin>> arr[i];
    }
    int x;
    cout<< "Enter the element to be searched: ";
    cin>> x;

    int l = 0;
    int h = n - 1;
    int mid;

    while(l <= h){
        mid = l + (h - l)/ 2;

        if( arr[mid] == x){
            cout<< "Element found at index " << mid <<"\n";
            return 0;
        }
        else if( arr[mid] < x)
            l = mid + 1;
        else
            h = mid - 1;
    }
    cout<< "Element not present in the array \n";

    return 0;
}
