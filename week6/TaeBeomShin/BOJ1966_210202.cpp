#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
/*
	BOJ 1966 - 프린터큐.
	
	내풀이. Prioirty queue 와 Queue를 적절히 활용하여 구현.
	다른 사람 풀이. 두 벡터를 선언해서 한벡터를 정렬한 후 for문을 적절히 활용하여 구현. 
	
	아마 문제 의도는 내풀이에 가깝지 않을까... 
	 
*/
int main(){
	int t;cin>>t;
	
	while(t--){
		int n,m;cin>>n>>m;
		queue<pair<int,int>> Q;
		priority_queue<int,vector<int>,less<int>> PQ;
		for(int i=0;i<n;i++){
			int num;cin>>num;
			Q.push({num,i});
			PQ.push(num);
		}
		
		int ans=0;
		bool check=false;
		while(true){
			int value=Q.front().first,idx=Q.front().second;
			if(PQ.top()!=value){
			//더 큰수가 존재하는 경우. 뺏다가 넣어줌. 
				Q.pop();
				Q.push({value,idx});
			}else{
			//더 큰수가 없는 경우. 인쇄함. 
				Q.pop();PQ.pop();
				ans++;
				if(idx==m)check=true;
			}
			if(check) break;
		}
		cout<<ans<<"\n";
	}
}
