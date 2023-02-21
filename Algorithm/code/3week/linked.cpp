#include <iostream>
using namespace std;

//노드 struct 구현 (data값과 nextNode가 존재)
struct node {
	int data;
	node* nextNode;
};

class LinkedList {
	private:
		node* head;
		int cnt;
	public:
		LinkedList() {
			head = NULL;
			cnt = 0;
		}

		node* findNode(int n);
		void modifyNode(int n,int data);
		void deleteFrontNode();
		void addFrontNode(int data);

		node* getHead() {
			return head;
		}
		void display();
};

node* LinkedList::findNode(int n){ 
	node* t = getHead();
	int c =1;
	while(t!=NULL){
		if(c==n) return t;
		c++;
		t = t->nextNode;
	}
	return t;
}

void LinkedList::addFrontNode(int data) {
	cout << "------노드 추가 함수 -----" <<endl<<endl;
	node* temp = new node;
	temp->data = data;
	this->cnt++;

	cout << " 생성된 '"<< data <<"' 노드 주소 값: " << temp<<endl<<endl;

	//LinkedList가 비어있으면
	if (head == NULL) {
		cout << "링크드리스트에 헤드값이 없습니다. 헤드를 지정합니다 (" << temp <<")"<< endl<<endl;
		head = temp;
	}
	//LinkedList에 데이터가 있으면
	else {
		cout << "링크드리스트에 헤드의 주소값이 존재합니다. 해드 주소를 새로 생성된 노드로 대체합니다 "<<endl;
		cout << "기존 헤드의 주소 : " << head << endl;
		cout << "생성된 주소(바뀔 헤드의 주소) : " << temp << endl<<endl;
		temp->nextNode = head;
		//head는 temp
		head = temp;
	}
	cout << "------노드 추가 함수끛 -----" <<endl<<endl;
}

//node 삽입
void LinkedList::modifyNode(int n,int data) {
	cout << "--------수정 함수 호출-------" <<endl<<endl;

	node* temp = findNode(n);
	cout << "찾은 주소의 위치 : "<< temp << endl;
	temp->data = data;

	cout << "--------수정 함수 끝 -------" <<endl<<endl;
}

//node 삭제
void LinkedList::deleteFrontNode() {
	cout << "------노드 삭제 함수 -----" <<endl<<endl;
	node *temp = this->getHead();
	cout << "삭제할 노드 주소(헤더): " << temp <<endl;
	if(temp!=NULL) this->head = head->nextNode;

	delete temp;
	cout << "------노드 삭제 함수끛 -----" <<endl<<endl;
}




//메인 함수
int main() {
	LinkedList a;
	cout << "LinkedList에 데이터 추가합니다.\n";
	a.addFrontNode(10);
	a.addFrontNode(50);
	a.addFrontNode(1000);
	a.addFrontNode(-1);
	a.addFrontNode(-100);

	cout << "4번째 요소를 5로 수정\n";
	a.modifyNode(4, 5);

	//세번째 노드 삭제
	a.deleteFrontNode();
	cout << "1번째 요소를 삭제!\n";

	//해보기: "일"-0x1,"이"-0x2,"삼"-0x3,"사"-0x4라는 데이터를 4개 추가함.
	//이번엔 노드가 생성될 때마다 꼬리에다 추가하고싶음.
	//꼬리에다 추가하는 sudo코드를 작성하고
	//순회하는 주소값이랑 지정된 헤더값을 말하기
}
