#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 16937 두 스티커 
	예전 초등학교, 중학교때했던 사고력 문제 같은 느낌..
	
	CASE 분류 + 단순 구현.
	
	맞닿아 있는 곳은 큰 변의 길이, 맞닿지 않은 곳은 두변의 길이 합이 길이가 된다는 성질을 이용해서
	총 8개로 케이스 분류해준다. 
	
	조건문을 하나로 합치면 코드는 단순해지나 가독성이 안좋아서 단순하게 나열하는 형태로 코드를 작성했다. 
*/
int main(){
	int h,w;cin>>h>>w;
	
	vector<pair<int,int>> v;
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int r,c;cin>>r>>c;
		v.push_back({r,c});
	}
	
	int ans=0;
	bool check=false;
	for(int i=0;i<n;i++){
		auto A=v[i];
		int AR=v[i].first,AC=v[i].second;
		for(int j=i+1;j<n;j++){
			auto B=v[j];
			int BR=v[j].first,BC=v[j].second;
			int square=AR*AC+BR*BC;
			check=false;
			//맞닿아 있는 곳은 더 큰 변의 길이, 맞닿지 않은 곳은 두 변의 길이합.
			if(AR+BR<=h&&max(AC,BC)<=w) check=true;
			if(AR+BR<=w&&max(AC,BC)<=h) check=true;
			if(AC+BC<=h&&max(AR,BR)<=w) check=true;
			if(AC+BC<=w&&max(AR,BR)<=h) check=true;
			if(AR+BC<=h&&max(AC,BR)<=w) check=true;
			if(AR+BC<=w&&max(AC,BR)<=h) check=true;
			if(AC+BR<=h&&max(AR,BC)<=w) check=true;
			if(AC+BR<=w&&max(AR,BC)<=h) check=true;
			if(check) ans=max(square,ans);
		}
	}
	cout<<ans;
} 
