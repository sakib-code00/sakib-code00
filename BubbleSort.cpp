//Bubble sort.
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {8,5,10,3,6};
    int i,j, n = 5;

    int flag, counter = 0;
    for(i = 0; i < n - 1; i++){
        flag = 0;
        for(j = 0; j< n - 1 - i; j++){
                counter ++;
                if( arr[j] > arr[j + 1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    flag = 1;
            }
        }
        if(flag == 0){
            break;
        }

    }
    cout<< "After Sorting:" <<endl;
        for(i = 0; i < n; i++){
           cout<< arr[i] <<" ";
        }
    cout<<endl;
    cout<< "Total loop: " << counter;
    return 0;
}
