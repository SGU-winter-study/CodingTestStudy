#include<bits/stdc++.h>
using namespace std;
/*

	BOJ 2346 풍선 터트리기 
	- 요세푸스 문제와 유사, NHN 기출 중에서 수건돌리기 있었는데 그것도 이런 유형이였던 걸로 기억함(더 복잡하긴했음)
	- 중점 : 벡터에서 인덱스의 모듈러 처리와 vector 자료형에 대한 이해(erase 메소드 이용) 
	- 그리면서 하면 덜헷갈림. 머리로만 푸려고하면 실수많이하는 문제. 
	
*/
int main(){
	int N;cin>>N;
	vector<pair<int,int>> v(N);
	vector<int> ans;
	
	for(int i=0;i<N;i++){
		int num;cin>>num;
		v[i]={i+1,num};
		
	}
	
	int idx=0,temp=N;
	
	for(int i=0;i<temp;i++){
		cout<<v[idx].first<<" ";
		int move=v[idx].second;
		if(move>0) move--;
		v.erase(v.begin()+idx);
		idx+=move;
		if(--N==0) break;
		
		idx=(idx>=0)?idx:N+idx%N;
		idx%=N;
	}
	
}
