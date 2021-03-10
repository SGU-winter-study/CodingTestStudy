#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 11054 - DP(2개의 dp) 
	
	dp[i]는 i를 포함한 1~i까지의 증가하는 가장 긴 부분수열의 길이
	dp2[i]는 i를 포함한 i~n까지의 감소하는 가장 긴 부분수열의 길이
	
	이다.   
*/
int dp[1001],dp2[1001],A[1001];
int main(){
	int n;cin>>n;
	
	for(int i=1;i<=n;i++) cin>>A[i];
	
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<=i;j++){
			if(A[j]<A[i]) dp[i]=max(dp[i],dp[j]+1);
		}
	}

	int ans=0;
	for(int i=n;i>=1;i--){
		dp2[i]=1;
		for(int j=n;j>=i;j--){
			if(A[j]<A[i]) dp2[i]=max(dp2[i],dp2[j]+1);
		}
		ans=max(ans,dp[i]+dp2[i]-1);
	}
	cout<<ans;
}
