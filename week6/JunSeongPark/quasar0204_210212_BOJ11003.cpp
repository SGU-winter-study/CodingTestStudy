/*
https://www.acmicpc.net/problem/11003

Ǯ�� :
dq�� �̿��ؼ� O(n)�� ���� �� �ִ�.
dq�� �տ� �׻� �ּڰ��� �����ϵ��� �����Ѵ�.
���� ���� �����ʿ� ���� ���Ұ� ���� �ִ� ������ ������
���ʿ� �ִ� ���� �ּҰ��� �� ���ɼ��� �����Ƿ� �����Ѵ�.
���� ���ʿ��� ������ ��� �κ��� �����ϸ� �׻� �ּҰ��� ���� �� �ִ�
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
const int mxn = 10000;

int tc, cnt;
int n, l;
deque<pii> dq;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> l;

	int num;
	for (int i = 1; i <= n; i++) {
		cin >> num;

		while (!dq.empty() && dq.front().second <= i - l) dq.pop_front();
		while (!dq.empty() && num <= dq.back().first) dq.pop_back();

		dq.push_back({ num, i });

		cout << dq.front().first << ' ';
	}




	return 0;
}