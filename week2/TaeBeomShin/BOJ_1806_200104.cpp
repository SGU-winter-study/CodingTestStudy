/*
	-- 시간복잡도 O(n^2) --
	1. 길이를 1씩 늘려나간다.
	2. psum을 이용해 합을 구한다.
	3. 합이 s를 넘으면 길이를 반환한다. 
	
	항상 틀렸다고 나올 때는 양 끝 조건을 적절히 작성햇는지 확인할 것. 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,s;cin>>n>>s;
	int psum[n+1]={0,},sum=0,length=0;
	
	for(int i=0;i<n;i++){
		int a; cin>>a;
		sum+=a;
		psum[i+1]=sum;
	}
	
	bool flag=false;
	for(int size=1;size<=n;size++){
		for(int i=0;i<=n-size;i++){
			int num=psum[i+size]-psum[i];
			if(num>=s){
				flag=true;
				length=size;
				break;
			}
		}
		if(flag) break;
	}
	cout<<length;
}
