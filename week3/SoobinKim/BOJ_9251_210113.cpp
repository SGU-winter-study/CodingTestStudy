#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string A, B;
int** dp;

int max(int a, int b) {
	return a > b ? a : b;
}

int go(int a, int b) {
	if (dp[a][b] != -1) return dp[a][b];
	dp[a][b] = 0;

	if (A[a] == B[b])
		dp[a][b] = go(a - 1, b - 1) + 1;
	else {
		dp[a][b] = max(go(a - 1, b), go(a, b - 1));
	}
	return dp[a][b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, len_a, len_b;

	cin >> A;
	cin >> B;
	len_a = A.length(); len_b = B.length();
	dp = new int*[len_a];
	for (i = 0; i < len_a; i++) {
		dp[i] = new int[len_b];
		fill(dp[i], dp[i] + len_b, -1);
	}

	// initialize
	if (A[0] == B[0]) dp[0][0] = 1;
	else dp[0][0] = 0;

	for (i = 1; i < len_a; i++) {
		dp[i][0] = dp[i - 1][0];

		if (B[0] == A[i]) {
			dp[i][0] = 1;
		}
	}

	for (i = 1; i < len_b; i++) {
		dp[0][i] = dp[0][i - 1];

		if (A[0] == B[i]) {
			dp[0][i] = 1;
		}
	}

	go(len_a - 1, len_b - 1);
	cout << dp[len_a - 1][len_b - 1];
}
