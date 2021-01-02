/*
https://www.acmicpc.net/problem/16236

풀이 : pq bfs
bfs의 queue를 priority queue로 바꿔주면 됨
https://www.acmicpc.net/problem/20046 문제도 비슷하게 풀 수 있을 것 같음
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
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 20;

struct node {
	int d, y, x;

	node(int a, int b, int c)
	: d(a), y(b), x(c) {};

	bool operator<(const node &rhs) const {
		if (d == rhs.d) {
			if (y == rhs.y) 
				return x > rhs.x;
			return y > rhs.y;
		}
		return d > rhs.d;
	}
};

int _map[mxn][mxn];
bool visit[mxn][mxn];


int tc, cnt;
int n;
int ans, sz = 2;
pii start;

void solve() {
	priority_queue<node> pq;
	pq.push(node(0,start.first, start.second));

	while (!pq.empty()) {
		int d = pq.top().d;
		int y = pq.top().y;
		int x = pq.top().x;
		pq.pop();

		if (0 < _map[y][x] && _map[y][x] < sz) {
			_map[y][x] = 0;
			cnt++;
			ans += d;
			d = 0;
			while (pq.size()) pq.pop();
			memset(visit, false, sizeof(visit));

			if (cnt == sz) {
				sz++;
				cnt = 0;
			}
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dr[i];
			int nx = x + dc[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visit[ny][nx]) continue;
			if (_map[ny][nx] > sz) continue;

			pq.push(node(d + 1, ny, nx));
			visit[ny][nx] = true;
		}

	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> _map[y][x];
			if (_map[y][x] == 9) {
				start = { y,x };
				_map[y][x] = 0;
			}
		}
	}
	solve();

	cout << ans;

	return 0;
}