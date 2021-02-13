#include<bits/stdc++.h>
using namespace std;

int main(){
	string num;cin>>num; 
	/*
		BOJ 10610 30 (정렬 응용) 
		105개의 숫자로 구성
		숫자들을 섞어 30의 배수가 되는 가장 큰 수.
		
		3의 배수이면서 10의 배수.
		-배수 판정법, 3의배수 : 각자리 숫자의 합이 3의 배수
		10의 배수 일의 자리가 0인수
		
		두조건 만족하면 수를 내림차순으로 출력. 
	*/
	
	int sum=0;
	bool check=false;
	vector<int> v;
	for(int i=0;i<num.length();i++){
		int n=num[i]-'0';
		v.push_back(n);
		sum+=n;
		if(n==0) check=true;
	}
	sort(v.begin(),v.end(),greater<int>());
	if(check&&sum%3==0){
		for(int i=0;i<v.size();i++) cout<<v[i];
	}else{
		cout<<-1;
	}
}
