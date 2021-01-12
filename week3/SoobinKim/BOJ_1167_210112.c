#include <iostream>
#include <vector>

using namespace std;

int V, max_dist, selected;
vector<pair<int, int>> *tree;
bool* visited;

void dfs(int start, int dist) {
	int i, next, w, flag = 0;
	visited[start] = true;
	for (i = 0; i < tree[start].size(); i++) {
		next = tree[start][i].first; w = tree[start][i].second;
		if (!visited[next]) {
			flag = 1;
			dfs(next, dist + w);
		}
	}
	if (flag == 0) {
		if (max_dist < dist) {
			max_dist = dist;
			selected = start;
		}
	}
}

int main() {
	int i, u, v, w, toggle;
	cin >> V;
	tree = new vector<pair<int, int>>[V + 1];
	visited = new bool[V + 1];

	// make tree
	for (i = 0; i < V; i++) {
		cin >> u; toggle = true;
		do {
			if (toggle) {
				cin >> v;
			}
			else {
				cin >> w;
				tree[u].push_back(make_pair(v, w));
			}
			toggle = !toggle;
		} while (v != -1);
	}
	max_dist = -1; fill(visited, visited + (V + 1), false);
	dfs(1, 0);
	int max1 = max_dist;
	max_dist = -1; fill(visited, visited + (V + 1), false);
	dfs(selected, 0);
	int max2 = max_dist;

	cout << max2;
}
