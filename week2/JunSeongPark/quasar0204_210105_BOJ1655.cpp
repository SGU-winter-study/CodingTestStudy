/*
https://www.acmicpc.net/problem/1655

풀이 :
min heap 과 max heap 2개를 이용해서 반씩 나눠서 항상 max heap의 top에 중간값이 존재하도록 구현한다.
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
int n;
priority_queue<int> M;
priority_queue<int, vector<int>, greater<int>> m;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;

		if (M.empty()) M.push(cur);
		else if (m.empty()) {
			if (cur < M.top()) {
				m.push(M.top());
				M.pop();
				M.push(cur);
			}
			else
				m.push(cur);
		}
		else {
			if (cur <= M.top()) M.push(cur);
			else m.push(cur);

			while (M.size() < m.size()) {
				M.push(m.top());
				m.pop();
			}

			while (!(M.size() == m.size() || M.size() == m.size() + 1)) {
				m.push(M.top());
				M.pop();
			}

		}

		cout << M.top() << '\n';
	}


	return 0;
}