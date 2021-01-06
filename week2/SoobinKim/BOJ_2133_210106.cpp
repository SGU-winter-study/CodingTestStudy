#include <iostream>
using namespace std;
int main() {
	int N, i, j;
	int* dp;
	cin >> N;
	dp = new int[N + 1];
	for (i = 0; i <= N; i++) {
		if (i == 0) dp[i] = 1;
		else if (i == 1) dp[i] = 0;
		else if (i == 2) dp[i] = 3;
		else if (i % 2 == 1) dp[i] = 0;
		else {
			dp[i] = dp[i - 2] * 3;
			for (j = 0; j < i - 2; j += 2)
				dp[i] += dp[j] * 2;
		}
	}
	cout << dp[N];
}