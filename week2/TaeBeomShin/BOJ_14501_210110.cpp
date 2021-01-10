#include<bits/stdc++.h>
using namespace std;
/*
	sol1) 동적프로그래밍
	i날에 일을 할 때와 일을 하지 않을 때를 나누어서 생각.
	1. 일을 하는 경우
		i+T[i]<=n+1일 때, i날에 일을 할 수 있음. -> dp[i+T[i]]=max(dp[i]+P[i],dp[i+T[i]]
	2. 일을 하지 않는 경우
		다음날로 넘어간다. 
*/
int T[17]={0,};
int P[17]={0,};
int dp[17]={0,};
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>T[i]>>P[i];
	
	for(int i=1;i<=n;i++){
		if(i+T[i]<=n+1) 
			dp[i+T[i]]=max(dp[i]+P[i],dp[i+T[i]]);
		dp[i+1]=max(dp[i+1],dp[i]);
	}
	
	int maxn=0;
	for(int i=1;i<=n+1;i++)
		if(dp[i]>maxn) maxn=dp[i];
	
	cout<<maxn;
} 
