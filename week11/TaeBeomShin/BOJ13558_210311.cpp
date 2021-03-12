#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
/*
	BOJ13558
	
	- 자료형에 유의하기
	- 배열 중간에서 나누어 생각하기 ..! 
*/
long long nums[60010],lnums[60010];
int n,num,A[100001];
	
int main(){
	fastio;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>A[i];
		if(i>=2) nums[A[i]]++;
	}
	
	lnums[A[0]]++;

	long long cnt=0;
	for(int i=1;i<n-1;i++){		
		for(int j=1;j<=2*A[i];j++)
			cnt+=(long long)(lnums[j]*nums[2*A[i]-j]);
		lnums[A[i]]++;
		nums[A[i+1]]--;
	}
	cout<<cnt;
}
