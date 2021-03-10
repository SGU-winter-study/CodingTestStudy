#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 1987 - 알파벳
	
	sol1) BFS로 접근, 같은 level에서 단어 개수 체크가 불가능해서 fail
	sol2) DFS로 접근, 같은 level이 겹치지 않아서 OK 
*/
bool check[26]={false,},visited[20][20]={false,};
int board[20][20],r,c;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int ans=0;

void dfs(int x,int y,int cnt){
	ans=max(ans,cnt);
	for(int dir=0;dir<4;dir++){
		int nx=x+dx[dir],ny=y+dy[dir];
		if(nx<0||nx>=r||ny<0||ny>=c) continue;
		if(visited[nx][ny]||check[board[nx][ny]]) continue;
//		cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<" "<<cnt<<"\n";
		
		visited[nx][ny]=true;
		check[board[nx][ny]]=true;
		
		dfs(nx,ny,cnt+1);
		
		visited[nx][ny]=false;
		check[board[nx][ny]]=false;
	}
	return;
}
int main(){
	cin>>r>>c;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			char a;cin>>a;
			board[i][j]=a-'A';
		}
	}
	
	visited[0][0]=true;
	check[board[0][0]]=true;
	dfs(0,0,1);
		
	cout<<ans;
}
