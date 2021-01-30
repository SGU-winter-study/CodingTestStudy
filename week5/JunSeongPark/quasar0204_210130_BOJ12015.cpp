/*
https://www.acmicpc.net/problem/12015

풀이 :
이분 탐색을 이용해 lis를 nlogn으로 구현할 수 있다. (값 보존을 해야한다면 그 부분을 따로 구현해야함)
입력된 값이 현재까지 들어온 값들 중 가장 크면 배열의 가장 뒤에 넣어준다.
아니면 이분탐색을 통해 입력된 값보다 크거나 같은 값 중 가장 작은 값이 있는 위치를 입력으로 대체해준다.
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
