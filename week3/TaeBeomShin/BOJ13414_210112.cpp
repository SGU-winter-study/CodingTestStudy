#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<string,int>&a, const pair<string,int>&b){
	return a.second<b.second;
}
int main(){
	int k,l;cin>>k>>l;
	/*
		1. 중복되는 목록 삭제(앞에 클릭한 걸 없앰.)-> map자료형 이용. 
		2. 맨앞에서부터 k명 선정. 
	*/
	map<string,int> m; 
	for(int i=0;i<l;i++){
		string num;cin>>num;
		m[num]=i;
	}
	
	vector<pair<string,int> > v(m.begin(),m.end());
	sort(v.begin(),v.end(),cmp);
	
	k=min(k,int(v.size()));
	for(int i=0;i<k;i++)
		cout<<v[i].first<<"\n";
	
}
