#include<bits/stdc++.h>
using namespace std;
int Dp[10001][10001];
/* Variation of 0-1 Knapsack
Find wheather an array can be divided into 
to parts such that sum of each section is equal
*/
bool equalSumPartition(int arr[], int sum, int n) {
    if(sum & 1) return false;
    //Initialization
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < (sum/2) + 1; j++){
            if(i == 0) Dp[i][j] = 0;
            if(j == 0) Dp[i][j] = 1;
        }
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < (sum/2) + 1; j++){
            if(j >= arr[i-1]){
                Dp[i][j] = Dp[i-1][j-arr[i-1]] || Dp[i-1][j];
            } else{
                Dp[i][j] = Dp[i-1][j];
            }
        }
    }
    return Dp[n][sum/2];
}


int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    cout << equalSumPartition(arr,sum,n);
}