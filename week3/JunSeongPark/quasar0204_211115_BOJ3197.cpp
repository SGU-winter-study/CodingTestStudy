/*
https://www.acmicpc.net/problem/3197

풀이 :
BFS로 전처리해 몇번째만에 얼음이 깨지는지 구해둔다
이후 시간에 대한 이분탐색을 이용해서 해결한다.
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
const int mxn = 1505;

int tc, cnt;
int r, c;
vector<pii> bird;

int block[mxn][mxn];
bool visit[mxn][mxn];
string str[mxn];
queue<pii> q;

void init() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dr[i];
			int nx = x + dc[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visit[ny][nx] || str[ny][nx] == '.') continue;

			block[ny][nx] = block[y][x] + 1;
			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
}


bool solve(int time) {

	q.push(bird[0]);

	fill(visit[0], visit[0] + mxn * mxn, false);

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dr[i];
			int nx = x + dc[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visit[ny][nx]) continue;
			if (block[ny][nx] > time) continue;

			if (bird[1].first == ny && bird[1].second == nx) return true;
			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
	return false;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c;

	for (int y = 0; y < r; y++) {
		cin >> str[y];
		for (int x = 0; x < c; x++) {
			if (str[y][x] == '.') {
				visit[y][x] = true;
				q.push({ y,x });
			}
			if (str[y][x] == 'L') {
				visit[y][x] = true;
				q.push({ y,x });
				bird.push_back({ y,x });
				str[y][x] = '.';
			}
		}
	}

	init();

	int l = 0, r = mxn;
	int ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (solve(mid)) {
			ans = mid;
			r = mid - 1;
			q = queue<pii>();
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;
	
	return 0;
}
