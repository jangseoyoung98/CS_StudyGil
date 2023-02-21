#include<bits/stdc++.h>

using namespace std;

bool visit[10]={0,};
bool arr[10][10] = {0,};

void bfs_visit(int from){
	visit[from] =1;
	cout << "from : "<< from << endl;
	for(int i=0;i<10;i++){
		if(visit[i]) continue;
		if(arr[from][i]) bfs_visit(i);
	}
	return;
}

int main(){
	arr[1][2] =1;
	arr[1][3] =1;
	arr[3][4] =1;
	arr[2][1] =1;
	arr[3][1] =1;
	arr[4][3] =1;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(arr[i][j] && visit[i]==0) bfs_visit(i);
		}
	}
}
