#include<iostream>
#include<algorithm>
using namespace std;

//Recursive approach
void Rec_bubbleSort(int* arr, int j, int n){
    if(n == 1) return;
    if(j == n-1){
        return Rec_bubbleSort(arr,0,n-1);
    }
    if(arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
        return Rec_bubbleSort(arr,j+1,n);
    }
}


//Iterative approach
void bubbleSort(int* arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int n; cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bubbleSort(arr,n);
    Rec_bubbleSort(arr,0,n);    
    for(int i = 0 ; i < n; i++){
        cout << arr[i] << " ";
    }
}