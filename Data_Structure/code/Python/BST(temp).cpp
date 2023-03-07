#include <iostream>
using namespace std;

// 노드 - 구조체
struct Node {
    int data;
    Node* leftchild = NULL;
    Node* rightchild = NULL;
};

// 트리 - 클래스
class BST {
public:
    Node* root = NULL;
    int cnt = 0;

    void insert(int data);
    Node* find(int data, Node* parPos);
    void deleteNode(int data);

    void travelBST();
    void travelBSTNode(Node* temp);
};

void BST::insert(int data){
    // 1. 동일한 data 값을 가진 노드가 있는지 탐색한다. -> 있으면 실패 반환
    Node* parPos = root;
    Node* temp = this->find(data, parPos);
    if(temp != NULL){
        cout << data + "값을 가진 노드가 이미 있습니다.\n";
        return;
    }

    // 2. (없다는 전제 하에) 새로운 노드를 만들어서 data를 담는다.
    Node* newNode = new Node();
    newNode->data = data;
    
    // case 1) 빈 트리인 경우 -> 새 노드를 루트와 연결한다.
    if(parPos == NULL){
        this->root = newNode;
        cout << "삽입 성공!" << endl;
        return;
    }
    // case 2) 빈 트리가 아닌 경우 -> parPos의 노드보다 작은지 큰지 판단해서 연결될 위치를 찾고, 넣는다.
    // ※ 삽입은 항상 리프노드로 들어간다!
    if(data < parPos->data){
        parPos->leftchild = newNode;
    }
    else { // data > parPos->data
        parPos->rightchild = newNode;
    }
    cout << "삽입 성공!" << endl;

    (this->cnt)++;
};

// find() -> input : data / output : Node*(해당 data를 가진 노드의 위치)
// Node* BST::find(int data){
//     // 1. 루트 노드를 받아와서 준비를 마친다.
//     Node* temp = root;
//     // 2. 루트부터 아래로 내려가면서, 해당 데이터가 있는지 찾는다.
//     do{
//         if(data == temp->data){  // 3. 있다면, 그 위치를 반환한다.
//             cout << data + "를 가진 노드를 찾았습니다!\n";
//             return temp;
//         } 
//         else if(data < temp->data){
//             temp = temp->leftchild;
//         }
//         else { // data > temp->data
//             temp = temp->rightchild;
//         }
//     } while(temp != NULL);
//     // temp == NULL
//     // 노드를 못 찾은 경우 + 루트 노드가 없는 경우(즉, 빈 트리인 경우) -> NULL을 반환한다.
//     cout << data + "를 가진 노드가 없습니다!\n";
//     return NULL;
// };

// find 함수2 (부모의 위치도 함께 반환)
// input : data, parPos(부모의 위치를 받아올 포인터 변수) / output : Node*(동일한 데이터를 가진 노드의 위치)
Node* BST::find(int data, Node* parPos){
    // 1. 루트 노드를 받아와서 준비를 마친다.
    Node* temp = root;
    
    // 2. 루트부터 아래로 내려가면서, 해당 데이터가 있는지 찾는다. + temp가 옮겨가기 전, parPos에 temp를 담는다.
    do{
        if(data == temp->data){  // 3. 있다면, 그 위치를 반환한다.
            cout << data + "를 가진 노드를 찾았습니다!\n";
            return temp;
        } 
        else if(data < temp->data){
            parPos = temp;
            temp = temp->leftchild;
        }
        else { // data > temp->data
            parPos = temp;
            temp = temp->rightchild;
        }
    } while(temp != NULL);

    // temp == NULL
    // 노드를 못 찾은 경우 + 루트 노드가 없는 경우(즉, 빈 트리인 경우) -> NULL을 반환한다.
    cout << data + "를 가진 노드가 없습니다!\n";
    return NULL;
};

void BST::deleteNode(int data){
    // 1. 해당 data를 가진 노드가 BST에 있는지 찾는다.
    // 없으면 -> 에러메시지 출력
    Node* parPos = NULL;
    Node* temp = this->find(data, parPos);
    if(temp == NULL){
        cout << data + "를 가진 노드가 없습니다.\n";
        return;
    }
    
    // 2. (있다는 전제 하에)
    // case 1) 루트노드 or 리프노드인 경우
    // 그냥 삭제한다.
    if(temp->leftchild == NULL && temp->rightchild == NULL){
        delete temp;
        cout << "삭제 완료!" << endl;
        return;
    }

    // 왼쪽(오른쪽 NULL) / 오른쪽(왼쪽 NULL) / 둘 다(둘 다 != NULL)
    // case 2) 인터널노드인 경우 - 자식이 1개일 때
    // 해당 노드를 삭제하고
    // 그 노드의 부모와 그 노드의 자식을 연결한다.
    if(temp->rightchild == NULL){ // 왼쪽에 연결
        if(parPos->leftchild == temp) parPos->leftchild = temp->leftchild;
        else parPos->rightchild = temp->leftchild;
        delete temp;
    }
    else if(temp->leftchild == NULL) { // 오른쪽에 연결
        if(parPos->leftchild == temp) parPos->leftchild = temp->rightchild;
        else parPos->rightchild = temp->rightchild;
        delete temp;
    }

    // case 3) 인터널노드인 경우 - 자식이 2개일 때
    // 해당 노드를 삭제하고
    // 오른쪽 서브트리에서 가장 작은 노드를 붙인다.
    else{
        Node* min = temp;
        while(min->leftchild != NULL){
            min = temp->leftchild;
        }
        temp->data = min->data;
        delete min;
    }

    cout << "삭제 완료!" << endl;

    (this->cnt)--;
};

// ▼ 아래는 이후에..!
// 전위 순회 (루트노드 - 왼쪽 - 오른쪽)
void BST::travelBST(){
    Node* temp = root;
    Node* parent = root;
    // 반복 1 - do while
    // 1. 루트노드를 일단 ★출력★하고
    // 2. 왼쪽 서브트리가 NULL이 나올 때까지 내려간다.
    // NULL이 나올 때까지 내려가면서 해당 노드를 ★출력★한다.
    // 반복 2 - 
    // 3. 오른쪽 서브트리로 이동해서 ★출력★한다.

    for(int i = 0; i < cnt; i++){
    // temp->right
    while(true){
        if(temp->leftchild == NULL){
            cout << temp->data + "\t";
            i++;
            break;
        }
        cout << temp->data + "\t";
        i++;
        temp = temp->leftchild;
    } 
    cout << (temp->rightchild)->data;
    i++;
    }


};

void BST::travelBSTNode(Node* temp){

}

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




