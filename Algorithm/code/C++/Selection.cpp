#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
int min;
  for(int i=0; i<n-1; i++){
    min = i;

    for(int j=i+1; j<n; j++){
      if(arr[j]<arr[min])
        min = j;
    }

    if(i != min){
      int temp=arr[i];
      arr[i]=arr[min];
      arr[min]=temp;
    }
  }
}

int main(){
  int arr[10]= {-1,4,5,1,2,6,3,3,1,45};
  selection_sort(arr,10);
}