#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1000000000

using namespace std;

int V, E, K;
vector<pair<int, int>> *g;
int* d;

auto cmp = [](int left, int right) { return d[left] > d[right]; };
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);


void dijkstra() {
	int a, b, w;
	pq.push(K);
	while (!pq.empty()) {
		a = pq.top(); pq.pop();
		for (int i = 0; i < g[a].size(); i++) {
			b = g[a][i].first; w = g[a][i].second;
			if (d[a] + w < d[b]) {
				d[b] = d[a] + w;
				pq.push(b);
			}
		}
	}
}

int main() {
	int u, v, w, i;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	g = new vector<pair<int, int>>[V + 1];
	d = new int[V + 1];
	fill(d, d + (V + 1), INF); d[K] = 0;
	for (i = 0; i < E; i++) {
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
	}
	dijkstra();
	for (i = 1; i <= V; i++) {
		if (d[i] == INF) printf("INF");
		else printf("%d", d[i]);
		if (i != V) printf("\n");
	}
}
