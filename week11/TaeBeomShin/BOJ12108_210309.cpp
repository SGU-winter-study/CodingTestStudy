#include<bits/stdc++.h>
using namespace std;

int n,s,A[40],threshold,sum;
long long result;
map<long long,int> cnt;
/*
	BOJ 1208 - 부분수열의 합
	
	meet in the middle 알고리즘
	
	반으로 쪼개어서 왼쪽의 부분집합, 오른쪽의 부분집합을 구한 다음
	곱해준다.
	
	각각의 부분 집합은 dfs를 통해 map으로 만든다. 
*/
void dfs1(int pos){//pos:현재 탐색중인 인덱스. 
	if(pos==threshold){
		auto iter=cnt.find(sum);
		if(iter!=cnt.end()) ++iter->second;
		else cnt[sum]=1;
		return;
	}
	dfs1(pos+1);
	sum+=A[pos];
	dfs1(pos+1);
	sum-=A[pos];
}

void dfs2(int pos){
	if(pos==n){
		auto iter=cnt.find(s-sum);
		if(iter!=cnt.end()) result +=iter->second;
		return;
	}
	dfs2(pos+1);
	sum+=A[pos];
	dfs2(pos+1);
	sum-=A[pos];
}
int main(){
	//n개의 물건, 최대 c만큼 넣을 수 있음. 
	cin>>n>>s;
	for(int i=0;i<n;i++) cin>>A[i];
	threshold=n/2;
	
	dfs1(0);
	dfs2(threshold);
	
	if(s==0) --result;
	cout<<result;
}
