#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
string lcs[1001][1001];
int main(){
	string A,B;cin>>A>>B;
	
	for(int i=1;i<=A.length();i++){
		for(int j=1;j<=B.length();j++){
			if(A[i-1]==B[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				lcs[i][j]=lcs[i][j]+lcs[i-1][j-1]+A[i-1];
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(dp[i-1][j]>dp[i][j-1]){
					lcs[i][j]=lcs[i-1][j];
				}else{
					lcs[i][j]=lcs[i][j-1];
				}
			}
		}
	}
	if(dp[A.length()][B.length()])
		cout<<dp[A.length()][B.length()]<<"\n"<<lcs[A.length()][B.length()];
	else cout<<"0";
}
