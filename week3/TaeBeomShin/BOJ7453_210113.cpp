/*
	https://www.acmicpc.net/problem/7453 합이 0인 네 정수
	
	투포인터 개념을 이용하여 문제를 풀었다
	(자료형을 long long이 아닌 int로 써서 오래걸림..)
	
	1. 배열 2개 씩의 합을 따로 구한다.
	2. 각 배열을 정렬 시킨다.
	3. 한배열은 앞에서부터 다른 배열은 뒤에서부터 start,end 변수를 통해 탐색한다.
	   - 합이 음수면 start ++, 합이 양수으면 end--;
	4. 합이 0이면 같은 수가 있는지 탐색한다.
	5. 이과정을 반복해서 답을 구한다.
	
	* 자료형 long long 인지 int인지 파악하기.
	* 오타 조심하기. 
*/
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

vector<int> A(4002),B(4002),C(4002),D(4002);
int main(){
	fastio;
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i]>>B[i]>>C[i]>>D[i];
	
	vector<int> Group1;
	vector<int> Group2;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			Group1.push_back(A[i]+B[j]);
			Group2.push_back(C[i]+D[j]);
		}
	sort(Group1.begin(),Group1.end());
	sort(Group2.begin(),Group2.end());
	
	int index=n*n;
	int start=0,end=index-1;
	
	long long count=0,x,y;
	while(start<index&&end>=0){
		x=0,y=0;
		if(Group1[start]+Group2[end]==0){
			int s=start;
			while(Group1[start]+Group2[end]==0){
				if(start>=index) break;
				x++;
				start++;
			}
			while(Group1[s]+Group2[end]==0){
				if(end<0) break;
				y++;
				end--;
			}
			count=count+x*y;
		}else if(Group1[start]+Group2[end]<0){
			start++;	 
		}else end--;
	}
	cout<<count;
}
