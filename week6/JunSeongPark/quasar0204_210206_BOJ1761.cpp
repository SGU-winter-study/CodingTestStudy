/*
https://www.acmicpc.net/problem/1761

풀이 :
최소 공통 조상을 찾는다.
x와 y의 최소 공통 조상을 k라 할때
두 정점 사이의 거리는 항상 최소 공통 조상을 거치게 되므로
dist[x] + dist[y] - 2 * dist[k]로 계산 가능하다
*/

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <deque>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 101010;
const int lmxn = 22;
int tc, cnt;
int n, k;
int par[mxn][lmxn];
int visit[mxn], d[mxn];
int dist[mxn];

vector<pii> adj[mxn];


void dfs(int cur, int depth, int dis) {
	visit[cur] = true;
	d[cur] = depth;
	dist[cur] = dis;

	for (auto next : adj[cur]) {
		if (visit[next.first]) continue;

		par[next.first][0] = cur;
		dfs(next.first, depth + 1, dis + next.second);
	}
}

void make() {
	for (int j = 1; j < lmxn; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}

int lca(int x, int y) {

	if (d[x] > d[y]) swap(x, y);

	for (int i = 20; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i)) {
			y = par[y][i];
		}
	}

	if (x == y) return x;

	for (int i = 20; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}
	}

	return par[x][0];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	dfs(1, 0, 0);

	make();

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		int x = lca(a, b);
		cout << dist[a] + dist[b] - 2 * dist[x] << '\n';
	}

	return 0;
}