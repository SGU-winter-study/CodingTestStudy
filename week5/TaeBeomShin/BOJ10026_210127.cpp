#include<bits/stdc++.h>
using namespace std;
// bfs �� �� ����. 
char grid[101][101];
char grid2[101][101];
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
			if(grid[i][j]=='G'){
				grid2[i][j]='R';
			}else{
				grid2[i][j]=grid[i][j];
			}
		}
	}
	//grid�� grid2�� ���� ���� bfs ����. 
}
