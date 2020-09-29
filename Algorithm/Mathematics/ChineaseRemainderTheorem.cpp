#include<bits/stdc++.h>
#define N 1000001
using namespace std;
int num[N];
int pp[N];

// Compute product of elements in num array
int product(int num[], int n) {
    int res = 1;
    for(int i = 0; i < n; i++) {
        res *= num[i];
    }
    return res;
}
// store the value of product/ num[i]
void productRatio(int pp[], int n, int prod){
    for(int i = 0; i < n; i++) {
        pp[i] = prod/num[i];
    }
}
// To compute multiplicative modulo inverse using Extended Euclid algorithm
int extendedEuclid(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = extendedEuclid(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1 * (a/b); // a mod b = a - (a/b)*b
    return d;
}
int modInverse1(int a, int m){
    int x,y;
    extendedEuclid(a,m,x,y);
    return (x%m + m)%m; // x may be negative
}

int main() {
    int n;
    cin >> n;
    int* rem = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> rem[i];
    }
    int prod = product(num,n);
    productRatio(pp,n,prod);
    int x = 0;
    
    // Compute the minimum value of x which statisfy the given equation
    for(int i = 0; i < n; i++) {
        x = x + (pp[i]*rem[i]*modInverse1(pp[i],num[i]));
    }
    cout << x % prod;


}