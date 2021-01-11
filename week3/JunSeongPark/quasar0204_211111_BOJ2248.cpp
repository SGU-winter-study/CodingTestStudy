/*
https://www.acmicpc.net/problem/2248

풀이 :
n자리수에서 1을 m개 이하로 사용해서 만들 수 있는 수의 개수를 dp[n][m]으로 놓을 때
dp[n][m] = dp[n-1][m] + dp[n-1][m-1]이 성립함
이를 이용해서 구해준 후 자리수를 기준으로 dp[n][m]보다 i가 크다면
1을 아니면 0을 앞에 추가하는 형식으로 역추적해 답을 구할 수 있다.
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
const int mxn = 33;

string ans;
lint dp[mxn][mxn];

lint solve(int n, int m) {
	
	if (n == 0 || m == 0) return 1LL;

	lint &ret = dp[n][m];

	if (ret != -1LL) return ret;

	return ret = solve(n - 1, m) + solve(n - 1, m - 1);
}

void trace(int n, int m, lint i) {
	if (n == 0) return;

	if (m == 0) {
		for (int i = 0; i < n; i++)
			ans += "0";
		return;
	}

	lint tmp = solve(n - 1, m);

	if (tmp >= i) {
		ans += "0";
		trace(n - 1, m, i);
	}
	else {
		ans += "1";
		trace(n - 1, m - 1, i - tmp);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	lint i;
	cin >> n >> m >> i;

	fill(dp[0], dp[0] + mxn * mxn, -1);

	trace(n, m, i);
	cout << ans;

	return 0;
}