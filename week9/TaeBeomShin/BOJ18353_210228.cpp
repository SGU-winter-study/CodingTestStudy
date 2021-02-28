#include<bits/stdc++.h>
using namespace std;
/*
	BOJ18353 - 병사배치하기(dp)
	
	열외되는 병사가 최소가 되도록.
	-> 가장 긴 감소하는 부분 수열!! 구하기
	
	dp[i]= i번째 수까지 중 가장 긴 부분 수열. 
*/
int dp[2001]={0,};
int arr[2001]={0,};
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		dp[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(arr[i]<arr[j]) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	
	cout<<n-ans;
}
