//Selection SortS
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,j,pos,t;
    cout<< "Enter the size of array:"<<endl;
    cin>>n;
    long long int a[n];
    cout<< "Enter the elements:"<<endl;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[pos]) pos=j; // Find the starting element of an array
        }
        t=a[pos]; // swap
        a[pos]=a[i];
        a[i]=t;
    }
    cout<< "After Sorting: "<<endl;
    for(i=0;i<n;i++) cout<<a[i]<<' ';
    return 0;
}
