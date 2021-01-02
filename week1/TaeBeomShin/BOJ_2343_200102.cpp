#include<bits/stdc++.h>
using namespace std;
/*
일반적인 유형의 이분탐색 문제.
이분탐색은 항상 left,right값을 제대로 정해주는게 중요하다.
그렇지 않으면 testcase는 올바르게 나오지만 hidden case에 대해 오답일 경우가 많다.

지금까지 푼 이분탐색 문제를 종합해봤을때, left는 원소 중 최댓값, right는 원소의 총합으로
하는 것이 제일 나았다. 가끔 STl의 lowerbound, upperbound를 이용해야하는 문제도 있음.

연습해보기. 
*/
int main(){
	int n,m;cin>>n>>m;
	
	int arr[n];
	int total=0;
	int maxv=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		total+=arr[i];
		maxv=max(arr[i],maxv);
	}
	
	int right=total,left=maxv,ans=0;
	while(left<=right){
		int mid=(left+right)/2;
		int sum=0,count=0;
		
		for(int i=0;i<n;i++){
			if(sum+arr[i]>mid){
				sum=0;
				count++;
			}
			sum+=arr[i];
		}
		count++;
		(count<=m)?right=mid-1:left=mid+1;
	}
	cout<<left;
}
