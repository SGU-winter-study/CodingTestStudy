#include<bits/stdc++.h>
using namespace std;
/*
	BOJ2022 사다리타기
	이분탐색 in 실수 + 도형의 닯음 
	
	1. 닮음비를 이용해서 c를 양옆의 높이에 관한 식으로 바꿈
	2. 실수 오차 내의 범위일 때까지 이분탐색 수행.  
*/
int main(){
	double x,y,c;cin>>x>>y>>c;
	double l=0,r=min(x,y);
	
	while(abs(r-l)>1e-6){
		double mid=(l+r)/2;
		double lh=sqrt(x*x-mid*mid), rh=sqrt(y*y-mid*mid);
		double new_c=(lh*rh)/(lh+rh);
		if(new_c<=c) r=mid;
		else l=mid;
	}
	printf("%.3lf",r);
}
