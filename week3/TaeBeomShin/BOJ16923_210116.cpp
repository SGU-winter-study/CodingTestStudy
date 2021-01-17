#include<bits/stdc++.h>
using namespace std;
/*
	완전탐색 조합응용. - 문자열의 길이가 26미만인경우와 26인 경우를 나누어 생각.
	
	1. 26미만 인 경우: 사용하지 않은 문자중 우선순위 높은걸 추가한다.
	2. 26인 경우 : next_permutation을 통해 다음에 올 문자열이 있는지 체크해서 반환한다. 
*/
int cnt[26]={0,};
char word[26]={0,};
int main(){
	string s; cin>>s;
	for(int i=0;i<s.length();i++){
		cnt[s[i]-'a']++;
		word[i]=s[i];
	}
	if(s.length()<26){//문자열의 길이가 26이하. 
		bool check=false;
		char w;
		for(int i=0;i<26;i++){
			if(cnt[i]==0){
				check=true;
				w='a'+i;
				break;
			}
		}
		(check)?cout<<s<<w:cout<<-1;
	}
	else{//문자열의 길이가 26이상. 
		(next_permutation(word,word+27))?cout<<word:cout<<-1;
	}
	
}
