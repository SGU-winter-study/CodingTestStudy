#include<bits/stdc++.h>
#define INF 1e6
using namespace std;

/*
	BOJ 2458 키 순서 (플로이드 와샬 응용) 
	a->b인 경로나 b->a 인 경로가 모든 정점에 대해 존재하는 경우
	
	자신의 키가 몇번째 인지 알 수 있음. 
*/
int main(){
	int n,m;cin>>n>>m;
	
	int dist[n][n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dist[i][j]=INF;
			
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a-=1;b-=1;
		dist[a][b]=1;
	}
	
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j]>=INF) dist[i][j]=0;
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		int count=0;
		for(int j=0;j<n;j++){
			if(dist[i][j]!=0||dist[j][i]!=0) count++;
		}
		if(count==n-1) ans++;
	}
	cout<<ans;
} 
