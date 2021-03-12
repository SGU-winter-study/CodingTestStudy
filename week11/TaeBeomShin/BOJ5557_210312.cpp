#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 5557 - 1학년
	
	- dfs로 하면 시간초과(2^99)
	- n범위가 너무 크고, 규칙이 있을 것 같을 땐 dp를 쓰자..
	
	dp[i][j]= i번째 수까지 사용했을때 j값이 되는 수. 
*/
int n;
long long num[101];
long long dp[101][21];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	
	dp[1][num[1]]++;
	for(int i=2;i<=n-1;i++){
		for(int j=0;j<=20;j++){
			if(dp[i-1][j]==0) continue;
			if(j+num[i]<=20) dp[i][j+num[i]]+=dp[i-1][j];
			if(j-num[i]>=0) dp[i][j-num[i]]+=dp[i-1][j];
		}
	}
	
	cout<<dp[n-1][num[n]];
} 
