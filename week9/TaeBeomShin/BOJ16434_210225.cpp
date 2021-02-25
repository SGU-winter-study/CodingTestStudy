#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

/*
	BOj 16434 - 드래곤 던전
	
	1. l=1, r=1e18(최대값 추정) 으로 설정
	2. 방을 순회하며 모든 방을 뚫을수 있는지 확인
	3. 안된다면 다시 돌아가서 반복
	
	* r을 설정하는 것이 이분탐색에서 가장 중요한 듯.. 처음에 범위를 좁게 잡아서 ac 못받음. 
*/
typedef long long ll;
typedef struct{
	int type;
	int attack;
	int hp;
}room;

int n,h_atk;
vector<room> v;

int main(){
	fastio;
	cin>>n>>h_atk;
	v.resize(n);
	
	for(int i=0;i<n;i++)
		cin>>v[i].type>>v[i].attack>>v[i].hp;
	
	long long l=1,r=1e18;
	
	while(l<=r){
		ll mid=(l+r)/2;
		ll maxhp=mid,chp=maxhp,catk=h_atk;
		bool check=true;
		
		for(int i=0;i<n;i++){
			if(v[i].type==1){
				ll mhp=v[i].hp,mattack=v[i].attack;
				chp-=(mhp/catk+(mhp%catk!=0)-1)*mattack;
				if(chp<=0) check=false;
			}else{//포션방 
				chp=min(maxhp,chp+v[i].hp);
				catk+=v[i].attack;
			}
			if(!check) break;
		}
		
		if(check) r=mid-1;
		else l=mid+1;
	}
	cout<<l;
}
