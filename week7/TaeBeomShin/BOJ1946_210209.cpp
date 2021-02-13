#include<bits/stdc++.h>
using namespace std;
/*
	BOJ1946 - 신입사원
	
	pair의 정렬 + 약간의 로직.
	입력받은 순위를 서류성적을 기준으로 오름차순 정렬.
	지원자들을 차례로 비교하며 최고 면접성적을 갱신.
	
	조건 만족하는 지원자 명수 추가. 
*/
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<pair<int,int>> v(n);
		for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
		sort(v.begin(),v.end());
		
		int minb=v[0].second;
		int count=1;
		for(int i=1;i<v.size();i++){
			if(v[i].second<minb) count++;
			minb=min(minb,v[i].second);
		}
		cout<<count<<"\n";
	}
}
