/*
https://www.acmicpc.net/problem/14501

풀이 :
dp를 이용해서 계산할 수 있음
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

int tc, cnt;
int n;
int dp[22];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	int t, p;
	for (int i = 1; i <= n; i++) {
		cin >> t >> p;

		dp[i] = max(dp[i], dp[i - 1]);
		dp[i + t - 1] = max(dp[i + t - 1], dp[i - 1] + p);
	}

	cout << dp[n];


	return 0;
}