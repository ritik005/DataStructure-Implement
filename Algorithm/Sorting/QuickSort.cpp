#include<iostream>
#include<algorithm>
using namespace std;

// Recursive solution (Divide and conqeuer algorithm)
int partition(int* arr, int s, int e){
    int i = s-1;
    int j = s;
    int pivot = arr[e];
    for( ; j <= e-1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

void quickSort(int* arr, int s, int e){
    if(s>=e) return;
    int p = partition(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}
void print(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    print(arr,n);
}