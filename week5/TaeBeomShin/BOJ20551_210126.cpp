#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
/*
	BOJ20551
	- �ؽ� �ڷ���(MAP �ڷ���) + ����
	- ������ �迭�� ���� �ε����� map�� �����Ѵ�.
	- ������ ��û�� �� ���� �����ϸ� �ε��� ��ġ, �������� ������ -1�� ��ȯ�Ѵ�. 
*/
int main(){
	fastio;
	int n,m;cin>>n>>m;
	vector<int> v(n);
	
	for(int i=0;i<n;i++) cin>>v[i];
	
	sort(v.begin(),v.end());//map�� v�� ���� ����.
	
	map<int,int> M;
	
	for(int i=0;i<n;i++){
		if(M.find(v[i])==M.end()) M[v[i]]=i;		
	}
	
	for(int i=0;i<m;i++){
		int num;cin>>num;
		(M.find(num)!=M.end())?cout<<M[num]<<"\n":cout<<"-1\n";
	}
}
