#include<bits/stdc++.h>
using namespace std;
/*
	BOJ18353 - �����ġ�ϱ�(dp)
	
	���ܵǴ� ���簡 �ּҰ� �ǵ���.
	-> ���� �� �����ϴ� �κ� ����!! ���ϱ�
	
	dp[i]= i��° ������ �� ���� �� �κ� ����. 
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
