/*
https://www.acmicpc.net/problem/20295

풀이 :
dfs를 통해 루트부터 자신까지 오는 사탕수들을 저장한다.
lca 를 통해 최소 공통 조상을 찾은 후 x, y의 공통조상을 p라 하면
사탕 개수에 대해 a + b - 2p가 1보다 크면 중간에 사탕이 존재하는것이므로
play를 아니면 cry를 출력한다.

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
const int lmxn = 21;
int tc, cnt;
int n, m;
int par[mxn][lmxn];
int visit[mxn], d[mxn];
int candy[mxn];
int check[mxn][6];
bool fcheck[6];


vector<int> adj[mxn];

void dfs(int cur, int depth) {
	visit[cur] = true;
	d[cur] = depth;

	for (int next : adj[cur]) {
		if (visit[next]) continue;

		par[next][0] = cur;
		for (int i = 1; i <= 5; i++)
			check[next][i] += check[cur][i];
		dfs(next, depth + 1);
	}
}

void make() {
	for (int j = 1; j < lmxn; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
}

int lca(int x, int y) {
	if (d[x] > d[y]) swap(x, y);

	
	for (int i = 20; i >= 0; i--)
		if (d[y] - d[x] >= (1 << i)) {
			y = par[y][i];
			
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

	for (int i = 1; i <= n; i++) {
		cin >> candy[i];
		check[i][candy[i]]++;
		fcheck[candy[i]] = true;
	}
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	make();

	int cur = 0;
	cin >> m;
	while (m--) {
		cin >> a >> b;
		if (cur == 0) {
			if (fcheck[b])
				cout << "PLAY\n";
			else
				cout << "CRY\n";
		}
		else {
			int p = lca(cur, a);

			if (check[cur][b] + check[a][b] - 2 * check[par[p][0]][b] > 0)
				cout << "PLAY\n";
			else
				cout << "CRY\n";
		}
			
		cur = a;
	}


	return 0;
}