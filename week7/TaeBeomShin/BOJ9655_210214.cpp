#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 9655 ������(DP)
	 
	dp[i] = (�ش����� ���  �¸� : 1 �������� ��� �¸� :0)
	
	����̰� ù�� �̹Ƿ� dp[i-3]�� dp[i-1] �߿��� 0�� �Ǵ� ���� �����Ѵ�.
	�׷� ���� �������� ������ dp[i]=0�̴�.
	 
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
