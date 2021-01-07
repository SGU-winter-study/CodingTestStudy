#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define INFINITY 100000000

using namespace std;

int N, M, X;
vector<pair<int, int>>* g; // (node, weight)
int** total;
bool* visited;

void dijkstra() {
	int i, j, k;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for (k = 1; k <= N; k++) {
				if (total[j][i] + total[i][k] < total[j][k])
					total[j][k] = total[j][i] + total[i][k];
			}
		}
	}
}

int main() {
	int u, v, w, i, tmp, max = 0;

	cin >> N >> M >> X;
	g = new vector<pair<int, int>>[N + 1];
	total = new int*[N + 1];
	for (i = 0; i <= N; i++) {
		total[i] = new int[N + 1];
		fill(total[i], total[i] + (N + 1), INFINITY);
		total[i][i] = 0;
	}
	visited = new bool[N + 1];
	
	fill(visited, visited + (N + 1), false);
	for (i = 0; i < M; i++) {
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w)); // w: time cost from u to v
		total[u][v] = w;
	}

	dijkstra();
	
	for (i = 1; i <= N; i++) {
		if (max < total[i][X] + total[X][i])
			max = total[i][X] + total[X][i];
	}
	cout << max;
}
