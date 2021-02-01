/*
https://www.acmicpc.net/problem/7575

풀이 :
kmp를 사용해주면 됨
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
const int mxn = 101;

int tc, cnt;
int n, k;

vector<int> v[mxn];

vector<int> makeTable(vector<int>& pattern) {
	vector<int> ret(k, 0);

	int j = 0;
	for (int i = 1; i < k; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = ret[j - 1];
		if (pattern[i] == pattern[j])
			ret[i] = ++j;
	}
	return ret;
}

bool kmp(int idx, vector<int>& pattern) {
	vector<int> table = makeTable(pattern);

	int parentSize = v[idx].size();

	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && v[idx][i] != pattern[j]) {
			j = table[j - 1];
		}
		if (v[idx][i] == pattern[j]) {
			if (j == k - 1) return true;
			else j++;
		}
	}
	return false;
}

bool solve(int sidx, int idx) {
	vector<int> p;
	if (v[0].size() < sidx + k) return false;

	for (int i = sidx; i < sidx + k; i++)
		p.push_back(v[0][i]);

	if (kmp(idx, p)) return true;

	reverse(all(p));

	return kmp(idx, p);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v[i].resize(num);
		for (int j = 0; j < num; j++)
			cin >> v[i][j];
	}


	for (int sidx = 0; sidx < v[0].size(); sidx++) {
		int flag = true;
		for (int i = 1; i < n; i++) {
			if (!solve(sidx, i)) flag = false;
		}
		if (flag) {
			cout << "YES";
			return 0;
		}
	}
	
	cout << "NO";
	return 0;
}
