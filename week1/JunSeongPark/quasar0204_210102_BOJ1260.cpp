/*
https://www.acmicpc.net/problem/1260

풀이 : 구현
*/

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

const int mxn = 1001;
int n, m, v;
bool adj[mxn][mxn];
bool visit[mxn];

void dfs(int cur) {
	visit[cur] = true;
	cout << cur << ' ';

	for (int next = 1; next <= n; next++)
		if (adj[cur][next] && !visit[next]) 
			dfs(next);
		
}

void bfs() {
	fill(visit, visit + mxn, 0);
	queue<int> q;
	q.push(v);

	int cur;

	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (visit[cur]) continue;

		cout << cur << ' ';
		visit[cur] = true;

		for (int next = 1; next <= n; next++) 
			if (adj[cur][next] && !visit[next])
				q.push(next);
	}
}

int main() {
	cin >> n >> m >> v;
	int from, to;

	for (int i = 0; i < m; i++) {
		cin >> from >> to;

		adj[from][to] = adj[to][from] = true;
	}

	dfs(v);

	cout << '\n';

	bfs();

	return 0;

}