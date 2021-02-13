/*
https://www.acmicpc.net/problem/1562

비트 마스킹을 활용해 dp 테이블을 채운다
비트 패턴을 이용해 0 ~ 9를 사용했는지 확인하는데 사용하면서
dp를 풀어주면 된다.
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

const int MOD = 1000000000, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 111;

int tc, cnt;
int n;

lint dp[111][11][1<<11];

lint solve(int idx, int last, int visit) {
	if (last < 0 || last > 9) return 0;

	if (idx == 1) {
		if ((visit | (1 << last)) == ((1 << 10) - 1))
			return 1;
		return 0;
	}

	lint &ret = dp[idx][last][visit];

	if (ret != -1) return ret;

	visit = visit | (1 << last);

	return ret = (solve(idx - 1, last - 1, visit) + solve(idx - 1, last + 1, visit)) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	memset(dp, -1, sizeof(dp));


	int ans = 0;

	for (int i = 1; i < 10; i++) {
		ans += solve(n, i, 0);
		ans %= MOD;
	}

	cout << ans;


	return 0;
}
