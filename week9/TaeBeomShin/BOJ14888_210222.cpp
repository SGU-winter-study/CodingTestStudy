#include<bits/stdc++.h>
using namespace std;
/*
	접근: 모든 경우의수 따지기(with DFS)
	
	dfs작성요령{
		1. 종료조건
		2. 가능한 경우의수
			- 해당 경우에 어떤 것을 수행할 것이냐? 
	}
	- dfs 함수 정의를 잘하는 것이 재귀적으로 작성하는데 있어 가장 중요함!! 
*/
int n,arr[11]={0,};
int oper[4]={0,};
int min_num=INT_MAX,max_num=-INT_MAX;

void dfs(int plus,int minus,int multiply,int divide, int cnt, int sum){
	if(cnt==n){
		min_num=min(min_num,sum);
		max_num=max(max_num,sum);
	}
	//모든 경우의 수 대입
	if(plus>0)
		dfs(plus-1,minus,multiply,divide,cnt+1,sum+arr[cnt]);
	if(minus>0)
		dfs(plus,minus-1,multiply,divide,cnt+1,sum-arr[cnt]);
	if(multiply>0)
		dfs(plus,minus,multiply-1,divide,cnt+1,sum*arr[cnt]);
	if(divide>0)
		dfs(plus,minus,multiply,divide-1,cnt+1,sum/arr[cnt]);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<4;i++) cin>>oper[i];
	
	dfs(oper[0],oper[1],oper[2],oper[3],1,arr[0]);
	cout<<max_num<<"\n"<<min_num;
} 
