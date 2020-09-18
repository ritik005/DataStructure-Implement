#include<iostream>
#define ll long long
using namespace std;

ll binaryExponentiation(ll a, ll b, ll m){
    ll res = 1;
    while(b){
        if(b%2){
            res = (res*a)%m;
            b--;
        }
        a = (a*a)%m;
        b /= 2;
    }
    return res%m;
}

ll extendedEuclid(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1,y1;
    ll d = extendedEuclid(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1 * (a/b); // a mod b = a - (a/b)*b
    return d;
}

ll modInverse1(ll a, ll m){
    ll x,y;
    extendedEuclid(a,m,x,y);
    return (x%m + m)%m; // x may be negative
}
ll modInverse2(ll a, ll m){
    return binaryExponentiation(a,m-2,m); // a inverse = (a^m-2)%m
}


int main(){
    ll a,m;
    cin >> a >> m;
    ll mod1 = modInverse1(a,m);
    ll mod2 = modInverse2(a,m);
    cout << mod2;
}