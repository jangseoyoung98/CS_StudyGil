#include <iostream>
#define stack_size 4
using namespace std;

class stack { // 배열기반
	public:
		int cnt = -1;
		int arr[stack_size]={0,};

		void print(){
			for(int i=0;i<stack_size;i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		void push(int data) {
			if(cnt == stack_size-1) {
				printf("stack is full\n");
				return;
			}
			arr[++cnt] = data;
		}
		int pop() {
			if(empty()) {
				printf("stack is empty\n");
				return -1;
			}
			arr[cnt]=0;
			return arr[cnt--];
		}
		int top() {
			if(empty()) {
				printf("stack is empty\n");
				return -1;
			}
			return arr[cnt];
		}
		bool empty() {
			return cnt <= -1;
		}
};

int main(){
	stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.print();
	s.push(4);
	s.print();

	s.pop();
	s.print();

	s.push(-1);
	s.print();

	cout << s.top() << endl;
}
