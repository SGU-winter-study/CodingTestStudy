/*
https://www.acmicpc.net/problem/2180

풀이 :
그리디 알고리즘을 이용해 aj*bi < ai*bj 로 정렬해준후 순서대로 끄면 된다.
a == b == 0 인 상황을 주의하자
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
const int mxn = 10000;

int tc, cnt;
int n;

vector<pii> v;

bool cmp(pii a, pii b) {
	return a.second * b.first < a.first * b.second;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == 0 && b == 0) continue;
		v.push_back({ a,b });
	}

	sort(all(v), cmp);

	lint ans = 0;
	for (auto x : v) {
		ans = (ans + ans * x.first + x.second) % 40000LL;
	}

	cout << ans;

	return 0;
}
