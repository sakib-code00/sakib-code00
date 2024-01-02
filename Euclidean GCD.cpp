// EUCLIDEAN GCD Algorithm.
#include <bits/stdc++.h>
using namespace std;

int findGcd(int a, int b){
    if (a == 0)
        return b;
    return findGcd(b % a, a);
}
int main(){
    int num1, num2;
    cout<< "Enter First Number: ";
    cin>> num1;
    cout<< "Enter Second Number: ";
    cin>> num2;

    int gcd = findGcd(num1, num2);
    cout<< "GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;

    return 0;
}
