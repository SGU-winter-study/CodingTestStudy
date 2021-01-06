/*
링크 : https://www.acmicpc.net/problem/3055


풀이 :
bfs에 초기값으로 물의 위치를 먼저 넣어주고 그 다음 도치의 위치를 넣어준다.
이후 bfs를 실행하면 된다.
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
const int mxn = 50;

int tc, cnt;
int n, r, c;
string str[mxn];
int _map[mxn][mxn];
pii d;

void solve() {
	queue<pii> q;

	memset(_map, -1, sizeof(_map));

	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++)
			if (str[y][x] == '*') {
				_map[y][x] = INF;
				q.push({ y,x });
			}

	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++) {
			if (str[y][x] == 'S') {
				_map[y][x] = 0;
				q.push({ y,x });
			}
			if (str[y][x] == 'D')
				d = { y,x };
			if (str[y][x] == 'X')
				_map[y][x] = INF;
		}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dr[i];
			int nx = x + dc[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (_map[ny][nx] != -1) continue;
			if (_map[y][x] >= INF && str[ny][nx] == 'D') continue;

			_map[ny][nx] = _map[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	
	if (_map[d.first][d.second] == -1 || _map[d.first][d.second] >= INF)
		cout << "KAKTUS";
	else cout << _map[d.first][d.second];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
		cin >> str[i];

	solve();

	return 0;
}