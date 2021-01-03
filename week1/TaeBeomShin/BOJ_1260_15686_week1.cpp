/*
 삼성 SW 기출 문제 - 치킨배달(DFS or 조합  + 브루트 포스)
 
 1. DFS나 조합을 통해서 폐업시키지 않을 치킨집 m개를 고른다. 
 2. 반복해서 각각의 치킨거리를 구한다음 최솟값을 저장한다.
 3. 최솟값을 출력한다.
 
 조합이나 dfs를 많이 사용하지 않았으면 m개의 치킨집을 뽑아내는 것이 어렵게 느껴진다(예전에 그랬었던 듯) 
*/
#include<bits/stdc++.h>
using namespace std;

int arr[51][51];
vector<pair<int,int> >house;
vector<pair<int,int> >chicken;
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1) house.push_back({i,j});
			if(arr[i][j]==2) chicken.push_back({i,j});
		}
	}
	int mn=1e9;
	vector<int> check(chicken.size(),1);
	fill(check.begin(),check.begin()+chicken.size()-m,0);
	do{
		int dist=0;
		for(auto h : house){
			int temp=1e9;
			for(int i=0;i<chicken.size();i++){
				if(check[i]==0) continue;
				temp=min(temp,abs(chicken[i].first-h.first)+abs(chicken[i].second-h.second));
			}
			dist+=temp;
		}
		mn=min(mn,dist);
	}while(next_permutation(check.begin(),check.end()));
	cout<<mn;
}
