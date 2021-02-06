#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 1806 - 부분합
	
	왜 골드 4인지 모르겠네.. 예전에 AC 못받은걸 다시푸는 중인데
	지금 보니 쉽게 풀리는 문제들이 많아 기분이 좋다.
	
	기본적인 투포인터 개념을 이용해서, 기준 값보다 작으면 end ++, 기준 값보다 크면 start++을 하는 것을 반복.
	길이의 최소값을 저장하여 출력한다. 
*/
int main(){
	int n,s;cin>>n>>s;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int start=0,end=0;
	int ans=1e6;
	
	int sum=arr[0];
	while(start<=end&&end<n){
		if(sum<s){
			end++;
			sum+=arr[end];
		}else{
			ans=min(ans,end-start+1);
			sum-=arr[start];
			start++;
		}
	
	}
	(ans!=1e6)?cout<<ans:cout<<0;
} 
