#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std; 
/*
	다익스트라 기본구현 - 1916
	
	다익스트라 경로탐색 알고리즘 기본구현
	
	- pair<int,int> 를 P로 define해서 더 깔끔하게 코드를 작성할 수 있다.
	- for(;;)문 보다 for (:)문을 이용해서 가독성이 더 좋은 코드를 작성할 수 있다. 
*/
int main(){
	int n,m;cin>>n>>m;
	vector<P> adj[n+1];
	int dist[n+1]={0,};
	fill(dist,dist+n+1,1e9);
	bool visited[n+1]={0,};
	for(int i=0;i<m;i++){
		int curr,next,d;cin>>curr>>next>>d;
		adj[curr].push_back({next,d});
	}
	int start,end;cin>>start>>end;
	priority_queue<P,vector<P>,greater<P>> PQ;
	dist[start]=0;
	PQ.push({0,start});
	
	while(!PQ.empty()){
		int curr;
		do{
			curr=PQ.top().second;PQ.pop();
		}while(!PQ.empty()&&visited[curr]);
		if(visited[curr]) continue;
		visited[curr]=true;
		
		for(auto &p:adj[curr]){
			int next=p.first,d=p.second;
			if(dist[next]>dist[curr]+d){
				dist[next]=dist[curr]+d;
				PQ.push({dist[next],next});
			}
		}
	}
	cout<<dist[end];
}
