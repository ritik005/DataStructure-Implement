#include<bits/stdc++.h>
using namespace std;
int Dp[10001][10001];
/*Varaiation of 0-1 Knapsack
Find the count of subsets whose
sum is equal to given sum
*/
int countSubsetSum(int arr[], int n, int sum) {
    // Initialization
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(i == 0) Dp[i][j] = 0;
            if(j == 0) Dp[i][j] = 1;
        }
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(j >= arr[i-1]){
                Dp[i][j] = Dp[i-1][j-arr[i-1]] + Dp[i-1][j];
            } else {
                Dp[i][j] = Dp[i-1][j];
            }
        }
    }
    return Dp[n][sum];
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    cout << countSubsetSum(arr,n,sum);

}