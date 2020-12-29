#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
/*
	단순구현문제 문제에서 각 Square별로 작성한 규칙에 따라 유효성 체크만 해주면됨.
	자료구조를 적절히 쓰면 좀 더 쉽게 구현 가능할 듯함. 
*/
void printans(int count,int magic){
	if(magic==1){
		printf("Square %d: Not a Magick Square\n",count);
	}else if(magic==2){
		printf("Square %d: Semi-Magick Square\n",count);
	}else if(magic==3){
		printf("Square %d: Weakly-Magick Square\n",count);
	}else if(magic==4){
		printf("Square %d: Strongly-Magick Square\n",count);
	}else if(magic==5){
		printf("Square %d: Magically-Magick Square\n",count);
	}
}
int main(){
	fastio;
	int count=1;
	while(true){
		int n;cin>>n;
		if(n==0) break;
		int magic=0,arr[n][n];
		map <int,int> m;
		vector<int> v;
		bool dup=false;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>arr[i][j];
				v.push_back(arr[i][j]);
				if(m.find(arr[i][j])!=m.end()){
					m[arr[i][j]]++;
					dup=true;
				}
				else m[arr[i][j]]=1;
			}
		}
		
		int sum=0;	
		for(int i=0;i<n;i++) sum+=arr[0][i];
		
		for(int i=0;i<n;i++){
			int row=0,col=0;
			for(int j=0;j<n;j++){
				row+=arr[i][j];
				col+=arr[j][i];
			}
			if(sum!=row||sum!=row){
				magic=1;
				break;
			}
		}
		if(magic==1) {
			printans(count,magic);
			count++;
			continue;
		}
		
		//3. Strongly-Magick Square 인가? 
		int lr=0,rl=0;
		for(int i=0;i<n;i++){
			lr+=arr[i][i];
			rl+=arr[n-i-1][n-i-1];
		}
		(sum==lr&&sum==rl)?magic=3:magic=2;
		if(magic==2){
			printans(count,magic);
			count++;
			continue;
		}
		// 4. Strongly-Magick Square 인가? 
		if(dup){
			magic=3; 
			printans(count,magic);
			count++;
			continue;
		}
		//5.Magically magic consecutive 인가?
		bool cont=true;
		sort(v.begin(),v.end());
		for(int i=0;i<v.size()-1;i++){
			if(v[i+1]-v[i]!=1){
				cont=false;
				break;
			}
		}
		if(cont){
			magic=5;
			printans(count,magic);
			count++;
		}else{
			magic=4;
			printans(count,magic);
			count++;
		}
	}
}
