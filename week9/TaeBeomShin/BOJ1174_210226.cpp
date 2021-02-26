#include<bits/stdc++.h>
using namespace std;
/*
	BOJ1038 감소하는수 - BFS
	
	일의자리 수 부터 차례대로 bfs를 수행하면서 감소하는 조건을 만족하는
	수를 넣는다.
	
	감소하는 수들을 넣은 벡터를 정렬한후 값을 출력한다. 
*/
int main(){
	int n;cin>>n;
	queue<long long> Q;
	
	for(long long i=0;i<10;i++) Q.push(i);
	
	vector<long long> numbers;
	while(!Q.empty()){
		long long cur=Q.front();
		numbers.push_back(cur);
		Q.pop();
		
		for(long long i=0;i<cur%10;i++){
			long long nextnum=cur*10+i;
			Q.push(nextnum);
		}
	}
	sort(numbers.begin(),numbers.end());
	(n<numbers.size())?cout<<numbers[n]:cout<<-1;
}
