#include<bits/stdc++.h>
using namespace std;

// sol1) BFS이용하여 거리 구하기(가중치가 1이기때문에 가능) 

// sol2) 다익스트라 기본 구현. 

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,k,x;cin>>n>>m>>k>>x;
	//x에서 출발하여 갈 수 있는 도시 중에서 최단거리가 k인 모든도시.
	//단방향 그래프
	
	vector<vector<int> > adj(n);
	int dist[n]={0,};
	fill(dist,dist+n,-1);
	for(int i=0;i<m;i++){
		int cur,next;cin>>cur>>next;
		adj[cur-1].push_back(next-1);
	}
	
	vector<int> ans;
	queue<int> Q;// 정점, 거리
	Q.push({x-1});
	dist[x-1]=0;
	
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		if(dist[cur]==k) ans.push_back(cur);
		for(int i=0;i<adj[cur].size();i++){
			int next=adj[cur][i];
			if(dist[next]>=0) continue;
			dist[next]=dist[cur]+1;
			Q.push(next);
		}
	}
	
	if(ans.empty()){
		cout<<-1;
	}else{
		sort(ans.begin(),ans.end());
		for(int a : ans) cout<<a+1<<"\n";
	}
}

void solutionbyDijkstrat(){
	int dist[300001];
	
	int n, m, k, x;
    int city_a, city_b;
    int here, cost;
    int there, nextCost;
    int cnt =0;

    priority_queue<pair<int ,int>> pq;
    cin>>n>>m>>k>>x;
    vector< vector<int> > way(n+1);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &city_a, &city_b);
        way[city_a].push_back(city_b);
    }
    
    for(int i=1; i<=n; i++) dist[i] = n;
    dist[x] = 0;
    pq.push(make_pair(0, x));

    while(!pq.empty()){
        cost = -1 * pq.top().first;
        here = pq.top().second;
        pq.pop();
        
        if(dist[here] < cost)
            continue;
        
        for(int i=0; i<way[here].size(); i++){
            
            there = way[here][i];
            nextCost = cost + 1;
            
            if(nextCost < dist[there]){
                dist[there] = nextCost;
                pq.push(make_pair(-nextCost, there));

            }
            
        }
    }
    for(int i=1; i<=n; i++){
        if(dist[i] == k){
            printf("%d\n", i);
            cnt++;
        }
    }
    if(cnt == 0){
        printf("-1\n");
    }
}
