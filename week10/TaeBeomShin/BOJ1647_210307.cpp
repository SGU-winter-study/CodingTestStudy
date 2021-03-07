#include<bits/stdc++.h>
using namespace std;

/*
	BOJ1647 (MST 살짝 응용)
	
	두 마을을 만드는데, 드는 길 유지비의 최솟값.
	
	크루스칼을 n-2일때 까지 적용하면 두 마을일 때 드는
	길유지비의 최솟값이다. 
	 
*/
int uf[100000];

int find(int a){
	if(uf[a]==-1) return a;
	return uf[a]=find(uf[a]);
}

bool merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b) return false;
	uf[b]=a;
	return true;
}

struct Edge{
	int u,v,w;
	Edge(): Edge(-1,-1,0){}
	Edge(int u1,int v1,int w1): u(u1),v(v1),w(w1){}
	bool operator <(const Edge& O)const{return w<O.w;}
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0); 
	int n,m;cin>>n>>m;
	Edge e[1000000];
	
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		e[i]=Edge(--a,--b,c);
	}
	sort(e,e+m);
	
	int result=0,cnt=0;
	fill(uf,uf+n,-1);
	for(int i=0;i<m;i++){
		if(merge(e[i].u,e[i].v)){
			result+=e[i].w;
			if(++cnt==n-2){
				break;
			}
		}
	}
	cout<<result;
}
