#include<iostream>
using namespace std;
// recursive solution

int binarySearch(int* arr, int s, int e, int key){
    int mid = s+(e-s)/2;
    if(s>=e) return -1;
    if(arr[mid] == key) return mid;
    else if(arr[mid] > key){
       binarySearch(arr,s,mid-1,key);
    }
    else{
         binarySearch(arr,mid+1,e,key);
    }
}

int main(){
    int n,key; cin >> n >> key;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << binarySearch(arr,0,n,key);
}