#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
/*
	BOJ 16567 바이너리 왕국
	
	- 첫 시도 시간초과 : 0이 호출될때마다 새로 값을 구해서 시간초과가 남.
	- 코드 수정, 값을 구하는 코드를 밖으로 빼고, 새로 값이 추가되는 경우를 케이스 분류해서
	  값을 업데이트하는 형태로 변경.
	  
	- 중점 : O(N)인 풀이가 정해인 경우가 많으니. 이중 포문이 나올때는 의심하자..
			(테케가 맞아도 히든케이스에서 틀릴확률 매우 높음) 
*/
int main(){
	fastio;
	int n,m;cin>>n>>m;
	int road[n];
	for(int i=0;i<n;i++) cin>>road[i];
	
	int count=0;
	for(int i=0;i<n;i++){
		if(road[i]==1){
			while(road[i]==1&&i<n) i++;
			count++;
		}
	}
	
	while(m--){
		int num;cin>>num;
		if(num==0){
			cout<<count<<"\n";
		}else{
			int idx;cin>>idx;
			if(road[idx-1]!=1){
				road[idx-1]=1;
				if(idx-2<0&&road[idx]==0) count++;
				if(idx>=n&&road[idx-2]==0) count++;
				if(idx-2>=0&&idx<n&&road[idx-2]==0&&road[idx]==0) count++;
				if(idx-2>=0&&idx<n&&road[idx-2]==1&&road[idx]==1) count--;	
			}
		}
	}
} 
