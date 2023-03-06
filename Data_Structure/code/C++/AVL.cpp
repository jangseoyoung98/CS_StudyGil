#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* leftchild=NULL;
	Node* rightchild=NULL;  
};

class AVL{
	public:
		Node* root=NULL;
		int cnt=0;
		void insert(int data){
			if(find(data)!=NULL) {
				cout << "duplicate data!!" << endl;
				return;
			}
			Node* inode = new Node();
			inode->data = data;
			if(root==NULL){
				root= inode;
				return;
			}
			Node* temp = root;
			while(temp!=NULL){
				if(temp->data < data){
					if(temp->rightchild == NULL){
						temp->rightchild = inode;
						break;
					}
					temp = temp->rightchild;
				}else if(temp->data > data){
					if(temp->leftchild == NULL){
						temp->leftchild = inode;
						break;
					}
					temp = temp->leftchild;
				}
			}
			//끝에 삽입 완료됨 밸런스 체크
			travelBST();
		}
		Node* find(int data){
			Node* temp = root;
			while(temp!=NULL){
				if(temp->data < data){
					temp= temp->rightchild;
				}else if(temp->data > data){
					temp = temp->leftchild;
				}else return temp;
			}
			return NULL;
		}
		void deleteNode(int data){
			if(find(data)==NULL) {
				cout << "no delete data!!" << endl;
				return;
			}

			Node* temp = root;
			Node* parent = NULL;

			while(temp!=NULL){
				if(temp->data < data){
					parent=temp;
					temp= temp->rightchild;
				}else if(temp->data > data){
					parent=temp;
					temp = temp->leftchild;
				}else break;
			}

			//삭제노드의 자식이 없을 때
			if(temp->leftchild==NULL &&temp->rightchild==NULL){
				if(temp==root){
					root =NULL;
				}else if(parent->leftchild==temp) parent->leftchild=NULL;
				else parent->rightchild=NULL;

				delete temp;

			}else if(temp->leftchild!=NULL && temp->rightchild!=NULL){ //자식이 2개일 때.
				Node* minnode = temp->rightchild; //오른쪽에서 가장 작은값 찾음
				Node* parentmin=temp;

				while(minnode->leftchild!=NULL){
					parentmin=minnode;
					minnode = minnode->leftchild;
				}

				if(parentmin->rightchild==minnode){
					parentmin->rightchild=minnode->rightchild;
				}else parentmin->leftchild = minnode->rightchild;

				if(temp!=root){
					if(parent->leftchild==temp){
						parent->leftchild = minnode;
					}else{
						parent->rightchild = minnode;
					}
				}else{
					root = minnode;
				}

				minnode->leftchild = temp->leftchild;
				minnode->rightchild = temp->rightchild;
				delete temp;

			}else{ //삭제 노드의 자식이 1개 일때.
				if(temp==root){
					if(temp->leftchild) root = temp->leftchild;
					else root = temp->rightchild;
				}
				else if(parent->leftchild == temp){
					if(temp->leftchild) parent->leftchild = temp-> leftchild;
					else parent->leftchild = temp-> rightchild;
				}else{
					if(temp->leftchild){
						parent->rightchild = temp-> leftchild;
					}
					else parent->rightchild = temp-> rightchild;
				}

				delete temp;
			}
		}

		void travelBST(){
			travelBSTNode(root);
		}
		void travelBSTNode(Node* temp){



			if(temp->leftchild!=NULL){
				travelBSTNode(temp->leftchild);
			}
			int curbf= getBF(temp);
			cout << "temp : " << temp->data << " curbf : " <<  curbf<<endl;
			if(curbf<-1){//rl? rr?
				if(-1==getBF(temp->rightchild)){
					cout << "RR 밸런스 패치 일어남!! temp data : " << temp -> data << endl;
					RRCase(temp);
				}else{
					cout << "RL 밸런스 패치 일어남!! temp data : " << temp -> data << endl;
					RLCase(temp);
				}
			}else if(curbf>1){ //ll? lr?

				if(1==getBF(temp->leftchild)){
					cout << "LL 밸런스 패치 일어남!! temp data : " << temp -> data << endl;
					LLCase(temp);
				}else{
					cout << "LR 밸런스 패치 일어남!! temp data : " << temp -> data << endl;
					LRCase(temp);
				}
			}

			if(temp->rightchild!=NULL){
				travelBSTNode(temp->rightchild);
			}

		}

		int getdepth(Node* cur){
			if(cur==NULL) return 0;
			int depth=1;
			if(cur->leftchild==NULL && cur->rightchild==NULL){
				return 1;
			}else if(cur->rightchild){
				depth+=getdepth(cur->rightchild);
			}else if(cur->leftchild){
				depth+=getdepth(cur->leftchild);
			}
			return depth;
		}
		int getBF(Node* cur){
			if(cur==NULL) return 0;
			int left=0,right=0;
			if(cur->leftchild!=NULL){
				left=getdepth(cur->leftchild);
			}
			if(cur->rightchild!=NULL){
				right=getdepth(cur->rightchild);
			}
			return left-right;
		}

		void RightRotation(Node* z){
			bool sig=false;
			if(z==root) sig=true;
			Node* y = z->leftchild;
			Node* x = y->leftchild;

			Node* temp = y->rightchild;
			y->rightchild = z;
			z->leftchild = temp;
			if(sig) root=y;
		}
		void LeftRotation(Node* z){
			bool sig=false;
			if(z==root) sig=true;
			Node* y = z->rightchild;
			Node* x = y->rightchild;


			Node* temp = y->leftchild;
			y->leftchild = z;
			z->rightchild = temp;
			if(sig) root=y;
		}

		void LLCase(Node* cur){
			RightRotation(cur);
		}
		void RRCase(Node* cur){
			LeftRotation(cur);
		}
		void LRCase(Node* cur){
			LeftRotation(cur->leftchild);
			RightRotation(cur);
		}
		void RLCase(Node* cur){
			RightRotation(cur->rightchild);
			LeftRotation(cur);
		}

		void printOrder(Node* temp){
			if(temp->leftchild!=NULL){
				printOrder(temp->leftchild);
			}
			cout << temp->data << " ";
			if(temp->rightchild!=NULL){
				printOrder(temp->rightchild);
			}
		}
		void print(){
			printOrder(root);
		}
};

int main(){
	AVL bst;
	bst.insert(7);
	bst.insert(3);
	bst.insert(1);
	bst.insert(4);
	bst.insert(8);
	bst.insert(10);
	bst.print();
	cout << endl;
	return 0;
}
