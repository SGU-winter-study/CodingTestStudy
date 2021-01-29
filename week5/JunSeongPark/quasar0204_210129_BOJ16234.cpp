/*
https://www.acmicpc.net/problem/16234

풀이 :
bfs 또는 dfs를 이용한 구현 문제
매번 모두 탐색하면서 연결되어있는 부분에 대한 처리를 해주면 됨
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
const int mxn = 55;

int tc, cnt;
int n, l, r;

int _map[mxn][mxn];
bool visit[mxn][mxn];

bool bfs(int Y, int X) {
	queue<pii> q;
	vector<pii> v;
	int sum = _map[Y][X];
	bool ret = false;

	q.push({ Y,X });
	v.push_back({ Y,X });
	visit[Y][X] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dr[i];
			int nx = x + dc[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visit[ny][nx]) continue;
			if (!(l <= abs(_map[ny][nx] - _map[y][x]) && abs(_map[ny][nx] - _map[y][x]) <= r)) continue;

			visit[ny][nx] = true;
			q.push({ ny, nx });
			v.push_back({ ny,nx });
			sum += _map[ny][nx];
			ret = true;
		}
	}

	for (auto p : v) {
		_map[p.first][p.second] = sum / v.size();
	}

	return ret;
}

bool solve() {
	memset(visit, false, sizeof(visit));

	bool ret = false;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (visit[y][x]) continue;

			if (bfs(y, x)) ret = true;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;

	for (int y = 0; y < n; y++) 
		for (int x = 0; x < n; x++)
			cin >> _map[y][x];
	

	while (solve()) {
		cnt++;
	}

	cout << cnt;


	return 0;
}
