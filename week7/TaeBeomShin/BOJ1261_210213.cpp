#include<bits/stdc++.h>
#define INF 1e7
using namespace std;
/*
	BOj 1261 - 알고스팟(다익스트라 알고리즘)
	
	격자에서 이동하면서 순차적으로 다익스트라 알고리즘을 적용한다.
	
	벽으로 막혀있으면 비용이 1만큼 드는 것이고, 그렇지 않으면 비용이 들지 않는다.
	
	과정을 반복해서 dist[n-1][m-1] 값을 출력한다. 
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
				if(dist[nx][ny]>dist[x][y]+1){//방문한 적이 없거나 최단거리가 아님. 
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
