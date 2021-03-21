#include<bits/stdc++.h>
using namespace std;

int n,m,answer;
char board[502][502];
//dp[i][j]의 정의 -1 : 탐색 안해봄 0 : 밖으로 못나감 1: 밖으로 나갈 수 있음.
//i,j에서 갈 수 있는지 여부 저장 
int dp[502][502];

int dfs(int x,int y){
	
	if(x<=0||x>n||y<=0||y>m) return 1;
	if(dp[x][y]!=-1) return dp[x][y];
	
	dp[x][y]=0;
	
	if(board[x][y]=='U'){
		dp[x][y]=dfs(x-1,y);
	}else if(board[x][y]=='R'){
		dp[x][y]=dfs(x,y+1);
	}else if(board[x][y]=='D'){
		dp[x][y]=dfs(x+1,y);
	}else if(board[x][y]=='L'){
		dp[x][y]=dfs(x,y-1);
	}
	return dp[x][y];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>board[i][j];
			dp[i][j]=-1;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			answer+=dfs(i,j);
		}
	}
	cout<<answer<<"\n";
}
