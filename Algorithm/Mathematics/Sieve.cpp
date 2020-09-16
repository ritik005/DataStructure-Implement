#include<iostream>
#define N 1000001
using namespace std;
// Sieve of Eratosthenes :- used to find prime numbers in the given range;

int arr[N];

void sieve(){
    for(int i = 0; i < N; i++){
        arr[i] = 1; // Marking all as a prime
    }
    arr[0] = arr[1] = 0; // 0 and 1 are not prime
    for(int i = 2; i*i < N; i++){
        if(arr[i]){
            for(int j = i*i; j < N; j+=i){
                arr[j] = 0; // Marking mutliple of i as non prime
            }
        }
    }
}
void print(){
    for(int i = 0; i < 11; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    sieve();
    print();
}