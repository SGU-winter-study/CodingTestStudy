#include<bits/stdc++.h>
#define INF 1e7
using namespace std;
/*
	BOj 1261 - �˰���(���ͽ�Ʈ�� �˰���)
	
	���ڿ��� �̵��ϸ鼭 ���������� ���ͽ�Ʈ�� �˰����� �����Ѵ�.
	
	������ ���������� ����� 1��ŭ ��� ���̰�, �׷��� ������ ����� ���� �ʴ´�.
	
	������ �ݺ��ؼ� dist[n-1][m-1] ���� ����Ѵ�. 
*/
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int board[101][101],dist[101][101];
int main(){
	int n,m;cin>>n>>m;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			scanf("%1d",&board[i][j]);
			dist[i][j]=INF;
		}
	
	queue<pair<int,int>> Q;
	Q.push({0,0});
	dist[0][0]=0;
	
	int ans=0; 
	while(!Q.empty()){
		int x=Q.front().first,y=Q.front().second;
		Q.pop();
		
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			
			if(nx<0||ny<0||nx>=m||ny>=n) continue;
			if(board[nx][ny]==1){
				if(dist[nx][ny]>dist[x][y]+1){//�湮�� ���� ���ų� �ִܰŸ��� �ƴ�. 
					dist[nx][ny]=dist[x][y]+1;
					Q.push({nx,ny});
				}
			}else{
				if(dist[nx][ny]>dist[x][y]){
					dist[nx][ny]=dist[x][y];
					Q.push({nx,ny});
				}
			}
		}
	}

	cout<<dist[m-1][n-1];
}
