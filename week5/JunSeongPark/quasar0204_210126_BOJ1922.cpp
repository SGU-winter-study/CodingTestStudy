/*
https://www.acmicpc.net/problem/4792

풀이 :
최소 스패닝 트리를 구하면 됨
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

int tc, cnt;
int n, m;

struct node {
	int v1, v2, cost;

	bool operator<(const node& rhs) const {
		return cost > rhs.cost;
	}
};

priority_queue<node> pq;
int par[mxn];

int find(int x) {
	if (par[x] == -1) return x;
	return par[x] = find(par[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return false;

	par[y] = x;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	memset(par, -1, sizeof(par));

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq.push({ a,b,c });
	}

	int ans = 0;
	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();
		if (merge(cur.v1, cur.v2)) 
			ans += cur.cost;
		
	}
	
	cout << ans;

	return 0;
}
