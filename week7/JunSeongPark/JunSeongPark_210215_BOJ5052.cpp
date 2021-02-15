/*
https://www.acmicpc.net/problem/5052

Ǯ�� :
Ʈ���� ������ ����
Ʈ������ ���Ḧ �˸��� ����� �ڽ� ��尡 ������ �ȵȴ�.

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
const int mxn = 10000;

int tc, cnt;
int n;

const int chd_mxn = 10;

struct trie {
	trie* chd[chd_mxn];

	bool output;		//	���⼭ ������ ���ڰ� ������ true
	bool have_chd;	//	�ڽ��� �ִ°�

	trie() {
		fill(chd, chd + chd_mxn, nullptr);
		output = have_chd = false;
	}

	~trie() {
		for (int i = 0; i < chd_mxn; i++)
			if (chd[i]) delete chd[i];
	}

	void insert(const string& key, int idx) {

		if (idx == key.size()) output = true;

		else {
			int next = key[idx] - '0';

			if (!chd[next]) chd[next] = new trie;

			have_chd = true;

			chd[next]->insert(key, idx + 1);
		}
	}

	bool consistent() {
		if (have_chd && output) return false;

		for (int i = 0; i < chd_mxn; i++)
			if (chd[i] && !chd[i]->consistent()) return false;

		return true;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> tc;

	while (tc--) {
		cin >> n;

		trie *root = new trie;

		for (int i = 0; i < n; i++) {
			string tel;

			cin >> tel;

			root->insert(tel, 0);
		}

		cout << (root->consistent() ? "YES" : "NO") << '\n'; 

		delete root;
	}


	return 0;
}
