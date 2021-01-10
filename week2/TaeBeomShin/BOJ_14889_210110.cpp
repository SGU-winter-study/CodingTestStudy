#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
/*
	BOJ 14889 스타트와 링크 - 조합 응용 문제.
	
	* 처음에 선수번호를 모두 넣어서 조합 구함 -> 시간초과 발생. 
	* 각 번호별로 선수를 포함하는지 여부를 조합으로 구함 -> 시간초과 없어짐.
	
	next_permutation 사용하기 전에, 조합의 경우의수를 먼저 계산하기
	
	문제로직
	
	1. 사원(?)별 포함여부를 나타낼 v 벡터 초기화
	2. next_permutation을 통해 팀 결정, 팀이 되는 모든 쌍에대한 능력치 합구함
	3. 최소인 능력치 출력. 
*/
int main(){
	fastio;
	int n;cin>>n;
	int arr[n+1][n+1]={0,};
	vector<int> v;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	for(int i=0;i<n/2;i++){
		v.push_back(0);
		v.push_back(1);
	}
	
	int minn=1e9;
	do{
		int start=0,link=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(v[i]+v[j]==2) start+=arr[i][j];
				else if(v[i]+v[j]==0) link+=arr[i][j];
			}
		}
		minn=min(abs(start-link),minn);
	}while(next_permutation(v.begin(),v.end()));
	
	cout<<minn;
} 
