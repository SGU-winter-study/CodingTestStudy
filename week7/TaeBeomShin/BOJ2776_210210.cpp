#include<bits/stdc++.h>
using namespace std;
/*
	sol1) map ÀÚ·áÇü ÀÌ¿ë
	
	sol2) ÀÎµ¦½ÌÀ» ÀÌºÐÅ½»öÀ¸·Î Ã³¸®ÇØ¼­ search. -> ¸Þ¸ð¸®¸¦ ÈÎ¾À ´ú »ç¿ëÇÔ. 
*/
int main(){
	int t,n,m;
	int left,right;
	int num;
	
	cin>>t;
	while(t--){
		vector<int> v1,v2;
		
		cin>>n;
		while(n--){
			cin>>num;
			v1.push_back(num);
		}
		cin>>m;
		while(m--){
			cin>>num;
			v2.push_back(num);
		}
		sort(v1.begin(),v1.end());
		
		for(int j=0;j<v2.size();j++){
			bool flag=false;
			left=0;right=v1.size()-1;
			while(left<=right){
				int mid=(left+right)/2;
				if(v2[j]==v1[mid]){
					flag=true;
					break;
				}
				if(v2[j]>v1[mid]) left=mid+1;
				else right=mid-1;
			}
			cout<<flag<<"\n";
		}
	}
}
