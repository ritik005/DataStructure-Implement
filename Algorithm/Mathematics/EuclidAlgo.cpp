/* Euclid's Algorithm is used to find out the greatest common divisor of
two number a, b in O(log(max(a,b))) time complexity
*/
#include<iostream>
using namespace std;

// Recursive approach

int Recgcd(int a, int b){
    if(b == 0){
        return a;
    } else {
        return Recgcd(b,a%b);
    }
}
// Iterative approach

int gcd(int a, int b){
    while(b){
        a = a%b;
        swap(a,b);
    }
    return a;
}
int main(){
    int a, b;
    cin >> a >>  b;
    cout << gcd(a,b) << "\n";
    cout << Recgcd(a,b);
}