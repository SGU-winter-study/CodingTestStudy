#include<bits/stdc++.h>
using namespace std;
/*
	BFS 문제 
	
	- 연결요소의 개수와 연결요소별 크기 구하기.
	- BFS를 반복해서 실행하여 해결
	
	* 123456를 하나씩 입력받고 싶을때 scanf("%1d",&~) 이용하기. 
*/
bool visited[25][25]={false,};
int board[25][25]={0,};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main(){
	int n;cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&board[i][j]);
		}
	}
	
	vector<int> ans;
	int dangi=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//이미 방문한 곳 
			if(visited[i][j]) continue;
			if(board[i][j]==0) continue;
			dangi++;
			
			int count=0;
			
			queue<pair<int,int> > Q;
			Q.push({i,j});
			count++;
			visited[i][j]=true;
			
			while(!Q.empty()){
				auto cur=Q.front();Q.pop();
				int cx=cur.first,cy=cur.second;
//				cout<<cx<<" "<<cy<<"\n";
				
				for(int dir=0;dir<4;dir++){
					int nx=cx+dx[dir],ny=cy+dy[dir];
					
					if(nx<0||ny<0||nx>=n||ny>=n) continue;
					if(visited[nx][ny]) continue;
					if(board[nx][ny]==0) continue;
					
					Q.push({nx,ny});
					visited[nx][ny]=true;
					count++;
				}
			}
			
			ans.push_back(count);
		}
	}
	sort(ans.begin(),ans.end());
	
	cout<<dangi<<"\n";
	
	for(int answer : ans) cout<<answer<<"\n";
	
}
