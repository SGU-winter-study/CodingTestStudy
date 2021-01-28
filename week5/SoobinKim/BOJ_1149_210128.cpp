#include <iostream>

using namespace std;

int N;
int dp[2][3];

int min2(int a, int b) {
	return a < b ? a : b;
}


int main() {
	int i, r, g, b;
	cin >> N;
	
	for (i = 0; i < N; ++i) {
		cin >> r >> g >> b;
		if (i == 0) {
			dp[1][0] = r;
			dp[1][1] = g;
			dp[1][2] = b;
		}
		else {
			dp[0][0] = dp[1][0];
			dp[0][1] = dp[1][1];
			dp[0][2] = dp[1][2];
			dp[1][0] = min2(dp[0][1], dp[0][2]) + r;
			dp[1][1] = min2(dp[0][0], dp[0][2]) + g;
			dp[1][2] = min2(dp[0][0], dp[0][1]) + b;
		}
	}

	cout << min2(min2(dp[1][0], dp[1][1]), dp[1][2]);

}
