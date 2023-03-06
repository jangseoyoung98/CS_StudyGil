#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* leftchild=NULL;
	Node* rightchild=NULL;  
};

class BST{
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
			cout << temp-> data << " ";
			if(temp->rightchild!=NULL){
				travelBSTNode(temp->rightchild);
			}

			if(temp->leftchild!=NULL){
				travelBSTNode(temp->leftchild);
			}
		}
};

int main(){
	BST bst;
	bst.insert(7);
	bst.insert(3);
	bst.insert(8);
	bst.insert(1);
	bst.insert(5);
	bst.insert(4);
	bst.insert(10);
	bst.travelBST();
	cout << endl;

	bst.deleteNode(6);
	bst.deleteNode(5);
	bst.travelBST();
	cout << endl;

	bst.deleteNode(3);
	bst.travelBST();
	cout << endl;

	bst.deleteNode(7);
	bst.travelBST();
	cout << endl;

	return 0;
}
