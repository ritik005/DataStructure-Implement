#include<iostream>
using namespace std;
//Primality Test
//Time complexity - O(sqrt(n))

bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i*i <= n; i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if(isPrime(n)) cout << "Prime number";
    else cout << "Not Prime";
}