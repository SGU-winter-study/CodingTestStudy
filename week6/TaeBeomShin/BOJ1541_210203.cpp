#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 1541 잃어버린 괄호
	 
	- 접근, 스택에 수와 연산자를 넣은 다음 -가 올때까지 값을 모두 더한후 음수 붙임.
	- 입력 처리하는게 가장 어려웠음.. 
*/
int main(){
	stack<string> S;
	string s;cin>>s;
	
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='-'||s[i]=='+'){
			string temp=s.substr(i,1);
			S.push(temp);
		}else{
			int start=i;
			while(i<s.length()){
				if(s[i]=='-'||s[i]=='+'){
					i--;
					break;
				}else{
					i++;
				}
			}
			S.push(s.substr(start,i-start+1));
			
		}
	}
	int ans=0,sum=0;
	while(!S.empty()){
		if(S.top()=="-"){
			ans-=sum;
			sum=0;
		}else if(S.top()!="+"){
			sum+=stoi(S.top());
		}
		S.pop();
	}
	cout<<ans+sum;
}
