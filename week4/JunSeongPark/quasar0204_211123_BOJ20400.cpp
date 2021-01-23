/*
https://www.acmicpc.net/problem/20040

풀이 :
유니온 파인드 자료구조를 이용해서 입력되는 두 정점을 계속 합쳐준다.
만약 같은 유니온에 속한 두 점이 들어올 경우 사이클이 생기므로 종료해준다.
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
const int mxn = 500050;

int tc, cnt;
int n, m;

int par[mxn];

int find(int x) {
	if (par[x] == -1) return x;
	return par[x] = find(par[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return false;

	par[y] = x;
	
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	memset(par, -1, sizeof(par));
	int a, b, ans = 1;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (!merge(a, b)) {
			cout << ans;
			break;
		}
		ans++;
	}

	if (ans > m) cout << 0;



	return 0;
}
