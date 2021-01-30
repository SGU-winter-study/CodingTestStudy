/*
https://www.acmicpc.net/problem/12015

Ǯ�� :
�̺� Ž���� �̿��� lis�� nlogn���� ������ �� �ִ�. (�� ������ �ؾ��Ѵٸ� �� �κ��� ���� �����ؾ���)
�Էµ� ���� ������� ���� ���� �� ���� ũ�� �迭�� ���� �ڿ� �־��ش�.
�ƴϸ� �̺�Ž���� ���� �Էµ� ������ ũ�ų� ���� �� �� ���� ���� ���� �ִ� ��ġ�� �Է����� ��ü���ش�.
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
#include <vector>
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
vector<int> v;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	int num;
	cin >> num;
	v.push_back(num);
	for (int i = 1; i < n; i++) {
		cin >> num;

		if (v.back() < num)
			v.push_back(num);
		else {
			int idx = lower_bound(all(v), num) - v.begin();
			v[idx] = num;
		}
	}

	cout << v.size();


	return 0;
}
