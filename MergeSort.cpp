//Merge Sort

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high){
  int i, j, k;
  int n1 = mid + 1 - low;
  int n2 = high - mid;
  int l[n1], r[n2];
  for(int i=0; i<n1; i++) l[i]=arr[low+i]; // left
  for(int j=0; j<n2; j++) r[j]=arr[mid+j+1]; // right
  i=0; j=0; k=low;

  while(i<n1 && j<n2){
    if(l[i]<=r[j]) arr[k++]=l[i++];
    else arr[k++]=r[j++];
  }
  while(i<n1) arr[k++]=l[i++];
  while(j<n2) arr[k++]=r[j++];
}

void mergeSort(int arr[],int low,int high){ // sorting
  int mid;
  if(low<high){
    mid=low+(high-low)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}

int main()
  {

    cout<< "Enter number of elements: " <<endl;
    int n;
    cin>>n;
    int arr[n];

    cout<< "Enter Elements: "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];

    mergeSort(arr,0,n-1);

    cout<< "After Sorting:"<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
  }
