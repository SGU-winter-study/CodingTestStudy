#include<bits/stdc++.h>
using namespace std;
/*
	BOJ3584 NCA
	
	sol)
	
	1. 각 노드별 부모 노드 정보 저장.
	2. 두 노드의 부모 노드를 역순회하며 저장.
	3. 가장 빨리 공통된 노드가 나올 때, 그 노드가 NCA 
*/
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	
	while(t--){
		int n;cin>>n;
		int nodes[n+1]={0,};
		for(int i=0;i<n-1;i++){
			int p,c;cin>>p>>c;
			//c의 부모는 p이다. 
			nodes[c]=p;	
		}
		int node1,node2;cin>>node1>>node2;
		
		vector<int> node1_parent,node2_parent;
		
		while(true){
			if(node1==0) break;
			node1_parent.push_back(node1);
			node1=nodes[node1];
		}
		
		while(true){
			if(node2==0) break;
			node2_parent.push_back(node2);
			node2=nodes[node2];
		}
		
		int ans=0;
		for(int i=0;i<node1_parent.size();i++){
			for(int j=0;j<node2_parent.size();j++){
				if(node1_parent[i]==node2_parent[j]){
					ans=node1_parent[i];
					break;
				}
				if(ans) break;
			}
			if(ans) break;
		}
		cout<<ans<<"\n";
	}
}
