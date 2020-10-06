#include<bits/stdc++.h>
using namespace std;
int Dp[10001][10001];

// Recursive + Memorization
int topDownKnapsack(int weight[], int value[], int W, int n){
    if(n == 0 || W == 0){
        return 0;
    }
    if(Dp[n][W]!=-1){
        return Dp[n][W];
    }
    if(W >= weight[n-1]){
        return Dp[n][W] = max(value[n-1] + topDownKnapsack(weight,value,W-weight[n-1],n-1), topDownKnapsack(weight,value,W,n-1));
    } else{
        return Dp[n][W] = topDownKnapsack(weight,value,W,n-1);
    }
}

// Iterative + Memorization
int bottomUpKnapsack(int weight[], int value[], int W, int n){
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < W+1; j++){
            if(i == 0 || j == 0) Dp[i][j] = 0;
        }
    }

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < W+1; j++){
            if(j >= weight[i-1])
            Dp[i][j] = max(value[i-1] + Dp[i-1][j-weight[i-1]], Dp[i-1][j]);
            else
            Dp[i][j] = Dp[i-1][j];
        }
    }
    return Dp[n][W];

}

int main() {
    int n;
    cin >> n; // number of total Items
    int* weight = new int[n];
    int* value = new int[n];
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }
    int W;
    cin >> W; // Total weight of a Knapsack

    memset(Dp, -1, sizeof(Dp)); // Initialize with -1 for topDown approach

    cout <<  topDownKnapsack(weight,value,W,n);
    cout <<  bottomUpKnapsack(weight,value,W,n);

}