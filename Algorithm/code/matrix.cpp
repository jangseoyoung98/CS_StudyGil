#include<bits/stdc++.h>

using namespace std;


int main(){
	bool arr[10][10] = {0,};
	arr[1][2] =1;
	arr[1][3] =1;
	arr[3][4] =1;
	arr[2][1] =1;
	arr[3][1] =1;
	arr[4][3] =1;

	vector<list<int>> li;
	li[1].insert(2);
	li[1].insert(3);
	li[3].insert(4);
	li[2].insert(1);
	li[3].insert(1);
	li[4].insert(3);

}

/*
	 void bfs_visit(bool arr[][10],int v){
	 if(vv[v]==0){
	 cout << v << endl;
	 }
	 for(int i=0;i<10;i++){
	 for(int j=0;j<10;j++){
	 if(arr[i][j]==1 && vv[j]==0){
	 cout << " "<<  j << endl;
	 vv[j] = 1;
	 }
	 }
	 }
	 }
	 void bfs(bool arr[][10],int v){
	 for(int i=0;i<10;i++){
	 if(vv[i]==0){
	 cout << i << endl;
	 vv[i] = 1;
	 }else continue;
	 for(int j=0;j<10;j++){
	 if(arr[i][j]==1 && vv[j]==0){
	 cout << " "<<  j << endl;
	 vv[j] = 1;
	 }
	 }
	 }
	 }
	 int main(){
	 bool arr[10][10] = {0,};
	 arr[1][2] =1;
	 arr[1][3] =1;
	 arr[3][4] =1;
	 arr[2][1] =1;
	 arr[3][1] =1;
	 arr[4][3] =1;
	 bfs(arr,0);
	 }
	 */
