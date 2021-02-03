/*
https://www.acmicpc.net/problem/3830

풀이 :
유니온 파인드 과정에서 무게에 대한 정보를 추가적으로 저장해준다.
같은 유니온이 아니면 무게 계산이 불가능하다.
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
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const int mxn = 101010;

int tc, cnt;
int n, m;

int par[mxn];
lint w[mxn];

int find(int x) {
	if (par[x] == -1) return x;

	int parent = find(par[x]);
	w[x] += w[par[x]];
	return par[x] = parent;
}

bool isSame(int x, int y) {
	return find(x) == find(y);
}

bool merge(int x, int y, int we) {
	int py = find(y);
	int px = find(x);

	if (py == px) return false;

	w[py] = w[x] - w[y] + we;
	par[py] = px;
	return true;
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	char ch;
	int a, b, c;

	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0) break;
		memset(par, -1, sizeof(par));
		memset(w, 0, sizeof(w));
		while (m--) {
			cin >> ch;
			if (ch == '!') {
				cin >> a >> b >> c;
				merge(a, b, c);
			}
			else if (ch == '?') {
				cin >> a >> b;
				if (isSame(a, b))
					cout << w[b] - w[a] << '\n';
				else
					cout << "UNKNOWN\n";
			}
			else
				break;
		}
	}


	return 0;
}
