/*
https://www.acmicpc.net/problem/14601

풀이 :
분할 정복을 이용해서 해결한다. 4분할을 한 뒤 해당 영역에 배수구가 포함되어 있다면
그 중앙 부분에서 그 부분을 제외하고 색칠해준다 -> check 함수
예를들어 2사분번에 배수구가 포함되어있다면 가운데 합쳐지는 부분은 'ㄴ' 모양으로 칠해야한다.
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
const int mxn = 1000;

int block[4][3][2] = { {{0,0},{0,1},{1,0}}, {{0,0},{0,1},{1,1}}, {{0,1},{1,0},{1,1}}, {{0,0},{1,0},{1,1} } };
int hole[4][2] = { {1,1}, {1,0}, {0,0}, {0,1} };
int tc, cnt;
int n, k;
int Y, X;
int id;
int ans[mxn][mxn];

bool check(int sy, int sx, int l) {
	for (int y = sy; y < sy + l; y++)
		for (int x = sx; x < sx + l; x++)
			if (ans[y][x] != 0) return false;
	return true;
}

void solve(int sy, int sx, int l) {
	id++;
	int nl = l / 2;
	int ny = sy + nl - 1;
	int nx = sx + nl - 1;
	if (check(sy, sx, nl)) ans[ny][nx] = id;
	if (check(ny + 1, sx, nl)) ans[ny + 1][nx] = id;
	if (check(sy, nx + 1, nl)) ans[ny][nx + 1] = id;
	if (check(ny + 1, nx + 1, nl)) ans[ny + 1][nx + 1] = id;

	if (l == 2) return;
	solve(sy, sx, nl);
	solve(ny + 1, sx, nl);
	solve(sy, nx + 1, nl);
	solve(ny + 1, nx + 1, nl);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> k;
	cin >> X >> Y;

	n = 1 << k;
	Y = n + 1 - Y;
	ans[Y][X] = -1;

	solve(1, 1, n);

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cout << ans[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
