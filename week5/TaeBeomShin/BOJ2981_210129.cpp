#include<bits/stdc++.h>
using namespace std;

int arr[101]={0,};
/*
	BOJ 2981 검문
	 
	그냥 수학문제.. 식을 소거해서 최대공약수를 구한후
	
	1을 제외한 최대공약수의 공약수를 출력해준다. 
*/
int gcd(int a,int b){
	return a%b?gcd(b,a%b):b;
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	
	int num=arr[1]-arr[0];

	for(int i=2;i<n;i++)
		num=gcd(num,arr[i]-arr[i-1]);

	vector<int> ans;
	for(int i=1;i*i<=num;i++){
		if(num%i==0){
			ans.push_back(i);
			if(i!=num/i) ans.push_back(num/i);
		}
	}
	
	sort(ans.begin(),ans.end());
	for(int num:ans){
		if(num==1) continue;
		cout<<num<<" ";
	}
}
