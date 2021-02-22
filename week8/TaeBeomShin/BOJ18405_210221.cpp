#include<bits/stdc++.h>
using namespace std;
/*
	BOJ18405 - ������ ����.
	 
	so1)���ڷ� ���� �̿�.
	
	�ּ��� �ִ��� -> ����ġ�� ������ �ٲٰų� ����� �ٲ��ָ� greater,less ���Ǿ��� ���ϰ� ����.
	������ ���� ���ڸ��� ���ĵȴٴ� ��ǿ� ������ ��. 
	
	sol2)ť ����
	���̷��� ������ŭ�� 2���� ���� ������ ����, �̸� ť�� �������.
	
	ó�� �����ؼ� ������ ���Ŀ��� ������ ��ȣ�� ���� �ͺ��� ���� ó����.
	
	���� ����. 
*/
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	int board[n][n]={0,};
	int count=0; 
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>> PQ;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
			if(board[i][j]>=1){
				PQ.push({-board[i][j],{i,j}});
			}
		}
	}
		
	int s,x,y; cin>>s>>x>>y;
	
	for(int i=0;i<s;i++){
	//�ð��� �帧.
		priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>> Q;
		int count=PQ.size();
		while(count--){
			auto cur=PQ.top();PQ.pop();
			int virus=-cur.first;
			int curx=cur.second.first,cury=cur.second.second;
			
			for(int dir=0;dir<4;dir++){
				int nx=curx+dx[dir],ny=cury+dy[dir];
				if(nx<0||nx>=n||ny<0||ny>=n) continue;
				if(board[nx][ny]!=0) continue;
				board[nx][ny]=virus;
				Q.push({-virus,{nx,ny}});
			}
		}
		
		while(!Q.empty()){
			auto cur=Q.top();Q.pop();
			int virus=cur.first;
			int nx=cur.second.first,ny=cur.second.second;
			PQ.push({virus,{nx,ny}});
		}
	}
	
	cout<<board[x-1][y-1];
}
