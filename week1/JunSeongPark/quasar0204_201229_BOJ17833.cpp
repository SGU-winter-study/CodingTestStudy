#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
https://www.acmicpc.net/problem/17833

풀이를 들으면 쉬운데 실제 풀이 방법을 찾는 것이 어려운 문제
개인적으로 정말 좋은 문제라고 생각함
풀이를 안보고 풀어보는 것을 추천드립니다

풀이 :
1~H까지의 노드를 만든 다음
정문과 후문의 높이 차만큼 차이나는 노드들을 가중치가 T인 간선으로 이어서
벨만포드로 돌려주면 됨

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
const int mxn = 2001;

int tc, cnt;
int n, r, d, m;

lint adj[mxn][mxn];
lint dist[mxn];

void solve() {
	fill(dist, dist + mxn, LINF);
	priority_queue<pll> pq;
	pq.push({ 0, r });
	dist[r] = 0;

	while (!pq.empty()) {
		lint cur = pq.top().second;
		lint cost = -pq.top().first;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (lint next = 1; next <= n; next++) {
			if (adj[cur][next] == LINF) continue;

			if (dist[next] > cost + adj[cur][next]) {
				dist[next] = cost + adj[cur][next];
				pq.push({ -dist[next], next });
			}
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> r >> d >> m;

	for (int i = 1; i <= n; i++) {
		fill(adj[i], adj[i] + mxn, LINF);
	}

	lint h, t, e1, e2;
	while (m--) {
		cin >> h >> t >> e1 >> e2;
		for (int i = 0; i <= n - h; i++) {
			adj[i + e1][i + e2] = min(adj[i + e1][i + e2], t);
			adj[i + e2][i + e1] = min(adj[i + e2][i + e1], t);
		}
	}

	solve();

	if (dist[d] == LINF) cout << -1;
	else cout << dist[d];
	


	return 0;
}