/*
	https://www.acmicpc.net/problem/1504 특정 최단경로
	- 다익스트라 응용 문제(다익스트라 3번 -> 함수로 표현)
	
	1. 두정점을 거치는 1~n까지의 최단거리
	-> 1~v1, v1~v2, v2~n 까지의 최단거리를 다익스트라로 구한다.
	-> 1~v2, v2~v1, v1~n 까지의 최단거리를 다익스트라로 구한다.
	
	2. 구한 최단거리가 INF보다 크면 -1을 반환한다.
	3. 구한 최단거리가 INF보다 작으면 그값을 반환한다. 

*/
#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;

const int MAX=801;
const int INF=1e9;

int n,m;
vector<P> adj[MAX];

vector<int> dijkstra(int start,int vertex){
	vector<int> distance(vertex,INF);
	distance[start]=0;
	
	priority_queue<P,vector<P>,greater<P>> PQ;
	PQ.push({0,start});
	
	while(!PQ.empty()){
		int cost=PQ.top().first,cur=PQ.top().second;
		PQ.pop();
		
		if(distance[cur]<cost) continue;
		
		for(auto &p:adj[cur]){
			int next=p.first,d=p.second+cost;
			
			if(distance[next]>d){
				distance[next]=d;
				PQ.push({distance[next],next});
			}
		}
	}
	return distance;
}
int main(){
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int cur,next,value;cin>>cur>>next>>value;
		adj[cur].push_back({next,value});
		adj[next].push_back({cur,value});
	}
	int v1,v2;cin>>v1>>v2;
	
	vector<int> result=dijkstra(1,n+1);
	vector<int> temp1=dijkstra(v1,n+1);
	vector<int> temp2=dijkstra(v2,n+1);
	
	long long answer=min(result[v1]+temp1[v2]+temp2[n],result[v2]+temp2[v1]+temp1[n]);
	if(answer>=INF||answer<0) cout<<-1;
	else cout<<answer;

}
