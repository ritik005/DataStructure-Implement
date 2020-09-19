/*
1- prime factorization on O(sqrt(n))
2- prime factorization using seive in O(logn)
*/
#include<iostream>
#include<vector>
#define ll long long 
using namespace std;
// 1 - O(sqrt(n))

vector<ll> primeFactor(ll n){
    vector<ll> res;
    for(int i = 2; i*i <= n; i++){
        while(n%i==0){
            res.push_back(i);
            n /= i;
        }
    }
    if(n > 1) res.push_back(n);
    return res;
}
// 2 - Using Sieve
vector<ll> factorize(ll n, ll minPrime[]) {
    vector<ll> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> v = primeFactor(n);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ",";
    }
    ll minPrime[n+1] = {0};
    for(int i = 2; i*i <= n; i++){
        if(minPrime[i] == 0){ // i.e i is prime
            for(int j = i*i; j <= n; j+=i){
                if(minPrime[i] == 0) minPrime[j] = i;
            }
        }
    }
    for(int i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
    vector<ll> vi = factorize(n ,minPrime);

    for(int i = 0; i < vi.size(); i++){
        cout << vi[i] << ",";
    }



}