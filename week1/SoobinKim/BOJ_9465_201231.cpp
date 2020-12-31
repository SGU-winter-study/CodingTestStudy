#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int max3(int a, int b, int c) {
	if (a > b) {
		return max(a, c);
	}
	else return max(b, c);
}

int main() {
	int n, m, x, result = 0;
	int (*mem)[2], (*tab)[3];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		mem = new int[m][2];
		tab = new int[m][3];
		for (int j = 0; j < m; j++) {
			cin >> mem[j][0];
		}
		for (int j = 0; j < m; j++) {
			cin >> mem[j][1];
		}
		// initialize
		tab[0][0] = mem[0][0];
		tab[0][1] = mem[0][1];
		tab[0][2] = 0;


		for (int j = 1; j < m; j++) {
			tab[j][0] = max(tab[j - 1][1], tab[j - 1][2]) + mem[j][0];
			tab[j][1] = max(tab[j - 1][0], tab[j - 1][2]) + mem[j][1];
			tab[j][2] = max(tab[j - 1][0], tab[j - 1][1]);
		}

		cout << max3(tab[m-1][0], tab[m-1][1], tab[m-1][2]) << endl;
	}
}
