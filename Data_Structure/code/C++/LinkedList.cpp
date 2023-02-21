#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
};


class LinkedList{
  public:
    int size=0;
    Node* head;
    
    void InsertFirst(int data){
      Node* temp = new Node;
      temp->data = data;

      if(head==NULL){
        head = temp;
      }else{
        temp->next = head;
        head = temp;
      }
      size++;
    } 
    void Delete(int n){
      int cnt=1;
      Node* temp = head;
      Node* prev = NULL;
      if(temp == NULL){
        cout << "NO data List!" << endl;
        return;
      }
      while(temp!=NULL){
        cnt++;
        if(cnt == n) break;
        prev = temp;
        temp = temp->next;
      }
      if(head == temp){
        head = temp->next;
        delete temp;
      }else{
        prev->next = temp->next;
        delete temp;
      }
      size--;
    }
    int searchNode(int n){
      Node* temp = head;
      int cnt=1;
      if(size<n && temp == NULL){
        cout << "NO data List!" << endl;
        return;
      }
      while(temp!=NULL){
        cnt++;
        if(cnt == n) break;
        temp = temp->next;
      }
      return temp->data;
    }
    void Print(){
      Node* temp = head;
      while(temp!=NULL){
        cout << temp-> data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
};