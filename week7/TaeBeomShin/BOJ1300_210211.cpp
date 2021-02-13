#include<bits/stdc++.h>
using namespace std;
/*
	BOJ1300 - k번째 수 (이분탐색 응용) 
	A[i][j]의 형태
	i* 1 i*2 ... i*N
	
	m보다 작거나 같은 숫자는 i*j<=m을 만족하는 j의 개수. j<=m/i;
	
	최솟값 :1 최댓값 : k B[k]는 1와 k 사이에 있는 어떤수. 
*/
int main(){
	int n,k;cin>>n;
	cin>>k;
	
	int left=1,right=k,ans=0;
	while(left<=right){
		int mid=(left+right)/2;
		long long count=0;
		
		for(int i=1;i<=n;i++) count+=min(mid/i,n);
		
		if(count<k){
			left=mid+1;
		}else{
			ans=mid;
			right=mid-1;
		}

	}
	cout<<ans;
	
} 
