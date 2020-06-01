#include <iostream>
#include <bitset>
using namespace std;

// Find the total number of configurations of placing n queens in n*n matrix.

bitset<30> col,d1,d2;
void solve(int r, int n, int &ans){
    if(r == n){
        ans++;
        return;
    }
    for(int j = 0; j < n; j++){
        if(!col[j] && !d1[r-j+n-1] && !d2[r+j]){
            col[j] = d1[r-j+n-1] = d2[r+j] = 1;
            solve(r+1,n,ans);
            //Backtracking
            col[j] = d1[r-j+n-1] = d2[r+j] = 0;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    solve(0,n,ans);
    cout << ans;
    return 0;
}