#include<bits/stdc++.h>
using namespace std;
/*
	이전순열, 다음순열, 모든 순열.
	
	순열 기본 문제. next_permutation 함수 사용법 익히는 문제..  
*/
int main(){
	int n;cin>>n;
	vector<int> v;
	for(int i=1;i<=n;i++) v.push_back(i);
	
	do{
		for(int num : v) cout<<num<<" ";
		puts("");
	}while(next_permutation(v.begin(),v.end()));
} 
