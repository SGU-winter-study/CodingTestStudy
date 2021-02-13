#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 9655 돌게임(DP)
	 
	dp[i] = (해당턴인 사람  승리 : 1 다음턴인 사람 승리 :0)
	
	상근이가 첫턴 이므로 dp[i-3]과 dp[i-1] 중에서 0이 되는 값을 선택한다.
	그런 값이 존재하지 않으면 dp[i]=0이다.
	 
*/
int main(){
	int n;cin>>n;
	
	
	int dp[n+1]={0,1,0,1};
	
	for(int i=4;i<=n;i++){
		if(dp[i-3]==0||dp[i-1]==0) dp[i]=1;
		else dp[i]=0;
	}
	
	(dp[n]==1)?cout<<"SK":cout<<"CY"; 
} 
