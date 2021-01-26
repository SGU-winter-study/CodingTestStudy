#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 2938 3으로 나누어 떨어지지 않는 배열.
	
	인접한 두수의 합이 3으로 나누어 떨어지지 않을조건.??
	1. 최초 접근 n의 크기 1<=n<=10000 모둔 경우의수 n!..
	  ->  그러므로 O(n^2)만에 해결해야함. 
	
	How?? 나머지가 1,2인 수의 쌍의 개수를 모두 모으고 수들 사이에 나머지가 0인수 넣으면됨.  
*/
int main(){
	int n;cin>>n;
	stack<int> one,two,three;
	for(int i=0;i<n;i++){
		int num;cin>>num;
		if(num%3==1) one.push(num);
		if(num%3==2) two.push(num);
		if(num%3==0) three.push(num);
	}
	
	
	bool check=true;
	// 1. 모든수가 3의 배수
	if(one.empty()&&two.empty()) check=false;
	// 2. 나머지가 1,2인 수가 있고 3의배수가 하나도 없음.
	if(!one.empty()&&!two.empty()&&three.empty()) check=false;
	// 3.나머지가 1,2인 수의 개수의 합이 나머지가 3인수 보다 작음. 3 3 3 3 1 1 2   313123
	if(one.size()+two.size()+1<three.size()) check=false;
	
	if(check){
		while(!one.empty()&&three.size()>1){
			cout<<three.top()<<" ";
			three.pop();
			cout<<one.top()<<" ";
			one.pop();
		}
		while(!one.empty()){
			cout<<one.top()<<" ";
			one.pop();
		}
		while(!two.empty()&&!three.empty()){
			cout<<three.top()<<" ";
			three.pop();
			cout<<two.top()<<" ";
			two.pop();
		}
		while(!two.empty()){
			cout<<two.top()<<" ";
			two.pop();
		}
		while(!three.empty()){
			cout<<three.top()<<" ";
			three.pop();
		}
	}else
		cout<<-1;
	
}
