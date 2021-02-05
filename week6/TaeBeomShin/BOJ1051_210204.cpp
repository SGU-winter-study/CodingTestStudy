#include<bits/stdc++.h>
using namespace std;
/*
	BOJ1051 숫자 정사각형
	
	간단한 구현. 문제(격자안에서 최대값 찾기..)
	- 기준점과 크기를 늘려가면서 만족하는 최대 정사각형을 구한다. 
*/
int main(){
	int m,n;cin>>n>>m;
	
	int arr[n][m];
	int num=max(m,n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	int ans=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int size=1;size<num;size++){
				if(i+size>=n||j+size>=m) continue;
				if(arr[i][j]==arr[i+size][j]&&arr[i+size][j]==arr[i][j+size]&&arr[i][j+size]==arr[i+size][j+size]){
					ans=max(ans,size+1);
				}
			}
		}
	}
	cout<<ans*ans;
} 
