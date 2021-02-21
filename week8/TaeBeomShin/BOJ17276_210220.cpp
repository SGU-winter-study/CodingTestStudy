#include<bits/stdc++.h>
using namespace std;

int n;
void rotate(int[][] arr,int[][] storage){
	for(int i=0;i<n;i++){
		storage[i][i]=arr[n/2][i];
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		int d;cin>>n>>d;
		int arr[n][n];
		int storage[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		d=(d<0)?d+360:d;
		/*
			X를 45° 의 배수만큼 시계방향 혹은 반시계방향으로 돌리려고 한다. X를 시계 방향으로 45° 돌리면 아래와 같은 연산이 동시에 X에 적용되어야 한다:
			X의 주 대각선을 ((1,1), (2,2), …, (n, n)) 가운데 열 ((n+1)/2 번째 열)로 옮긴다.
			X의 가운데 열을 X의 부 대각선으로 ((n, 1), (n-1, 2), …, (1, n)) 옮긴다. 
			X의 부 대각선을 X의 가운데 행 ((n+1)/2번째 행)으로 옮긴다.
			X의 가운데 행을 X의 주 대각선으로 옮긴다.
			위 네 가지 경우 모두 원소의 기존 순서는 유지 되어야 한다.
			X의 다른 원소의 위치는 변하지 않는다.
		*/
		
	}
	
} 
