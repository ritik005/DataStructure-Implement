#include<bits/stdc++.h>
#define LL long long int
#define P 1000000007
using namespace std;
/*
Compute binomial coefficient using
multiplicative modulo inverse
*/
int fact[1000001];

int power(int a, int b) {
    LL res = 1;
    while(b) {
        if(b%2){
            res = (res *1LL* a) % P;
            b--;
        }
        a = (a *1LL* a) % P;
        b /= 2;
    }
    return res % P;
}

int C(int n, int k){
    if(k > n) return 0;
    LL res = fact[n] % P;
    res = (res * 1LL * power(fact[k], P-2)) % P;
    res = (res * 1LL * power(fact[n-k], P-2)) % P;
    return res % P;

}

int main() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= 1000000; i++){
        fact[i] = (fact[i-1] * 1LL * i) % P;
    }
    int n,k;
    cin >> n >> k;
    cout << C(n,k);
}
