#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define INF 1e8
int num[MAX],ldp[MAX],rdp[MAX],n;
/*
	BOJ 15487 - 두구간으로 나누어서 dp(어찌보면 투포인터의 구간값 최대?) 
	
	1. 왼쪽 부분(A[j]-A[i])의 차가 최대인 구간을 찾는다(0인덱스 부터 찾음) 
	
	2. 오른쪽 부분에서(A[L]-A[K])의 차가 최대인 구간을 찾는다(N-1 인덱스 부터 찾음) 
	
	3. 둘의 합이 최대가 될때의 값으 저장한다. 
*/
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>num[i];
	
	int maxn=-INF,minn=INF;
	ldp[0]=-INF;
	rdp[n-1]=-INF;
	
	for(int i=0;i<n-1;i++){
		if(i) ldp[i]=max(ldp[i-1],num[i]-minn);
		minn=min(minn,num[i]);
	}
	
	maxn=num[n-1];
	for(int i=n-2;i>1;i--){
		rdp[i]=max(rdp[i+1],maxn-num[i]);
		maxn=max(maxn,num[i]);
	}
	
	int ans=-INF;
	for(int i=1;i<n-1;i++) ans=max(ans,ldp[i]+rdp[i+1]);
	
	cout<<ans;
	
}
