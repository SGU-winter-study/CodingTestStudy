#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

#define INF 1000000000

using namespace std;

typedef struct _edges {
	int right;
	int down;
} edges;

int N, M;

short int g[100][100];
int dist[100][100];
bool visited[100][100];

auto cmp = [](pair<int, int> left, pair<int, int> right) { 
	return dist[left.first][left.second] > dist[right.first][right.second];
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

int min(int a, int b) {
	return a < b ? a : b;
}


void dijkstra() {
	int tmp, i, j;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		i = pq.top().first; j = pq.top().second;
		pq.pop();
		// UP
		if (i != 0) {
			if (!visited[i-1][j] && dist[i][j] + g[i - 1][j] < dist[i - 1][j]) {
				dist[i - 1][j] = dist[i][j] + g[i - 1][j];
				pq.push(make_pair(i-1, j));
			}
		}
		// DOWN
		if (i != N-1) {
			if (!visited[i + 1][j] && dist[i][j] + g[i + 1][j] < dist[i + 1][j]) {
				dist[i + 1][j] = dist[i][j] + g[i + 1][j];
				pq.push(make_pair(i + 1, j));
			}
		}
		// RIGHT
		if (j != M - 1) {
			if (!visited[i][j + 1] && dist[i][j] + g[i][j + 1] < dist[i][j + 1]) {
				dist[i][j + 1] = dist[i][j] + g[i][j + 1];
				pq.push(make_pair(i, j + 1));
			}
		}
		// LEFT
		if (j != 0) {
			if (!visited[i][j - 1] && dist[i][j] + g[i][j - 1] < dist[i][j - 1]) {
				dist[i][j - 1] = dist[i][j] + g[i][j - 1];
				pq.push(make_pair(i, j - 1));
			}
		}
		visited[i][j] = true;
	}
}

int main() {
	int i, j;
	cin >> M >> N;
	for (i = 0; i < N; i++) {
		string maze;
		cin >> maze;
		for (j = 0; j < M; j++) {
			dist[i][j] = INF; visited[i][j] = false;
			g[i][j] = maze[j] - '0';
		}
	}

	dist[0][0] = 0;
	dijkstra();

	cout << dist[N - 1][M - 1];
}
