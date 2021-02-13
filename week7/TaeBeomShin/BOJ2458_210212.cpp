#include<bits/stdc++.h>
#define INF 1e6
using namespace std;

/*
	BOJ 2458 Ű ���� (�÷��̵� �ͼ� ����) 
	a->b�� ��γ� b->a �� ��ΰ� ��� ������ ���� �����ϴ� ���
	
	�ڽ��� Ű�� ���° ���� �� �� ����. 
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
