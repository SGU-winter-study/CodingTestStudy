#include<bits/stdc++.h>
using namespace std;

/*bfs가 아닌척하는 전형적인 bfs문제

문제를 잘 읽어보면 a -> b로 가는 최단경로를 구하는 문제임을 파악가능하다.

전형적인 bfs와 동일한 풀이이다.

1. input을 입력받는다, 인접리스트로 정점들간의 연결여부를 저장한다.

2. Q에 집어넣고 bfs를 수행한다. dist배열을 통해 방문하지 않았으면 수행한다.

3. 결과를 출력한다 (dist를 -1로 초기화해서 방문할수 없으면 -1이 출력되도록 만듬.) 
	 
*/
int main(){
	int a,b,n,m;cin>>a>>b>>n>>m;
	vector<int> v[n+1];
	int dist[n+1];
	fill(dist,dist+n+1,-1);
	
	for(int i=0;i<m;i++){
		int c,d;cin>>c>>d;
		v[c].push_back(d);
		v[d].push_back(c);
	}
	
	queue<int> Q;
	Q.push(a);dist[a]=0;
	
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		for(int i=0;i<v[cur].size();i++){
			int next=v[cur][i];
			if(dist[next]!=-1) continue;
			Q.push(next);
			dist[next]=dist[cur]+1;
		}
	}
	cout<<dist[b];
}
