/*
https://www.acmicpc.net/problem/15686

풀이 : 완전탐색

치킨집 수가 최대 13개이므로 2^13 완전탐색으로 풀 수 있음
visit을 이용해서 선택된 조합 표시했음
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
const int mxn = 10000;

int n, m;

pii h[100];
pii c[13];
int d[1 << 13][100];

int ans = INF;
int hn, cn;


int dist(pii p1, pii p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void solve(int visit, int idx, int cnt) {
	if (cnt == m) {
		fill(d[visit], d[visit] + 100, INF);
		for (int i = 0; i < hn; i++) {
			for (int v = 0; v < cn; v++) {
				if (visit & (1 << v)) {
					d[visit][i] = min(d[visit][i], dist(h[i], c[v]));
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < hn; i++) {
			sum += d[visit][i];
		}
		ans = min(ans, sum);
		return;
	}

	if (idx == cn)
		return;

	solve(visit, idx + 1, cnt);
	solve(visit | (1 << idx), idx + 1, cnt + 1);
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int num;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> num;
			if (num == 1) 
				h[hn++] = { y,x };
			else if (num == 2) 
				c[cn++] = { y,x };
		}
	}

	solve(0, 0, 0);
	cout << ans;



	return 0;
}