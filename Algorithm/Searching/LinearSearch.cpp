#include<iostream>
using namespace std;

//Using Recursion
int linearSearch(int* arr, int s, int n, int key){
    if(s == n) return -1;
    if(arr[s] == key) return s;
    else{
        return linearSearch(arr,s+1,n,key);
    }
}
//iterative solution
int Search(int* arr, int n, int key){
    for(int i = 0; i < n; i++){
        if(arr[i] == key) return i;
    }
    return -1;
}

int main(){
    int n,key; cin >> n >> key;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << linearSearch(arr,0,n,key);
    cout << Search(arr,n,key);


}