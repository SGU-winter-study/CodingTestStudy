#include<bits/stdc++.h>
using namespace std;
/*
	BOJ11437 (BFS 응용)
	
	1. 각 노드들의 depth를 구한다.
	2. 주어진 두 노드에서 parents를 거슬러 올라가며 LCA를 구한다. 
*/
int parents[50001],depth[50001];
vector<int> adj[50001];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	queue<int> Q;
	Q.push(1);
	depth[1]=1;

	//각각의 깊이를 저장한다. 
	while(!Q.empty()){

		int cur=Q.front();Q.pop();
		
		for(int i=0;i<adj[cur].size();i++){
			int next=adj[cur][i];
			if(depth[next]>0) continue;
			Q.push(next);
			depth[next]=depth[cur]+1;
			parents[next]=cur;
		}
	}
		
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		
		if(depth[a]<depth[b]) swap(a,b);
		
		while(depth[a]!=depth[b]) a=parents[a];

		while(a!=b){
			a=parents[a];
			b=parents[b];
		}
		cout<<a<<"\n";	
	}
}
	
