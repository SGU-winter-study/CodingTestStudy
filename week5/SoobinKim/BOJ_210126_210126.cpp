#include <iostream>
#include <vector>

using namespace std;

int N;

int min2(int a, int b) {
	return a < b ? a : b;
}

int min3(int a, int b, int c) {
	if (a < b)
		return min2(a, c);
	else
		return min2(b, c);
}

int max2(int a, int b) {
	return a > b ? a : b;
}

int max3(int a, int b, int c) {
	if (a < b)
		return max2(b, c);
	else
		return max2(a, c);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, a, b, c;
	int max_board[2][3], min_board[2][3];

	cin >> N;
	// init
	max_board[1][0] = max_board[1][1] = max_board[1][2] = 0;
	min_board[1][0] = min_board[1][1] = min_board[1][2] = 0;

	for (i = 0; i < N; ++i) {
		cin >> a >> b >> c;
		max_board[0][0] = max_board[1][0];
		max_board[0][1] = max_board[1][1];
		max_board[0][2] = max_board[1][2];
		
		max_board[1][0] = max2(max_board[0][0], max_board[0][1]) + a;
		max_board[1][1] = max3(max_board[0][0], max_board[0][1], max_board[0][2]) + b;
		max_board[1][2] = max2(max_board[0][1], max_board[0][2]) + c;

		min_board[0][0] = min_board[1][0];
		min_board[0][1] = min_board[1][1];
		min_board[0][2] = min_board[1][2];

		min_board[1][0] = min2(min_board[0][0], min_board[0][1]) + a;
		min_board[1][1] = min3(min_board[0][0], min_board[0][1], min_board[0][2]) + b;
		min_board[1][2] = min2(min_board[0][1], min_board[0][2]) + c;
	}

	cout << max3(max_board[1][0], max_board[1][1], max_board[1][2]) << " " << min3(min_board[1][0], min_board[1][1], min_board[1][2]);
}
