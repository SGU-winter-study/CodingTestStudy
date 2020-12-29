/*
[문제]
DFS와 BFS 구현
[풀이]
stack와 queue를 이용하여 DFS와 BFS 구현
[TODO]
1. 중복된 코드 정리
*/

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
void showAll(stack<int> s) {
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}
/* implementation with adjacency matrix */
int main() {
	string input;
	int N, M, V; //N: # of vertices, M: # of edges
	int x, y, cur;
	stack<int> dfs_stack;
	queue<int> bfs_queue;
	int** g;
	int* m;

	getline(cin, input);
	stringstream(input) >> N >> M >> V;
	
	m = (int*)malloc(sizeof(int) * (N + 1));
	g = (int**)malloc(sizeof(int*) * (N+1));
	for (int i = 0; i <= N; i++) g[i] = (int*)malloc(sizeof(int) * (N+1));

	// initialize graph
	for (int i = 0; i <= N; i++) {
		m[i] = 0;
		for (int j = 0; j <= N; j++) {
			g[i][j] = 0;
		}
	}

	// mark edges
	for (int i = 0; i < M; i++) {
		getline(cin, input);
		stringstream(input) >> x >> y;
		g[x][y] = g[y][x] = 1;
	}


	// dfs
	cur = V; cout << V; dfs_stack.push(V); m[V] = 1;
	for (int i = 1; i <= N; i++) {
		if (g[cur][i] == 1 && m[i] == 0) {
			cout << ' ' << i;
			m[i] = 1;
			dfs_stack.push(i);
			cur = i;
			i = 0;
			continue;
		}
		else if (i == N) {
			dfs_stack.pop();
			if (dfs_stack.empty()) break;
			cur = dfs_stack.top();
			i = 0;
		}
	}

	// re-initialize
	for (int i = 0; i <= N; i++) m[i] = 0;

	// bfs
	cur = V; cout << "\n" << V; bfs_queue.push(V); m[V] = 1;
	for (int i = 1; i <= N; i++) {
		if (g[cur][i] == 1 && m[i] == 0) {
			cout << ' ' << i;
			m[i] = 1; bfs_queue.push(i);
			if (i == N) {
				bfs_queue.pop();
				if (bfs_queue.empty()) break;
				cur = bfs_queue.front();
				i = 0;
			}
		}
		else if (i == N) {
			bfs_queue.pop();
			if (bfs_queue.empty()) break;
			cur = bfs_queue.front();
			i = 0;
		}
	}

	for (int i = N-1; i >= 0; i--) free(g[i]);
	free(g);
}