#include<iostream>
using namespace std;

void merge(int* arr, int s, int e, int mid){
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[500];
    while(i<= mid && j <= e){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++]; 
    }
    while(j <= e){
        temp[k++] = arr[j++];
    }
    for(int i = s; i <= e; i++){
        arr[i] = temp[i];
    }

}

void meregeSort(int* arr, int s, int e){
    if(s>=e) return;
    int mid = s+(e-s)/2;
    meregeSort(arr,0,mid);
    meregeSort(arr,mid+1,e);

    merge(arr,s,e,mid);
}

int main(){
    int n; cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    meregeSort(arr,0,n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}