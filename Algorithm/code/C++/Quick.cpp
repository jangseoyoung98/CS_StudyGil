#include<bits/stdc++.h>
using namespace std;

# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int partition(int list[], int left, int right){
  int pivot, temp;
  int low, high;

  low = left;
  high = right + 1;
  pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택

  /* low와 high가 교차할 때까지 반복(low<high) */
  do{
    /* list[low]가 피벗보다 작으면 계속 low를 증가 */
    do {
      low++; // low는 left+1 에서 시작
    } while (low<=right && list[low]<pivot);

    /* list[high]가 피벗보다 크면 계속 high를 감소 */
    do {
      high--; //high는 right 에서 시작
    } while (high>=left && list[high]>pivot);

    if(low<high){
      SWAP(list[low], list[high], temp);
    }
  } while (low<high);
  SWAP(list[left], list[high], temp);

  // 피벗의 위치인 high를 반환
  return high;
}

void quick_sort(int list[], int left, int right){
  if(left<right){
    //분할시키기.
    int q = partition(list, left, right); // q: 피벗의 위치

    // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
    quick_sort(list, left, q-1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
    quick_sort(list, q+1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
  }
}
void main(){
  int list[] = {5, 3, 8, 4, 9, 1, 6, 2, 7};
  quick_sort(list, 0, 8);
}