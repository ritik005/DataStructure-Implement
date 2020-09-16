#include<iostream>
#define ll long long 
using namespace std;
// Calculate a^b in O(log n) := Iterative approach

ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b%2){
            res = res*a;
            b--;
        }
        a = a*a;
        b /= 2;
    }
    return res;
}
// Recursive approach 

ll Recpower(ll a, ll b){
    if(b == 0) return 1;
    ll res = a*a;
    if(b%2) return a*Recpower(res,b/2);
    else return  Recpower(res,b/2);
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << power(a,b) << endl;
    cout << Recpower(a,b);
}