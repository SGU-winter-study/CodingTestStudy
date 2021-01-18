#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int room[51][51]={0,};
int main(){
	int r,c,t;cin>>r>>c>>t;
	
	vector<P> cleaner;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			cin>>room[i][j];
			if(room[i][j]==-1) cleaner.push_back({i,j});
		}
	
	
	while(t--){
		vector<P> dust;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(room[i][j]>0) dust.push_back({i,j});
		
		/*
		1.미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다-> 새로 확산된 칸에바로 들어가지 않는다. 
		 -(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
	 	*/		
		int size=dust.size();
		for(int i=0;i<size;i++){
			auto cur=dust[i];
			int curx=dust[i].first,cury=dust[i].second;
			int count=0;
			for(int dir=0;dir<4;dir++){
				int nx=curx+dx[dir],ny=cury+dy[dir];
				//-인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
				if(nx<0||ny<0||nx>r||ny>c) continue;
				if(room[nx][ny]==-1) continue;
				room[nx][ny]+=room[curx][cury]/5;
				count++;
			}
			room[curx][cury]-=room[curx][cury]/5*count;
		}
		/*
			2.공기청정기가 작동한다.
			-위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
		*/
		int x=cleaner[0].first, y=clearn[0].second;
		
	}
}
