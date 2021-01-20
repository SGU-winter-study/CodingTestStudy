/*
https://www.acmicpc.net/problem/14908

풀이 :
그리디 알고리즘에 의해 Ti / Si 가 작은것을 먼저 수행하면 됨
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
const int mxn = 1010;

int tc, cnt;
int n;

typedef struct {
	int t, s, i;
} node;

node arr[mxn];

bool cmp(node a, node b) {
	if (a.t * b.s == a.s * b.t)
		return a.i < b.i;
	return a.t * b.s < a.s * b.t;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].t >> arr[i].s;
		arr[i].i = i + 1;
	}
	
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++)
		cout << arr[i].i << ' ';


	return 0;
}
