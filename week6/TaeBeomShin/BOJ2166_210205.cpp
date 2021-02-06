#include<bits/stdc++.h>
#define x first
#define y second
#define ll long long
using namespace std;
/*
	BOJ 2166 다각형의 면적
	-> CCW 알고리즘(아마 코테에서는 필요없을듯..)
	
	세 점을 가지고 외적을 통해 다각형의 넓이를 응용해서 구할수 있도록하는 알고리즘.
	외적 계산은 예전에 배운 벡터 공식을 통해 하면됨. 
	
	주의해야하는 부분은 자료형 정도? 공식은 간단함.
	 
*/
vector< pair<ll,ll> >  v(10001);

long long ccw(pair<ll,ll> &p1,pair<ll,ll> &p2,pair<ll,ll> &p3){
	long long ans=p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.x*p3.y-p3.x*p2.y-p2.x*p1.y;
	return ans;
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>v[i].x>>v[i].y;
	ll sum=0;
	for(int i=0;i<n-1;i++)
		sum+=ccw(v[0],v[i],v[i+1]);
		
	printf("%.1lf",abs(sum/2.0));
}
