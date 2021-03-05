#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 1005 - ACM Craft(위상정렬)
	
	위상정렬을 수행하면서, 가장 오래 걸리는 시간을 저장한다.
	
	위상정렬을 끝내고, 타겟 노드의 시간을 출력한다. 
*/
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	
	int n,m;
	while(t--){
		cin>>n>>m;
		int times[n+1]={0,},indegree[n+1]={0,},mt[n+1]={0,};
		bool visited[n+1]={0,};
		vector<int> adj[n+1];
		
		for(int i=1;i<=n;i++) cin>>times[i];
		for(int i=1;i<=m;i++){
			int u,v;cin>>u>>v;
			adj[u].push_back(v);
			indegree[v]++;
		}
		int target;cin>>target;
		
		queue<int> Q;
		//indegree가 0인 정점 삽입. 
		for(int i=1;i<=n;i++){
			if(indegree[i]==0){
				Q.push(i);
				mt[i]=times[i];
				visited[i]=true;
			}
		}
		while(!Q.empty()){
			int cur=Q.front();Q.pop();
			int vertex=cur,curtime=mt[cur];
			
			for(int i=0;i<adj[cur].size();i++){
				int next=adj[cur][i];
				mt[next]=max(mt[next],times[next]+curtime);
				indegree[next]--;
			}
			
			for(int i=1;i<=n;i++){
				if(indegree[i]==0&&!visited[i]){
					Q.push(i);
					visited[i]=true;
				}
			}
		}
		cout<<mt[target]<<"\n";
	}
}
