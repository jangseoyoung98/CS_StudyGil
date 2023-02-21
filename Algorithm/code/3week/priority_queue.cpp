#include<bits/stdc++.h>
#define MAX_LEN 16
using namespace std;


class pq{
	public:
		int arr[MAX_LEN]={0,};
		int size=0;

		void enqueue(int val)
		{
			int i = size+1; 
			if (size == MAX_LEN) { // 배열에 공간이 없으면 실패
				printf("Overflow: Could not insertKey\n");
			}

			// 힙 끝에 요소 삽입.
			cout << "val : " << val << endl;
			arr[i]= val;
			size++;
			// 우선순위가 부모 노드가 더 작다면 교환하고 부모 노드부터 다시 비교, 힙속성을 유지할 때까지 반복함.
			while(i > 1 && arr[i/2] < arr[i]) {
				swap(arr[i/2], arr[i]);
				i = i/2;
			}
		}

		void print(){
			for(int i=0;i<size+1;i++){
				cout << arr[i] << " ";
			}

			cout << endl;
		}

		int dequeue () {
			if(size == 0) {
				printf("empty\n");
				return -1;
			}

			int temp = arr[1]; 
			arr[1] = arr[size];
			arr[size--]=0;

			// 루트 노드부터 heapify 수행
			int i = 1;
			while(i < size){
				int largest = i;  
				int left = 2*i;              //left child
				int right = 2*i +1;          //right child

				// 현재 요소 i와 자식 노드의 값을 비교
				if(left <= size && arr[left] > arr[i] )
					largest = left;  
				if(right <= size && arr[right] > arr[largest] )
					largest = right;

				cout << "교환 과정: 현재위치 i : " << i << endl;
				cout << "교환 과정: 교환할 위치 largest : " << largest << endl;

				// 자식 노드의 값이 더 크다면 교환하고 교환된 자식 노드부터 반복
				if(largest != i ) {
					swap(arr[i] , arr[largest]);
				}else break;
				i=largest;
			}

			return temp;
		}
};

int main(){
	pq p;
	p.enqueue(80);
	p.enqueue(40);
	p.enqueue(10);
	p.enqueue(100);
	p.enqueue(780);
	p.enqueue(500);
	p.enqueue(1000);
	p.print();
	p.dequeue();
	p.dequeue();
	p.print();
}

// 1.배열에 최대힙 처럼 넣어주는 함수를 만든다.
// 2.최대힙에서 삭제하는 함수를 만든다.
