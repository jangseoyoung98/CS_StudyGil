#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n){
  int j=0;
	for(int i=1;i<n;i++){
		int key = arr[i];
		for(j=i-1; j>=0 && arr[j]>key; j--){
      arr[j+1] = arr[j];
    }
    arr[j+1] = key;
	}
}

int main(){
  int arr[10]= {-1,4,5,1,2,6,3,3,1,45};
  insertion_sort(arr,10);
}