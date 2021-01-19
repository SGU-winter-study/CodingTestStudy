#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 10001

using namespace std;

int V, E;
typedef pair<int, int> node;
priority_queue<node, vector<node>, greater<node>> connected;
bool mst[MAX];
vector<node> adj[MAX];

void add_connected(int u) {
	for (int i = 0; i < adj[u].size(); i++) {
		if (!mst[adj[u][i].second])
			connected.push(make_pair(adj[u][i].first, adj[u][i].second));
	}
}


int prim() {
	int min_cost = 0, u, w;
	int i;

	fill(mst, mst + MAX, false);

	// select start node
	connected.push(make_pair(0, 1));

	while (!connected.empty()) {
		u = connected.top().second; w = connected.top().first;
		connected.pop();
		if (!mst[u]) {
			mst[u] = true;
			min_cost += w;
			add_connected(u);
		}

	}

	return min_cost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int i, u, v, w;
	cin >> V >> E;
	for (i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(w, v));
		adj[v].push_back(make_pair(w, u));
	}
	cout << prim();
}
