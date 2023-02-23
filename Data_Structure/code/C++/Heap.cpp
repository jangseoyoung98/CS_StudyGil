#include<iostream>
using namespace std;

class maxheap{
    public:
        int arr[100]={0,};
        int pos=1;
        void push(int data){
            arr[pos++]=data;
            int i=pos-1;
            while(i>1 && arr[i/2]<arr[i]){
                swap(arr[i/2],arr[i]);
                i/=2;
            }
        }
        void pop(){
            arr[1]=arr[pos--];
            int i=1;
            print();
            while(i*2<pos){
                cout << " i : "<< i << endl;
                int largest = i;
                int right=i*2+1;
                int left=i*2;
                if(arr[largest] < arr[right]) largest = right;
                if(arr[largest] < arr[left] ) largest =left;
                if(largest!=i) {
                    swap(arr[largest],arr[i]);
                    i=largest;
                }
                else break;
            }
            print();
        }
        void print(){
            for(int i=0;i<pos;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    maxheap a;
    a.push(1);
    a.push(5);
    a.push(3);
    a.push(4);
    a.push(7);
    a.pop();
}