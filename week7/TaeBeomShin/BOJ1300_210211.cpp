#include<bits/stdc++.h>
using namespace std;
/*
	BOJ1300 - k��° �� (�̺�Ž�� ����) 
	A[i][j]�� ����
	i* 1 i*2 ... i*N
	
	m���� �۰ų� ���� ���ڴ� i*j<=m�� �����ϴ� j�� ����. j<=m/i;
	
	�ּڰ� :1 �ִ� : k B[k]�� 1�� k ���̿� �ִ� ���. 
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
