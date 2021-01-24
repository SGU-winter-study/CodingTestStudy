/*
https://www.acmicpc.net/problem/20505

풀이 :
숫자를 a0 a1 a2.... ai .... an이라 할 때
10^r 자리에 ai가 오려면 ai+1 ~ an까지 중 r개를 선택해야한다.
i 이전은 상관없음으로 2^i개를 추가로 뽑을 수있다
따라서 2^i * sigma r = 0 ~ r = n - i - 1 (n-i-1 C r) 을 계산해 다 더하면 됨
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

const int MOD = 998244353, INF = 987654321;
const lint LMOD = 998244353;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 10000;

int tc, cnt;
string str;
int n;

lint mod_pow(lint x, lint n) {
	lint ret = 1;
	while (n > 0) {
		if (n & 1) ret = (ret * x) % LMOD;
		x = (x * x) % LMOD;
		n >>= 1;
	}
	return ret;
}

int solve(int i) {
	lint ret = str[i] - '0';

	ret = (ret * mod_pow(2, i)) % LMOD;
	ret = (ret * mod_pow(11, n - i - 1)) % LMOD;

	return (int)ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> str;
	n = str.size();

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + solve(i)) % MOD;

	cout << ans;

	return 0;
}