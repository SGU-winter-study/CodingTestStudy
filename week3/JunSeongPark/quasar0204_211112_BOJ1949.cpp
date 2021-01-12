/*
https://www.acmicpc.net/problem/1949

풀이 :
트리 dp 현재 node를 선택, 혹은 선택하지 않는 경우로 나눠서 최대값을 구한다.
dp[1][i] -> i node를 선택했을때
dp[0][i] -> i node를 선택하지 않았을때

실제로 문제의 조건 3은 만족하지 않는 경우가 없으므로 1~2만 이용해 풀면 된다.
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
const int mxn = 10101;

int tc, cnt;
int n;

int arr[mxn];
vector<int> adj[mxn];

int dp[2][mxn];

int solve(int root, int pick, int par) {

	int &ret = dp[pick][root];

	if (ret != -1) return ret;

	ret = 0;
	if (pick) {
		ret = arr[root];
		for (int next : adj[root]) {
			if (next == par) continue;
			ret += solve(next, 0, root);
		}
	}
	else {
		for (int next : adj[root]) {
			if (next == par) continue;
			ret += max(solve(next, 0, root), solve(next, 1, root));
		}
	}

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int from, to;
	for (int i = 0; i < n - 1; i++) {
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	fill(dp[0], dp[0] + 2 * mxn, -1);

	cout << max(solve(1, 0, 0), solve(1, 1, 0));


	return 0;
}