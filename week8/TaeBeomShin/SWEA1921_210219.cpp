#include<bits/stdc++.h>
using namespace std;
/*
	SWEA 1961 - 숫자 배열 회 
	2차원 배열 다루기 연습전 
	
	- 2차원 배열 다룰 때, 리턴으로 2차원 배열을 주는 함수는 만들지 말 것.(메모리 사용량 증가)
	- n인 케이스로 일반화 시키기, 그림으로 그려보기.
	- 기본유형 + 응용까지 풀어볼 것. 
*/
int main(){
	int t;cin>>t;
	for(int c=1;c<=t;c++){
		int n;cin>>n;
		int arr[n][n]={0,};
		for(int i=0;i<n;i++) 
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		cout<<"#"<<c<<"\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) cout<<arr[n-1-j][i];
			cout<<" ";
			for(int j=0;j<n;j++) cout<<arr[n-1-i][n-1-j];
			cout<<" ";
			for(int j=0;j<n;j++) cout<<arr[j][n-1-i];
			cout<<"\n";
		}
	}
}
