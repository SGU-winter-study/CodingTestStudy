#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 10001

using namespace std;

int V, E;
vector<pair<int, pair<int, int>>> g; // weight, <node1, node2>
int mst[MAX];

void mst_init() {
	for (int i = 0; i < MAX; i++) {
		mst[i] = i;
	}
}

int find_root(int u) {
	while (mst[u] != u) {
		mst[u] = mst[mst[u]];
		u = mst[u];
	}
	return u;
}

bool no_cycle(int u, int v) {
	return find_root(u) != find_root(v);
}

void add_mst(int u, int v) {
	mst[find_root(u)] = mst[find_root(v)];
}

int kruskal() {
	int min_cost = 0;
	int u, v, w, i;

	// sort by weight
	sort(g.begin(), g.end());
	mst_init();

	for (i = 0; i < E; i++) {
		w = g[i].first;
		u = g[i].second.first; v = g[i].second.second;
		if (no_cycle(u, v)) {
			min_cost += w;
			add_mst(u, v);
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
		g.push_back(make_pair(w, make_pair(u, v)));
	}

	cout << kruskal();
}
