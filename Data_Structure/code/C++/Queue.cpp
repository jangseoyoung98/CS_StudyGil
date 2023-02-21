#include <iostream>
using namespace std;
const int maxSize = 5;

class queue
{
	public:
		int front = 0, rear = 0;
		int cnt=0;
		int queue[maxSize] ={0,};
		void Enqueue(int t){
			if (cnt==maxSize)
			{
				cout << "큐가 꽉찼습니다" << endl;
				return;
			}
			cnt++;
			queue[rear] = t;
			rear = (rear+1)%maxSize;
		}
		int Dequeue(){    
			if (cnt!=0){
				cnt--;
				int temp = queue[front];
				queue[front]=0;
				front = (front+1)%maxSize;
				return temp;
			}
			return -1; //데이터 없음
		}
        bool IsFull(){
            return ((rear+1) % maxSize == front);
        }
        bool isEmpty() {
            return front == rear;
        }
};