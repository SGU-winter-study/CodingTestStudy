/*
https://www.acmicpc.net/problem/14889

풀이 :
완전 탐색으로 가능한 경우를 모두 찾아줄 수 있음
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
const int mxn = 22;

int tc;
int n;

int ans = INF;
int a[mxn][mxn];
bool check[mxn];

void solve(int idx, int cnt) {
	if (idx == n) return;

	if (cnt == n / 2) {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;

				if (check[i] == false && check[j] == false)
					tmp -= a[i][j];
				if (check[i] == true && check[j] == true)
					tmp += a[i][j];
			}
		}
		ans = min(ans, abs(tmp));
		return;
	}
	
	check[idx] = true; cnt++;
	solve(idx + 1, cnt);
	check[idx] = false; cnt--;
	solve(idx + 1, cnt);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	solve(0, 0);

	cout << ans;

	return 0;
}