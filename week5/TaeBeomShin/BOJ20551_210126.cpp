#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
/*
	BOJ20551
	- 해쉬 자료형(MAP 자료형) + 정렬
	- 정렬한 배열의 값과 인덱스를 map에 저장한다.
	- 쿼리가 요청될 때 마다 존재하면 인덱스 위치, 존재하지 않으면 -1을 반환한다. 
*/
int main(){
	fastio;
	int n,m;cin>>n>>m;
	vector<int> v(n);
	
	for(int i=0;i<n;i++) cin>>v[i];
	
	sort(v.begin(),v.end());//map에 v의 정보 저장.
	
	map<int,int> M;
	
	for(int i=0;i<n;i++){
		if(M.find(v[i])==M.end()) M[v[i]]=i;		
	}
	
	for(int i=0;i<m;i++){
		int num;cin>>num;
		(M.find(num)!=M.end())?cout<<M[num]<<"\n":cout<<"-1\n";
	}
}
