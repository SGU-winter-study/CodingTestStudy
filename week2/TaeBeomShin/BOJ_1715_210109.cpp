#include<bits/stdc++.h>
using namespace std;
/*
	가장 작은 두 묶음씩 합친다. 이걸 반복. -> 우선순위 큐 자료구조를 이용. 
*/
int main(){
	int n;cin>>n;
	priority_queue <int,vector<int>,greater<int>> Q;
	long long sum=0;
	for(int i=0;i<n;i++){
		int num;cin>>num;
		Q.push(num);
	}
	if(Q.size()!=1){
		while(true){
			int a=Q.top();Q.pop();
			int b=Q.top();Q.pop();
			int temp=a+b;
			Q.push(temp);
			sum+=temp;
			if(Q.size()==1) break;
		}
	}
	cout<<sum;
}
