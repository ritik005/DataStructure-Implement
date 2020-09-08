#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
  int i,no,j;
  for(i = 1; i < n; i++){
    j = i - 1;
    no = arr[i];
    while(j >= 0 && arr[j] > no){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = no;
  }
}

void print(int arr[], int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d", arr[i]);
    printf("\n");
  }
  
}
int main(void) {
  int arr[1000007], n,i;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> arr[i];
  }
  insertionSort(arr,n);
  print(arr,n);
  
  return 0;
}