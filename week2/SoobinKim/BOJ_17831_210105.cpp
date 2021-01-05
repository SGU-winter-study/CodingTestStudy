#include <iostream>
#include <vector>

#define MENTOR 0
#define MENTEE 1
#define NEITHER 2

using namespace std;

vector<int>* tree;
int* synergy;
int** dp;

int max2(int a, int b) {
	return a > b ? a : b;
}

int max3(int a, int b, int c) {
	if (a > b) return max2(a, c);
	else return max2(b, c);
}

void add_edge(int u, int v) {
	tree[u].push_back(v);
	//tree[v].push_back(u);
}

int go(int now, int state) {
	int i, next, tmp, selected = 0, max = -1;
	if (dp[now][state] != -1) return dp[now][state];

	dp[now][state] = 0;

	if (state == MENTOR) {
		for (i = 0; i < tree[now].size(); i++) {
			next = tree[now][i];
			dp[now][state] += max2(go(next, MENTOR), go(next, NEITHER));
		}

		// find mentee
		for (i = 0; i < tree[now].size(); i++) {
			next = tree[now][i];
			tmp = synergy[now] * synergy[next] + go(next, MENTEE) - max2(dp[next][MENTOR], dp[next][NEITHER]);
			if (max < tmp) {
				max = tmp;
				selected = next;
			}
		}
		// add synergy
		if (!tree[now].empty())
			dp[now][state] += (synergy[now] * synergy[selected] \
				- max2(dp[selected][MENTOR], dp[selected][NEITHER]) + dp[selected][MENTEE]);

	}
	else if (state == MENTEE) {
		for (i = 0; i < tree[now].size(); i++) {
			next = tree[now][i];
			dp[now][state] += max2(go(next, MENTOR), go(next, NEITHER));
		}
	}
	else if (state == NEITHER) {
		for (i = 0; i < tree[now].size(); i++) {
			next = tree[now][i];
			dp[now][state] += max2(go(next, MENTOR), go(next, NEITHER));
		}
	}

	return dp[now][state];
}

int main() {
	int n, u, i;
	cin >> n;

	tree = new vector<int>[n + 1];
	synergy = new int[n + 1];
	dp = new int* [n + 1];
	for (i = 0; i <= n; i++) {
		dp[i] = new int[3];
		dp[i][0] = dp[i][1] = dp[i][2] = -1;
	}

	for (i = 2; i <= n; i++) {
		cin >> u;
		add_edge(u, i); // add only child node
	}

	for (i = 1; i <= n; i++) {
		cin >> synergy[i];
	}

	for (i = 1; i <= n; i++) {
		if (tree[i].empty()) {
			dp[i][MENTOR] = -10;
			dp[i][MENTEE] = 0;
			dp[i][NEITHER] = 0;
		}
	}

	cout << max2(go(1, MENTOR), go(1, NEITHER));
}