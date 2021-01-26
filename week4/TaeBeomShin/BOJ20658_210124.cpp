#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 2938 3���� ������ �������� �ʴ� �迭.
	
	������ �μ��� ���� 3���� ������ �������� ��������.??
	1. ���� ���� n�� ũ�� 1<=n<=10000 ��� ����Ǽ� n!..
	  ->  �׷��Ƿ� O(n^2)���� �ذ��ؾ���. 
	
	How?? �������� 1,2�� ���� ���� ������ ��� ������ ���� ���̿� �������� 0�μ� �������.  
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
	// 1. ������ 3�� ���
	if(one.empty()&&two.empty()) check=false;
	// 2. �������� 1,2�� ���� �ְ� 3�ǹ���� �ϳ��� ����.
	if(!one.empty()&&!two.empty()&&three.empty()) check=false;
	// 3.�������� 1,2�� ���� ������ ���� �������� 3�μ� ���� ����. 3 3 3 3 1 1 2   313123
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
