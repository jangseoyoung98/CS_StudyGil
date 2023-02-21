#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
  for(int i=n-1; i>0; i--){
    for(int j=0; j<i; j++){
      if(arr[j]<arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main(){
  int arr[10]= {-1,4,5,1,2,6,3,3,1,45};
  bubble_sort(arr,10);
}