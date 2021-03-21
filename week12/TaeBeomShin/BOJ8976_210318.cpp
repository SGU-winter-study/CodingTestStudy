#include<bits/stdc++.h>
using namespace std;

char board[9][9];
int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};
int ans=0;
void ansCount(int x,int y){
	for(int dir=0;dir<8;dir++){
		int nx=x+dx[dir],ny=y+dy[dir],cnt=0;
		bool flag=false;
		if(nx<=0||nx>8||ny<=0||ny>8) continue;
		if(board[nx][ny]!='W') continue;
		while(nx>0&&nx<=8&&ny>0&&ny<=8&&board[nx][ny]=='W'){
			cnt++;
			nx+=dx[dir];ny+=dy[dir];
			if(board[nx][ny]=='B'){
				flag=true;
				break;
			}
		}
		if(flag) ans+=cnt;
	}
}
int main(){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			cin>>board[i][j];
		}
	}
	
	int result=0;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(board[i][j]!='.') continue;
			ansCount(i,j);
			result=max(ans,result);
//			cout<<i<<" "<<j<<" "<<ans<<"\n";
			ans=0;
		}
	}
	cout<<result;
}
