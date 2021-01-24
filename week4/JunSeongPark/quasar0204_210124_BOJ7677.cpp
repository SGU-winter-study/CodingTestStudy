/*
https://www.acmicpc.net/problem/7677

풀이 :
문제에 피보나치에 대한 행렬식이 주어져있으므로 분할정복을 이용해
빠르게 행렬 거듭제곱을 해주면 된다.
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

const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 10000;

const lint MOD = 10000;
typedef vector<vector<lint>> matrix;

matrix operator * (const matrix &a, const matrix &b) {
	lint size = a.size();

	matrix ret(size, vector<lint>(size));
	for (lint i = 0; i < size; i++) {
		for (lint j = 0; j < size; j++) {
			for (lint k = 0; k < size; k++) {
				ret[i][j] += a[i][k] * b[k][j] % MOD;
			}
			ret[i][j] %= MOD;
		}
	}

	return ret;
}

matrix power(matrix a, lint n) {
	lint size = a.size();
	matrix ret(size, vector<lint>(size));
	for (lint i = 0; i < size; i++) {
		ret[i][i] = 1;
	}
	while (n > 0) {
		if (n % 2 == 1) {
			ret = ret * a;
		}
		n /= 2;
		a = a * a;
	}
	return ret;
}

int tc, cnt;
lint n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	matrix m(2, vector<lint>(2));

	m[0][0] = m[0][1] = m[1][0] = 1;

	while (true) {
		cin >> n;
		if (n == -1) break;
		if (n == 0) {
			cout << "0\n";
			continue;
		}

		cout << power(m, n)[0][1] << '\n';

	}



	return 0;
}