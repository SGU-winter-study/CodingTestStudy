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
	int n, result = 0;
	int *mem, *tab;

	cin >> n;
	mem = new int[n + 1];
	tab = new int[n + 1];
	mem[0] = 0;	tab[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> mem[i];
	}
	for (int j = 1; j <= n; j++) {
		if (j < 3)
			tab[j] = tab[j - 1] + mem[j];
		else {
			tab[j] = max3(tab[j - 1],
				tab[j - 2] + mem[j],
				tab[j - 3] + mem[j] + mem[j - 1]);
		}
	}
	cout << tab[n];
}
