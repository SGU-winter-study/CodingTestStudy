/*
https://www.acmicpc.net/problem/1289

풀이 :
다이나믹 프로그래밍
현재 노드를 선택하면 자식 노드는 선택할 수 없다
현재 노드를 선택하지 않으면 자식 노드는 선택 or 비선택을 선택할 수 있다
이를 dp를 이용해 저장해주면서 계산한ㄷ.
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
const int mxn = 10101;

int tc, cnt;
int n;

int val[mxn];
vector<int> adj[mxn];
int dp[2][mxn];
vector<int> ans;

int solve(int cur, int par, int pick) {
	int &ret = dp[pick][cur];

	if (ret != -1) return ret;

	ret = 0;
	if (pick) {
		ret = val[cur];
		for (auto next : adj[cur]) {
			if (next == par) continue;
			ret += solve(next, cur, 0);
		}
	}
	else {
		for (auto next : adj[cur]) {
			if (next == par) continue;
			ret += max(solve(next, cur, 0), solve(next, cur, 1));
		}
	}

	return ret;
}

void trace(int cur, int par, int pick) {
	if (pick == 1) {
		ans.push_back(cur);
		for (auto next : adj[cur]) {
			if (next == par) continue;

			trace(next, cur, 0);
		}
	}
	else {
		for (auto next : adj[cur]) {
			if (next == par) continue;

			if (dp[0][next] > dp[1][next])
				trace(next, cur, 0);
			else
				trace(next, cur, 1);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> val[i];

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fill(dp[0], dp[0] + 2 * mxn, -1);

	cout << max(solve(1, 0, 0), solve(1, 0, 1)) << '\n';

	if (max(solve(1, 0, 0), solve(1, 0, 1)) == solve(1, 0, 1))
		trace(1, 0, 1);
	else
		trace(1, 0, 0);

	sort(all(ans));
	for (auto x : ans) cout << x << ' ';

	return 0;
}
