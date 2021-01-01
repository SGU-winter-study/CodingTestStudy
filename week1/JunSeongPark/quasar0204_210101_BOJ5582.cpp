/*
https://www.acmicpc.net/problem/5582

풀이 : 다이나믹 프로그래밍
dp[0 ~ idx1 - 1][0 ~ idx2 - 1] 선언 후
str1[idx1] == str2[idx2] 면 이전 매칭값 + 1
아니면 0
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
const int mxn = 4001;

int tc, cnt;
int n;
string a, b;

int dp[mxn][mxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> a >> b;
	int ans = -1;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (i == 0) 
				dp[i][j] = (int)(a[i] == b[j]);
			else if (j == 0) 
				dp[i][j] = (int)(a[i] == b[j]);
			else {
				if (a[i] == b[j]) 
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else 
					dp[i][j] = 0;
				
			}
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;

	return 0;
}