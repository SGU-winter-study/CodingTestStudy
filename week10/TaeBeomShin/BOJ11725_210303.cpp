#include<bits/stdc++.h>
using namespace std;
/*
	BOJ11725 - 트리의 부모 찾기
	
	so1) BFS 이용.
	BFS를 1부터 시작해서 수행, 해당 노드 이전에 방문한 노드가 부모노드임. 
*/
int nodes[100001]={0,};
vector<int> v[100001];

int main(){
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int p,c;cin>>p>>c;
		v[p].push_back(c);
		v[c].push_back(p);		
	}
	
	queue<int> Q;
	Q.push(1);
	nodes[1]=1;
	
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		
		for(int i=0;i<v[cur].size();i++){
			int next=v[cur][i];
			if(nodes[next]>0) continue;
			nodes[next]=cur;
			Q.push(next);
		}
	}
	
	for(int i=2;i<=n;i++) cout<<nodes[i]<<"\n";
	
}
