#include<bits/stdc++.h>
using namespace std;

/*
	BOJ 11780 - 플로이드 2 (플로이드 와샬 + 경로 저장)
	
	- 기본 플로이드 와샬 + 갱신될 때 마다 경로 저장.(3차원 벡터 이용0 
	이때 i ->k -> j 로 갱신 되었을시 i->k k->j 인 경로가 바뀔수 있으므로 유의해서 저장. 
*/
int dist[101][101]={0,};
vector<int> v[101][101];

int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			dist[i][j]=(i==j)?0:1e9;
			v[i][j].push_back(i);
			v[i][j].push_back(j);
		}
			
		
	
	for(int i=0;i<m;i++){
		int start,next,weight;
		cin>>start>>next>>weight;
		dist[start-1][next-1]=min(dist[start-1][next-1],weight);
	}
	
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					v[i][j].clear();
					v[i][j]=v[i][k];
					for(int s=1;s<v[k][j].size();s++)
						v[i][j].push_back(v[k][j][s]);
				}			
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j]==0){
				cout<<"0\n";
				continue;
			}
			cout<<v[i][j].size()<<" ";
			for(int k=0;k<v[i][j].size();k++) cout<<v[i][j][k]+1<<" ";
			cout<<"\n";
		}
	}
}
