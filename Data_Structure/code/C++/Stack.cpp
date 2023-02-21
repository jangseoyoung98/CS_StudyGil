#include <iostream>
#define stack_size 100
using namespace std;
 
struct st { // 배열기반
    int cnt = -1;
    int arr[stack_size];
    void push(int data) {
        if (cnt == stack_size-1) {
            printf("stack is full\n");
            return;
        }
        arr[++cnt] = data;
    }
    int pop() {
        if (IsEmpty()) {
            printf("stack is empty\n");
            return -1;
        }
        return arr[cnt--];
    }
    int top() {
        if (IsEmpty()) {
            printf("stack is empty\n");
            return -1;
        }
        return arr[cnt];
    }
    bool IsEmpty() {
        return cnt <= -1;
    }
    bool IsFull(){
      return cnt==stack_size-1;
    }
};