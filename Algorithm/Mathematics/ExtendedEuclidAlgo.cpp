/*
Extended Euclid's algorithm finds the relation between gcd(a,b) with a, b
in the form of liner equation.
i.e:- a.x + b.y = gcd(a,b)
*/

#include<iostream>
using namespace std;

int exEuclid(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = exEuclid(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1 * (a/b); // a mod b = a - (a/b)*b
    return d;
}

int main(){
    int a,b,x,y;
    cin >> a >> b;
    cout << exEuclid(a,b,x,y) << "\n";
    cout << x << " " << y;
}