#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* left = NULL;
		Node* right = NULL;

		Node(int _data, Node* _leftChild, Node* _rightChild)
			:data(_data), left(_leftChild), right(_rightChild)
		{ }
};

class BST{
	public:
		Node* root=NULL;

		void addNode(int value){
			Node *temp = new Node();
			temp->data = value;
			if(root==NULL) root = temp;
			else{
				Node* ptr = root;
				while(ptr != NULL){
					if(temp->value < ptr->value){
						ptr = ptr->left;
					}else{
						ptr = ptr->right;
					}
				}
				if(temp->value < ptr->value)
					ptr->left = temp;
				else
					ptr->right=temp;
			}
		}

		void removeNode(int value){
			//Search Process
			Node* temp=root;
			while(temp != NULL){
				if(temp->value == value){
					cout << " find value : " << temp->value << endl;
					break;
				}
				else if(temp->value > value)
					temp = temp->left;
				else temp = temp->right;
			}
			if(temp ==NULL) {
				cout << "no data" << endl;
				return;
			}

			queue<Node*> q;
			q.push(root);

			Node* front = nullptr;

			//삭제 프로세스
			while(!q.empty()){
				front = q.front();q.pop();
				if(front->left){
					q.push(front->left);
				}
				if(front->right){
					q.push(front->right);
				}
				delete front;
			}
			root = nullptr;
		}
