#include <iostream>
using namespace std;
// 풀이: https://blog.naver.com/shiftlbns/222192460312
// TODO: graph 로 구현
int get_path(int** mem, int** tab, bool **mark, int i, int j) {
	if (mem[i - 1][j] > mem[i][j]) {
		if (mark[i - 1][j]) tab[i][j] += tab[i - 1][j];
		else tab[i][j] += get_path(mem, tab, mark, i - 1, j);
	}
	if (mem[i][j - 1] > mem[i][j]) {
		if (mark[i][j - 1]) tab[i][j] += tab[i][j - 1];
		else tab[i][j] += get_path(mem, tab, mark, i, j - 1);
	}
	if (mem[i + 1][j] > mem[i][j]) {
		if (mark[i + 1][j]) tab[i][j] += tab[i + 1][j];
		else tab[i][j] += get_path(mem, tab, mark, i + 1, j);
	}
	if (mem[i][j + 1] > mem[i][j]) {
		if (mark[i][j + 1]) tab[i][j] += tab[i][j + 1];
		else tab[i][j] += get_path(mem, tab, mark, i, j + 1);
	}

	mark[i][j] = true;
	return tab[i][j];
}

int main() {
	int n, m;
	int infinite = 100000;
	int** mem, ** tab;
	bool **mark;
	cin >> n >> m;
	mem = new int* [n + 2];
	tab = new int* [n + 2];
	mark = new bool* [n + 2];
	for (int i = 0; i <= n+1; i++) {
		mem[i] = new int[m + 2];
		tab[i] = new int[m + 2];
		mark[i] = new bool[m + 2];
		for (int j = 0; j <= m+1; j++) {
			tab[i][j] = 0;
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
				mem[i][j] = infinite;
				mark[i][j] = true;
			}
			else {
				mark[i][j] = false;
				cin >> mem[i][j];
			}
		}
	}

	tab[1][1] = 1; mark[1][1] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!mark[i][j]) {
				tab[i][j] = get_path(mem, tab, mark, i, j);
			}
		}
	}
	

	cout << tab[n][m];
}