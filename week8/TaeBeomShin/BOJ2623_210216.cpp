#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	int indegree[1000]={0,};
	vector<int> adj[1000];
	
	//정점과 연결여부를 입력받는다. 
	for(int i=0;i<m;i++){
		int num;cin>>num;
		int prev,curr;
		if(num==0) continue;
		
		cin>>prev;
		for(int i=1;i<num;i++){
			cin>>curr;
			indegree[curr-1]++;
			adj[prev-1].push_back(curr-1);
			prev=curr;
		}
	}
	
	int result[1000];
	queue<int> Q;
	for(int i=0;i<n;i++)
		if(indegree[i]==0) Q.push(i);
	
	for(int i=0;i<n;i++){
		if(Q.empty()){
		//정렬이 불가능함. 
			puts("0");
			return 0;
		}
		int curr=Q.front();
		Q.pop();
		result[i]=curr+1;
		for(int next : adj[curr])
			if(--indegree[next]==0) Q.push(next);
	}
	
	for(int i=0;i<n;i++)
		cout<<result[i]<<"\n";
}
