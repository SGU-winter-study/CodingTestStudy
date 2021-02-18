#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	int indegree[32000];
	vector<int> adj[32000];
	
	for(int i=0;i<m;i++){
		int prev,curr;cin>>prev>>curr;
		indegree[curr-1]++;// indegree 증가. 
		adj[prev-1].push_back(curr-1);// 인접리스트에 삽입. 
	}
	
	queue<int> Q;
	for(int i=0;i<n;i++)
		if(indegree[i]==0) Q.push(i);
	
	int result[32000];
	for(int i=0;i<n;i++){
		if(Q.empty()){
			puts("0");
			return 0;
		}
		
		int curr=Q.front();Q.pop();
		result[i]=curr+1;
		
		for(int next : adj[curr])
			if(--indegree[next]==0) Q.push(next);
	}
	
	for(int i=0;i<n;i++)
		cout<<result[i]<<" ";
} 
