#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
/*
	BOJ 17203  
	
	누적합 기본 응용. - 누적합을 두번 응용. 
*/
int arr[1002]={0,};
int var[1002]={0,};
int psum[1002]={0,};
int main(){
	fastio;
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<n;i++){
		var[i]=abs(arr[i+1]-arr[i]);
		psum[i]=psum[i-1]+var[i];
	}

	for(int i=0;i<m;i++){
		int start,end;cin>>start>>end;
		if(start==end) cout<<"0\n";
		else cout<<psum[end-1]-psum[start-1]<<"\n";
	}
}
