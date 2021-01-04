/*
https://www.acmicpc.net/problem/7453

풀이 :
a b c d를 두개씩 묶는다.
배열에 a + b를 저장하고 정렬한 뒤 -(c + d)를 이분탐색으로 찾는다.
map을 사용해서 풀면 시간초과가 난다 둘 다 시간 복잡도는 O(N^2logN)이지만
map 컨테이너 자체가 느린것 같다.
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
const int mxn = 4000;

lint tc, cnt;
int n;

int a[mxn], b[mxn], c[mxn], d[mxn];
vector<int> ab;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(a[i] + b[j]);
		}
	}

	sort(all(ab));
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cur = - c[i] - d[j];
			auto x = lower_bound(all(ab), cur);
			if (x != ab.end() && *x == cur) {
				auto u = upper_bound(all(ab), cur);
				ans += u - x;

			}
		}
	}


	cout << ans;


	return 0;
}