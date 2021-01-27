/*
https://www.acmicpc.net/problem/13306

Ǯ�� :
�������ٴ� ���̵� ���ø��°� ����� ����� ����
������ �־����� tree���� �ϳ��� �����س����°ǵ� union find���� �̸� �����ϱ� �������
���� �Է��� �ݴ�� ����� �ϳ��� ������ ������ ������ union find�� ���ָ� Ǯ����
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
const int mxn = 202020;

int tc, cnt;
int n, q;

int par[mxn];
int p[mxn];

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

vector<pii> quest;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(par, -1, sizeof(par));
	cin >> n >> q;

	int a, b;
	for (int i = 2; i <= n; i++) {
		cin >> a;
		p[i] = a;
	}

	for (int i = 0; i < n - 1 + q; i++) {
		cin >> a >> b;
		if (a == 0) 
			quest.push_back({ a,b });
		else {
			cin >> a;
			quest.push_back({ a,b });
		}
	}

	vector<string> ans;

	for (int i = n - 2 + q; i >= 0; i--) {
		if (quest[i].first == 0) 
			merge(quest[i].second, p[quest[i].second]);
		else {
			if (find(quest[i].second) == find(quest[i].first))
				ans.push_back("YES\n");
			else
				ans.push_back("NO\n");
		}
	}

	for (int i = q - 1; i >= 0; i--)
		cout << ans[i];

	return 0;
}
