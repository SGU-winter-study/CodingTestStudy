#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 20181 꿈틀꿈틀 호석벌레, 투포인터 + DP
	 
	방법 1. 탈피 에너지가 최대가되도록 하는 경우를 모두 탐색. -> 2^N 
	 -> N의 범위가 커지면 n log n 또는 O(n) 만에 해결해야함.
	 
	방법 2. 투포인터 + DP 이용. 
	-> dp[i]를 i번째까지 얻을 수 있는 최대 축적탈피에너지로 정의
	-> && k를 기준으로 투포인터를 통해 탈피에너지 합을 구함. 

*/

long long dp[100001],arr[100001]; 
int main(){
	long long n,k;cin>>n>>k;

	for(int i=1;i<=n;i++)
		cin>>arr[i];
		
	long long sum=0; 
	for(int start=0,end=1;end<=n;end++){
		sum+=arr[end];
		dp[end]=dp[end-1];
		while(sum>=k){
			dp[end]=max(dp[end],dp[start]+sum-k);
			sum-=arr[++start];
		}
	}
	cout<<dp[n];
	
}
