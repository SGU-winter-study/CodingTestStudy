#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 1806 - �κ���
	
	�� ��� 4���� �𸣰ڳ�.. ������ AC �������� �ٽ�Ǫ�� ���ε�
	���� ���� ���� Ǯ���� �������� ���� ����� ����.
	
	�⺻���� �������� ������ �̿��ؼ�, ���� ������ ������ end ++, ���� ������ ũ�� start++�� �ϴ� ���� �ݺ�.
	������ �ּҰ��� �����Ͽ� ����Ѵ�. 
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
