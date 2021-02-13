#include<bits/stdc++.h>
using namespace std;
/*
	BOJ14503 -  로봇청소기
	
	로직은 바로 짰는데 좌표 처리를 이상하게 해서 개수가 안맞게나옴..
	
	좌표처리 연습해야할듯. 
*/
int board[51][51]={0,};
bool visited[51][51]={0,};

//0:북쪽 1:서쪽 2:남쪽 3:동쪽 기준으로의 왼쪽방향. 
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int main(){
	int n,m;cin>>n>>m;
	
	//r: 북쪽으로 부터 떨어진 칸의 개수, c: 서쪽으로 부터 떨어진 칸의 개수. 
	int x,y,d;cin>>x>>y>>d;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>board[i][j];
		}
	}
	
	while(true){
		bool flag=false;
		visited[x][y]=true;
		
		//2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
		int count=0;
		
		for(int i=0;i<4;i++){
			d =(d==0)?d=3:d-1;
			int nx=x+dx[d],ny=y+dy[d];
			count++;
			//2-1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
			if(!visited[nx][ny]&&board[nx][ny]==0){// 청소하지 않은 공간이 존재하면.0
				x=nx;y=ny;//한칸 전진 
				break; 
			}
		}
		if(count==4&&visited[x][y]==true){//네방향 모두 못 가므로 좌표가 그대로임. 	
			//바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
			x=x-dx[d];y=y-dy[d];
			if(board[x][y]){
			//뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
				flag=true;
			}
		}
		if(flag) break;
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]) ans++;
		}
	}
	cout<<ans;
}
