/*
https://www.acmicpc.net/problem/17619

풀이 :
y좌표는 신경쓸 필요없이 두 통나무의 x좌표가 겹치면(한 점이라도)
유니온을 이용해 합쳐준다.
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
const int mxn = 101010;

int tc, cnt;
int n, q;

struct node {
	int l, r, i;

	bool operator<(node& rhs) {
		if (l == rhs.l) return r < rhs.r;
		return l < rhs.l;
	}
};

int par[mxn];
node arr[mxn];

int find(int x) {
	if (par[x] == -1) return x;
	return par[x] = find(par[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;

	par[y] = x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> q;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].l >> arr[i].r >> a;
		arr[i].i = i + 1;
	}

	memset(par, -1, sizeof(par));
	sort(arr, arr + n);

	int right = arr[0].r;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i + 1].l <= right) {
			merge(arr[i].i, arr[i + 1].i);
			right = max(right, arr[i + 1].r);
		}
		else {
			right = arr[i + 1].r;
		}
	}

	while (q--) {
		cin >> a >> b;
		if (find(a) == find(b))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}
