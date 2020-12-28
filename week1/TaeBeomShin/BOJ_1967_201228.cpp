#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

vector<pair <int,int> > v[10001];
bool visited[10002]={0,};
int n,mdist=0,midx;
/*
 문제접근법
 1. 루트노드에서 가장 멀리있는 노드를 구한다.(1번째 dfs 수행)
 2. 구한 노드에서 가장 먼 노드까지의 거리를 구한다.(2번째 dfs수행) 
 3. 정답을 출력한다.
 
 다른풀이 
 sol2) 다익스트라 알고리즘을 2번 수행(논리는 dfs)와 동일
 sol3) DP를 이용한 풀이 -> 아직공부필요
  
 세가지 풀이를 모두 정리해서 github 와 블로그에 정리. 
*/
void dfs(int node,int dist){
	if(visited[node]) return;
	if(dist>mdist){
		midx=node;
		mdist=dist;
	}
	visited[node]=true;
	for(int i=0;i<v[node].size();i++)
		dfs(v[node][i].first,dist+v[node][i].second);
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b,c;cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	dfs(1,0);
	fill(visited,visited+n+1,0);
	mdist=0;
	dfs(midx,0);
	cout<<mdist;
}

