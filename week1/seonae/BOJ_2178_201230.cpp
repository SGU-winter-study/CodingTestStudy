// 2178번
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;
char map[102][102];
int visited[102][102];

typedef struct {
	int row;
	int col;
	int distance;
}info;
queue<info> q;

void bfs(int row, int col, int distance);
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	cin >> n >> m;
	char c;
	int input;
	for (int i = 0; i < n; i++) {
			scanf("%s", &map[i]);
	}
	bfs(0, 0,1);
}


void bfs(int row, int col, int distance) {
	int ans = INT_MAX;
	q.push({ row,col,distance });

	while (!q.empty()) {
		
		int r = q.front().row;
		int c = q.front().col;
		int dis = q.front().distance;
		visited[r][c] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) { // 우, 하, 좌, 상 순서로 탐색
			int next_row = r + dy[i];
			int next_col = c + dx[i];
			if (-1 < next_row && next_row < n && -1 < next_col && next_col < m) {
				if (map[next_row][next_col] == '1' && !visited[next_row][next_col]) { // 갈 수 있다면
					visited[next_row][next_col] = 1; // 방문 표시
					q.push({next_row,next_col,dis+1});
				}
			}

			if (next_row == n-1 && next_col == m-1) {
				ans = min(ans,dis+1);
			}
		}
	}
	cout << ans;
}