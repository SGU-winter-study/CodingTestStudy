/*
https://www.acmicpc.net/problem/20367

풀이 :
3개가 들어가기 전까지는 있는걸 넣어주고 3개가 있는 상황만 생각하면 된다.
이후 어떤것을 빼줄지를 결정해주고 dp를 이용해 풀어주면 됨
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
const int mxn = 3333;

int tc, cnt;
int n;

lint dp[mxn][mxn];
lint arr[mxn];


lint solve(int i, int j) {
	if (i > n) return 0;

	lint &ret = dp[i][j];

	if (ret != -1) return ret;

	ret = 0;

	ret = max(solve(i + 2, j) + arr[i-1] * arr[i], solve(i + 2, i) + arr[i-1] * arr[j]);
	ret = max(ret, solve(i + 2, i - 1) + arr[i] * arr[j]);

	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	memset(dp, -1, sizeof(dp));

	cout << solve(2, 0);

	return 0;
}