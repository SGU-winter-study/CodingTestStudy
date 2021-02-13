/*
https://www.acmicpc.net/problem/2098

풀이 :
bitmask를 이용한 dp
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
const int mxn = 16;

int tc, cnt;
int n;

int cost[mxn][mxn];
int dp[mxn][1 << mxn];

int tsp(int cur, int visited) {
	int &ret = dp[cur][visited];

	if (ret != -1) return ret;

	if (visited == ((1 << n) - 1)) {
		return cost[cur][0];
	}

	ret = INF;
	for (int i = 0; i < n; i++) {
		if ((visited & (1 << i)) || cost[cur][i] == INF)
			continue;
		ret = min(ret, tsp(i, visited | (1 << i)) + cost[cur][i]);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> cost[y][x];
			if (cost[y][x] == 0) cost[y][x] = INF;
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << tsp(0, 1);


	return 0;
}
