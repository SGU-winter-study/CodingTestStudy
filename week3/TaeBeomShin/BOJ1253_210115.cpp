#include<bits/stdc++.h>
using namespace std;
/*
	투포인터 알고리즘. 응용.
	
	1. 배열을 정렬한다.
	2. 작은수 부터 하나 씩 살펴본다.
		- 두수의 합이 구려하는 수보다 작으면 start++, 크면 end--;
		- 유의) 원소로 0이 주어지는 경우가 corner case임 이에 대해 고려하기.
	3. 구한 답을 출력한다. 
*/
int arr[2001]={0,},n;
long long answer=0;

void input(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	
}

void getAnswer(){
	//수를 정렬한다. O(nlog n)
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++){
		//큰 수 부터 하나씩 살펴봄.
		int num=arr[i];
		int start=0,end=n-1;
		while(start<end){
			int sum=arr[start]+arr[end];
			if(sum==num){
				if(start!=i && end !=i){
				//둘 중에 0인 값이 없음. 
					answer++;
					break;
				}else if(start==i){
				//end가 0임. 
					start++;
				}else{
				//right가 0임.
					end--; 
				}
			}else if(sum>num){
				end--;
			}else{
				start++;
			}
		}
	}
}
int main(){
	input();
	getAnswer();
	cout<<answer;
}
