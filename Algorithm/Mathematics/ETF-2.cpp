#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;
/*
Compute Phi[n] from 1 to n
using sieve in O(nlog(logn)) time complexity
*/
int phi[MAX];
void init(int max){
    for(int i = 1; i <= max; i++){
        phi[i] = i;
    }
    for(int i = 2; i <= max; i++){
        if(phi[i] == i){
            for(int j = i; j <= max; j+=i){
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
}

int main(){
    init(1000000);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << phi[n] << endl;
    }
}