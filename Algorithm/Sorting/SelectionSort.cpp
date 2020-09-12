#include <iostream>
using namespace std;

void SelectionSort(int* arr, int n){
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i],minIndex);
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
  SelectionSort(arr,n);
  print(arr,n);
  
  return 0;
}