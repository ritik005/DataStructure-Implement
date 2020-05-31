#include <iostream>

using namespace std;
void tower(int n, char src, char help, char dest){
    if(n == 0){
        return;
    }
    tower(n-1,src,dest,help);
    cout << "Move" << n << "disks from" << src << "to" << dest << endl;
    tower(n-1,help,src,dest);
}

int main(){
    int n;
    cin >> n;
    tower(n,'A','B','C');
    return 0;
}