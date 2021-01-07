#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0) 
using namespace std;
const int MAX=1e7;
bool isPrime[MAX+1];//수가 소수인지 저장되어 있는 배열.
/*
	프로그래머스 소수찾기 문제와 동일.
	 
    1. 주어진 원소로 숫자를 만든다.(-> m개중 1개, ... ,m개중 m개 고르기)
    2. 소수인지 확인한다-> 배열을 만들어 소수인지 확인한다.
*/

int solution(string numbers) {
    // 주어진 숫자로 조합을 만든다.-> next_permutation
    vector <int> v;
    for(int i=0;i<numbers.size();i++)
        v.push_back(numbers[i]-'0');
    sort(v.begin(),v.end());
    set<int> ans;
    do{
        for(int i=0;i<=v.size();i++){
            int temp=0;
            for(int j=0;j<i;j++){
                temp=(temp*10)+v[j];
                if(isPrime[temp]) ans.insert(temp);
            }
        }
    }while(next_permutation(v.begin(),v.end()));
    return int(ans.size());
}

int main(){
	fastio;
    fill(isPrime+2, isPrime+MAX+1, true);
    for(int i=2; i<=MAX; i++){
        if(!isPrime[i]) continue;
        for(int j=i*2; j<=MAX; j+=i)
            isPrime[j] = false;
    }
    int t;cin>>t;
    while(t--){
    	string num;cin>>num;
    	cout<<solution(num)<<"\n";
	}
}
