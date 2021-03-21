#include<bits/stdc++.h>
using namespace std;

int n,m;
int dx[4]={0,0,1,-1},dy[4]={-1,1,0,0};
int board[502][502],dp[502][502];

// dp[x][y]= (x,y) 지점일 때 갈 수 있는  경로의 갯수. 


int dfs(int x,int y){
//	cout<<x<<" "<<y<<"\n";
	if(x==n&&y==m) return 1;
	else if(dp[x][y]==-1){//방문하지 않은 곳. 
		dp[x][y]=0;//0으로 초기화 
		for(int dir=0;dir<4;dir++){//4 방향으로 순회 
			int nx=x+dx[dir],ny=y+dy[dir];
			if(nx>0&&nx<=n&&ny>0&&ny<=m){
				if(board[nx][ny]<board[x][y]) dp[x][y]+=dfs(nx,ny);
			}
		}
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
	cout<<dfs(1,1);
}
