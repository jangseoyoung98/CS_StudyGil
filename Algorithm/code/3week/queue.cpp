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
		int print(){
			for(int i=0;i<maxSize;i++){
				cout << queue[i] << " ";
			}
			cout << endl;
			cout << "rear : " << rear << " front : " << front << endl;
		}
};

int main(){
	queue s;

	s.Enqueue(1);
	s.Enqueue(2);
	s.Enqueue(3);
	s.Enqueue(4);
	s.Enqueue(5);
	s.print();

	s.Enqueue(6); //꽉찻 출력
								//s.print();
	s.Dequeue();
	s.print();

	s.Enqueue(-1);
	s.print();
	s.Dequeue();
	s.Dequeue();
	s.Dequeue();
	s.Dequeue();
	s.Dequeue();
	s.print();

	//cout << s.top() << endl;
}
