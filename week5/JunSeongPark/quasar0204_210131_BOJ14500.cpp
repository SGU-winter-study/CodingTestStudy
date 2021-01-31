/*
https://www.acmicpc.net/problem/14500

풀이 :
완전 탐색..
*/

#include <iostream>
#include <vector>

using namespace std;

int dx[][4] = { {0, 0, 0, 0}, {0, 1, 2, 3}, {0, 0, 1, 1}, {0, 1, 2, 2},
			   {1, 0, 0, 0}, {0, 0, 1, 2}, {1, 1, 1, 0}, {2, 2, 1, 0},
			   {0, 0, 0, 1}, {2, 1, 0, 0}, {0, 1, 1, 1}, {0, 1, 1, 2},
			   {1, 1, 0, 0}, {2, 1, 1, 0}, {0, 0, 1, 1}, {1, 1, 1, 0},
			   {1, 0, 1, 2}, {0, 0, 0, 1}, {0, 1, 2, 1} };

int dy[][4] = { {0, 1, 2, 3}, {0, 0, 0, 0}, {0, 1, 0, 1}, {0, 0, 0, 1},
			   {0, 0, 1, 2}, {0, 1, 1, 1}, {0, 1, 2, 2}, {0, 1, 1, 1},
			   {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 0, 1, 2}, {0, 0, 1, 1},
			   {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 1, 1, 2}, {0, 1, 2, 1},
			   {0, 1, 1, 1}, {0, 1, 2, 1}, {0, 0, 0, 1} };

int N, M;
vector<vector<int> > arr;

int max(int a, int b) {
	return a > b ? a : b;
}

int search(int x, int y) {
	int maxNum = 0;
	for (int i = 0; i < 19; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[i][j];
			int ny = y + dy[i][j];
			
			if (nx < 1 || ny < 1 || nx > N || ny > M)
				break;
			sum += arr[nx][ny];
		}
		maxNum = max(maxNum, sum);
	}
	return maxNum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	arr = vector<vector<int> >(N + 1, vector<int>(M + 1));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	int result = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			result = max(result, search(i, j));

	cout << result;

	return 0;
}