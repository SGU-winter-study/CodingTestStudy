/*
[TODO]
1. 그래프 linked list로 구현
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void init(bool** g, bool* m, int size) {
	for (int i = 0; i < size; i++) {
		m[i] = false;
		for (int j = 0; j < size; j++) {
			g[i][j] = false;
		}
	}
}

int dfs(bool** g, bool* m, int cur, int lv, int size) {
	m[cur] = true;
	lv++;
	for (int i = 0; i < size; i++) {
		if (g[cur][i] && !m[i]) {
			lv = dfs(g, m, i, lv, size);
		}
	}
	return lv;
}

void main() {
	int N, M, a, b, cur;
	string input;
	bool** g;
	bool* m;
	vector<int> s;

	getline(cin, input);
	stringstream(input) >> N >> M;

	m = (bool*)malloc(sizeof(bool) * N);
	g = (bool**)malloc(sizeof(bool*) * N);
	for (int i = 0; i < N; i++) g[i] = (bool*)malloc(sizeof(bool) * N);


	// initialize
	init(g, m, N);

	for (int i = 0; i < M; i++) {
		getline(cin, input);
		stringstream(input) >> a >> b;
		g[a][b] = g[b][a] = true;
	}

	// dfs
	for (int i = 0; i < N; i++) {
		if (dfs(g, m, i, 0, N) >= 5) {
			cout << 1;
			return;
		}
		init(g, m, N);
	}
	cout << 0;
}
