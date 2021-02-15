#include<bits/stdc++.h>
using namespace std;
/*
	BOJ16562 - 친구비(U&F)
	
	같은 루트에 속하는 최소 비용을 저장. 모든 최소 비용을 더한 값이 k보다 적으면 모두 친구로 만들수 잇음. 
*/
int friends[10001],cost[10001];
bool visited[10001];
int find(int n){
	return (friends[n]==n)?n:friends[n]=find(friends[n]);
}

void u(int a,int b){
	a=find(a),b=find(b);
	if(a==b) return;
	if(a>b) swap(a,b);
	friends[b]=a;
	cost[a]=min(cost[a],cost[b]);
}

int main(){
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		friends[i]=i;
		cin>>cost[i];
	}
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		u(a,b);
	}
	
	int total=0;
	for(int i=1;i<=n;i++){
		if(!visited[find(i)]) visited[find(i)]=true,total+=cost[find(i)];
	}
	(total<=k)?cout<<total:cout<<"Oh no";
} 
